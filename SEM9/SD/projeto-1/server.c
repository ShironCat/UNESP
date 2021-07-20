#include <math.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

int main(int argc, const char **argv)
{
    // Checking parameters are set
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <NUMBER OF CLIENTS> <PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Socket related variables
    int number_clients = atoi(argv[1]), server_fd, client_socket[number_clients];
    uint16_t port = atoi(argv[2]);
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[50];

    printf("Monte Carlo Server\n");

    // Creating socket file descriptor
    printf("Creating socket file descriptor... ");
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("\nIn socket");
        exit(EXIT_FAILURE);
    }
    printf("OK\n");

    // Setting address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    // Binding socket to address
    printf("Binding socket to local address (port: %hu)... ", port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("\nIn bind");
        exit(EXIT_FAILURE);
    }
    printf("OK\n");

    // Setting socket to listen for connections
    printf("Setting socket to listen for connections... ");
    if (listen(server_fd, 20) < 0)
    {
        perror("\nIn listen");
        exit(EXIT_FAILURE);
    }
    printf("OK\n");

    // Waiting for clients connections
    printf("Expecting %d clients\n", number_clients);
    for (int i = 0; i < number_clients; i++)
    {
        printf("Waiting for client[%d]... ", (i + 1));
        if ((client_socket[i] = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }
        printf("OK\n");
    }

    // Setting up accumulator for each run
    double accumulator[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    // Start timestamp
    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);

    // Calculating PI with different number of dots
    for (int i = 3; i <= 10; i++)
    {
        double work = pow(10, i) / number_clients;

        // Sending work to clients
        for (int j = 0; j < number_clients; j++)
        {
            memset(buffer, '\0', sizeof buffer);
            if (j % 2)
                snprintf(buffer, sizeof buffer, "%lf", ceil(work));
            else
                snprintf(buffer, sizeof buffer, "%lf", floor(work));
            ssize_t valsend;
            do
            {
                valsend = send(client_socket[j], buffer, strlen(buffer), 0);
            } while (valsend < 0);
        }

        int wg = number_clients;

        // Waiting for all clients to send their finished work
        do
        {
            memset(buffer, '\0', sizeof buffer);
            for (int j = 0; j < number_clients; j++)
            {
                ssize_t valrecv = recv(client_socket[j], buffer, sizeof buffer, 0);
                if (valrecv > 0)
                {
                    accumulator[i - 3] += atof(buffer);
                    wg--;
                }
            }
        } while (wg);

        accumulator[i - 3] /= number_clients;
    }

    // End timestamp
    struct timespec end;
    clock_gettime(CLOCK_REALTIME, &end);

    printf("Values of PI:\n");

    printf("Number of dots\tValue of PI\n");
    for (int i = 3; i <= 10; i++)
        printf("[%lf]\t%lf\n", pow(10, i), accumulator[i - 3]);

    printf("Calculated in %ld.%ld seconds\n", end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);

    // Sending closing signal to clients
    for (int i = 0; i < number_clients; i++)
    {
        memset(buffer, '\0', sizeof buffer);
        ssize_t valsend;
        do
        {
            valsend = send(client_socket[i], buffer, strlen(buffer), 0);
        } while (valsend < 0);
    }

    // Closing all sockets
    for (int i = 0; i < number_clients; i++)
        close(client_socket[i]);
    close(server_fd);

    return 0;
}