#include <stdio.h>

void main() {
    int i = 5, *p;
    p = &i;
    printf("%p %d %d %d %d\n", p, (*p + 2), **&p, (3 * *p), (**&p + 4));
}