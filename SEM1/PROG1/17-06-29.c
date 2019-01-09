#include <stdio.h>

void atribuicao() {
    int i, j, a[50][60];
    char tabela[6][5];
    //gerar a matriz 'a'
    for(i = 0; i < 50; i++) {
        for(j = o; j < 60; j++) {
            a[i][j] = 0;
        }
    }

    //inicializar a tabela com brancos
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 5; j++){
            tabela[i][j] = '';
        }
    }
}

void leitura() {
    int i, j, a[50][60];
    //leitura da matriz 'a'
    for(i = 0; i < 50; i++) {
        for(j = 0; j < 60; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void escrita() {
    int i, j, a[50][60];
    //escrevendo a matriz 'a', no formato de
    //matriz, ou seja, mudando-se de linha a
    //cada nova linha da matriz
    for(i = 0; i < 50; i++) {
        for(j = 0; j < 60; j++) printf("%6d", a[i][j]);
        printf("\n");
    }
}

void exercicio_1() {
    //Dado duas matrizes A e B de dimensões MxN,
    //Calcular e escrever a matriz soma S.
    float a[50][50], b[50][50], s[50][50];
    int m, n, i, j;
    printf("Forneca as dimensoes MxN das matrizes(maximo 50x50)");
    scanf("%dx%d", &m, &n);
    printf("Forneca a matriz A");
    for(i = 0; i < m, i++) for(j = 0; j < n; j++) scanf("%f", &a[i][j]);
    printf("Forneca a matriz B\n");
    for(i = 0; i < m; i++) for(j = 0; j < n; j++) scanf("%f", &b[i][j]);

    //Calcular a matriz soma S
    printf("matriz soma\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            s[i][j] = a[i][j] + b[i][j];
            printf("%6.2f", s[i][j]);
        }
        printf("\n");
    }
}

void exercicio_2() {
    int I[50][50], i, j, N;
    printf
}

void main() {
    int op;
    printf("1 - Atribuição\n2 - Leitura\n3 - Escrita\n4 - Exercicio 1\n5 - Exercicio 2\n");
    scanf("%d", &op);
    switch(op) {
        case 1: atribuicao(); break;
        case 2: leitura(); break;
        case 3: escrita(); break;
        case 4: exercicio_1(); break;
        case 5: exercicio_2(); break;
    }
}