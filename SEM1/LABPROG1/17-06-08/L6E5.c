#include "stdio.h"

void main() {
    int v[10], x, a = 2, i = 0;
    printf("Insira um vetor de 10 elementos:\n");
    for(x = 0; x < 10; x++) {
        scanf("%d", &v[x]);
    }
    do {
        if(v[i] > v[(i + 1)]) {
            if(a == 1) {
                a = 0;
            } else {
                a = -1;
            }
        } else if(v[i] < v[(i + 1)]) {
            if(a == -1) {
                a = 0;
            } else {
                a = 1;
            }
        }
        i++;
    } while(i <= 9 && a != 0);
    if(a == 1) {
        printf("Crescente!\n");
    } else if(a == -1) {
        printf("Decrescente!\n");
    } else {
        printf("Desordenada!\n");
    }
}