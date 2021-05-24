#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char **argv)
{
    // Start timestamp
    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);

    // Calculating amount of work
    double work;
    for (double i = 3; i <= 10; i++)
        work = pow(10, i);

    // Executing "Monte Carlo" method
    long long int dots_inside_circle = 0;
    srand(time(NULL));
    for (int i = 0; i < work; i++)
    {
        double x = (double)rand() / RAND_MAX * 2 - 1, y = (double)rand() / RAND_MAX * 2 - 1;
        if (sqrt(pow(x, 2) + pow(y, 2)) <= 1)
            dots_inside_circle++;
    }

    double pi = 4 * (dots_inside_circle / work);

    // End timestamp
    struct timespec end;
    clock_gettime(CLOCK_REALTIME, &end);

    printf("Value of PI: %lf\n", pi);
    printf("Calculated in %lf milliseconds\n",
           (double)(end.tv_sec - start.tv_sec) * 1000.0 + (double)(end.tv_nsec - start.tv_nsec) * 0.000001);
    return 0;
}