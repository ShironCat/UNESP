/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 18/10/17
    Lista 8, Exercício: 1
*/

#include <stdio.h>

int buscaSequencial(int v[], int t, int x) {
    int i;
    for(i = 0; i < t; i++) if(v[i] == x) return i;
    return -1;
}

void main() {
    int t, i, v[100], x;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &t);
    printf("Insira o vetor: ");
    for(i = 0; i < t; i++) {
        scanf("%d", &v[i]);
    }
    printf("Insira um elemento X: ");
    scanf("%d", &x);
    printf("Resultado da busca: %d\n", buscaSequencial(v, t, x));
}