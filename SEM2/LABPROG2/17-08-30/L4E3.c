/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 3
*/

#include <stdio.h>

int soma(int n) {
    if(n > 1) {
        return n + soma((n - 1));
    } else {
        return 1;
    }
}

void main() {
    int n;
    printf("Insira um numero: ");
    scanf("%d", &n);
    printf("O soma de todos os numeros de 1 ate o numero n e: %d\n", soma(n));
}