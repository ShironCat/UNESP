#include "stdio.h"
#include "string.h"

void main() {
    int l, i;
    char w1[10], w2[10], w3[10];
    printf("Insira a primeira palavra: ");
    fgets(w1, 10, stdin);
    printf("Insira a segunda palavra: ");
    fgets(w2, 10, stdin);
    printf("Insira a terceira palavra: ");
    fgets(w3, 10, stdin);
    l = strlen(w1) - 2;
    for(i = l; i >= 0; i--) {
        printf("%c", w1[i]);
    }
    l = strlen(w2);
    for(i = l; i >= 0; i--) {
        printf("%c", w2[i]);
    }
    l = strlen(w3);
    for(i = l; i >= 0; i--) {
        printf("%c", w3[i]);
    }
    printf("\n");
}