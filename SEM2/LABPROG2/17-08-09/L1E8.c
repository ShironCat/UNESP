#include <stdio.h>

void p1() {
    int vet[] = {4, 9, 12}, i, *ptr;
    ptr = vet;
    for(i = 0; i < 3; i++) printf("%d\n", *ptr++);
}

void p2() {
    int vet[] = {4, 9, 12}, i, *ptr;
    ptr = vet;
    for(i = 0; i < 3; i++) printf("%d\n", (*ptr)++);
}

void main() {
    int a;
    scanf("%d", &a);
    (a) ? p1() : p2();
}