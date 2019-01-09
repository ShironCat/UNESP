#include <stdio.h>

void main() {
    int i = 3, j = 6, *p, *q;
    p = &i;
    q = &j;
    printf("%d\n", (p == &i));
    printf("%d\n", (*p - *q));
    printf("%d\n", **&p);
    printf("%.1f\n", (3 * -(float)*p / (*q) + 7));
}