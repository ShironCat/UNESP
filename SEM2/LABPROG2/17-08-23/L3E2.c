//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 23/08/17
//Lista: 3, Número do exercício: 2

#include <stdio.h>

int contador(int *n, float *x, int *a) {
    int i, resultado = 0;
    for(i = 0; i < *a; i++) if(*n == *(x + i)) resultado++;
    return resultado;
}

void main() {
    int i, n, a;
    float x[100];
    printf("Insira um tamanho para o vetor: ");
    scanf("%d", &a);
    printf("Insira os valores do vetor: ");
    for(i = 0; i < a; i++) scanf("%f", &x[i]);
    printf("Insira o numero que sera contado no vetor: ");
    scanf("%d", &n);
    printf("O numero %d aparece %d vezes no vetor\n", n, contador(&n, x));
}