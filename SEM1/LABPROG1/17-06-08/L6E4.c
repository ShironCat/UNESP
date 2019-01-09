#include "stdio.h"

void main() {
    int m1[3][3], m2[3], m3[3], x, y, a = 0;
    printf("Insira a primeira matriz:\n");
    for(x = 0; x <= 2; x++) {
        for(y = 0; y <= 2; y++) {
            scanf("%d", &m1[x][y]);
        }
    }
    printf("Insira a segunda matriz:\n");
    for(x = 0; x <= 2; x++) {
        scanf("%d", &m2[x]);
    }
    for(x = 0; x <= 2; x++) {
        a = 0;
        for(y = 0; y <= 2; y++) {
            a += m1[x][y] * m2[x];
        }
        m3[x] = a;
    }
    printf("Resultado:\n");
    for(x = 0; x<= 2; x++) {
        printf("%d ", m3[x]);
    }
    printf("\n");
}