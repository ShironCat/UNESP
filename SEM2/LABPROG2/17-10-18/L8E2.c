/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 18/10/17
    Lista 8, Exercício: 2
*/

#include <stdio.h>

int buscaBinaria(int v[], int n, int x) {
    int i = 0, j = (n - 1), k;
    while (i <= j) {
       k = (i + j) / 2;
       if (v[k] == x) return k;
       if (v[k] < x) i = k + 1;
       else j = k - 1;
    }
    return -1;
}

void main() {
    int n, i, v[100], x;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Insira o vetor ordenado: ");
    for(i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("Insira o valor de X: ");
    scanf("%d", &x);
    printf("Resultado da busca: %d\n", buscaBinaria(v, n, x));
}