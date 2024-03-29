#include <arpa/inet.h>
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
        fprintf(stderr, "Usage: %s <CLIENT ID> <PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Socket related variables
    int client_fd;
    uint16_t port = atoi(argv[2]);
    struct sockaddr_in address;
    char buffer[50];

    printf("Monte Carlo CLient\n");

    // Creating socket file descriptor
    printf("Creating socket file descriptor... ");
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("\nIn socket");
        exit(EXIT_FAILURE);
    }
    printf("OK\n");

    // Setting address struct
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) < 0)
    {
        perror("\nIn address conversion");
        exit(EXIT_FAILURE);
    }

    // Connecting to server
    printf("Connecting to server (port: %hu)... ", port);
    while (connect(client_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        perror("\nIn connect");
    printf("OK\n");

    double work;
    do
    {
        // Waiting for work
        memset(buffer, '\0', sizeof buffer);
        ssize_t valrecv;
        do
        {
            valrecv = recv(client_fd, buffer, sizeof buffer, 0);
        } while (valrecv < 0);

        work = atof(buffer);

        if (!work)
            continue;

        // Executing "Monte Carlo" method
        long long int dots_inside_circle = 0;
        srand(time(NULL) * atoi(argv[1]));
        for (long long int i = 0; i < work; i++)
        {
            double x = (double)rand() / RAND_MAX * 2 - 1, y = (double)rand() / RAND_MAX * 2 - 1;
            if (x * x + y * y <= 1)
                dots_inside_circle++;
        }

        double pi = 4 * (dots_inside_circle / work);

        // Sending value of pi
        memset(buffer, '\0', sizeof buffer);
        snprintf(buffer, sizeof buffer, "%lf", pi);
        ssize_t valsend;
        do
        {
            valsend = send(client_fd, buffer, sizeof buffer, 0) < 0;
        } while (valsend < 0);

        printf("Value of PI: %lf\n", pi);
    } while (work);

    // Closing socket
    close(client_fd);

    return 0;
}
