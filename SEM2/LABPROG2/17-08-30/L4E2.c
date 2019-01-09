/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 2
*/

#include <stdio.h>

int soma(int i, int n) {
    if(n > 1) {
        return i * i + soma(i, (n - 1));
    } else {
        return i * i;
    }
}

void main() {
    int i, n;
    printf("Insira os valores de i e n para calcular a somatoria: ");
    scanf("%d %d", &i, &n);
    printf("O resultado da somatoria e: %d\n", soma(i, n));
}