#include <stdio.h>

void main() {
    int i = 10, j = 2, *p, *q;
    p = &i; //printf("%p\n", p);
    q = &j; //printf("%X\n", *q);
    // p = &*&i; printf("%p\n", p);
    // i = (*&)j; printf("%d\n", i);
    // i = *&j; printf("%d\n", i);
    // i = *&*&j; printf("%d\n", i);
    // q = *p; printf("%p\n", q);
    i = (*p++) + *q; printf("%d\n", i);
}