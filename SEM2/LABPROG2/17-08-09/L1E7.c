#include <stdio.h>

void p1() {
    int vet[] = {4, 9, 13}, i;
    for(i = 0; i < 3; i++) printf("%d\n", *(vet + i));
}

void p2() {
    int vet[] = {4, 9, 13}, i;
    for(i = 0; i < 3; i++) printf("%p\n", (vet + i));
}

void main() {
    int a;
    scanf("%d", &a);
    (a) ? p1() : p2();
}