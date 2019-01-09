/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 6
*/

#include <stdio.h>

int produto(int m, int n) {
    if(n > m) {
        return m * produto((m + 1), n);
    } else {
        return n;
    }
}

void main() {
    int m, n;
    printf("Insira dois numeros inteiros m e n: ");
    scanf("%d %d", &m, &n);
    printf("O produto de todos os numeros no intervalo [%d, %d] e: %d\n", m, n, produto(m, n));
}