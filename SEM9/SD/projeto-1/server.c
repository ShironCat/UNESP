#include <math.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, const char **argv)
{
    // Checking parameters are set
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <NUMBER OF CLIENTS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Socket related variables
    int number_clients = atoi(argv[1]), server_fd, client_socket[number_clients];
    struct sockaddr_in address;
    int addrlen = sizeof(address);

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
    address.sin_port = htons(PORT);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    // Binding socket to address
    printf("Binding socket to address... ");
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
    printf("Expeting %d clients\n", number_clients);
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

    // Start timestamp
    time_t start = time(NULL);

    // Calculating amount of work
    double work;
    for (double i = 3; i <= 10; i++)
        work = pow(10, i);

    work /= number_clients;

    // Sending work to clients
    for (int i = 0; i < number_clients; i++)
    {
        char buffer[20];
        if (i % 2 == 0)
        {
            snprintf(buffer, 20, "%f", floor(work));
            write(client_socket[i], buffer, strlen(buffer));
        }
        else
        {
            snprintf(buffer, 20, "%f", ceil(work));
            write(client_socket[i], buffer, strlen(buffer));
        }
    }

    int wg = number_clients;
    double accumulator = 0;

    // Waiting for all clients to send their finished work
    do
    {
        char buffer[20];
        memset(buffer, '\0', 20);
        for (int i = 0; i < number_clients; i++)
        {
            ssize_t valread = read(client_socket[i], buffer, 20);
            if (valread > 0)
            {
                accumulator += atof(buffer);
                wg--;
            }
        }
    } while (wg);

    // Calculate final approximation of PI
    double pi = accumulator / number_clients;

    // End timestamp
    time_t end = time(NULL);

    printf("Value of PI: %lf\n", pi);
    printf("Calculated in %d seconds\n", end - start);

    // Closing all sockets
    for (int i = 0; i < number_clients; i++)
        close(client_socket[i]);
    close(server_fd);

    return 0;
}