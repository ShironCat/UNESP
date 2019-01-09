/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 7
*/

#include <stdio.h>

int fatorialDuplo(int n) {
    if((n % 2)) {
        if(n > 1) {
            return n * fatorialDuplo((n - 2));
        } else {
            return n;
        }
    } else {
        if(n > 2) {
            return n * fatorialDuplo((n - 2));
        } else {
            return n;
        }
    }
}

void main() {
    int n;
    printf("Insira um numero para ser calculado o seu fatorial duplo: ");
    scanf("%d", &n);
    printf("O fatorial duplo de %d e: %d\n", n, fatorialDuplo(n));
}