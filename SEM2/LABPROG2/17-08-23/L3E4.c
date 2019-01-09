//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 23/08/17
//Lista: 3, Número do exercício: 4

#include <stdio.h>

void soma(int (*a)[100], int (*b)[100], int (*c)[100], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void main() {
    int a[100][100], b[100][100], c[100][100], n, m, i, j;
    printf("Insira o tamanho das matrizes a e b: ");
    scanf("%d %d", &n, &m);
    printf("Insira os valores da matriz a:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Insira os valores da matriz b:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    soma(a, b, c, n, m);
    printf("Resultado da matriz c:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}