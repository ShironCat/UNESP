/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 4
*/

#include <stdio.h>

int somaDigitos(int n) {
    if(n > 10) {
        return (n%10) + somaDigitos((int)(n / 10));
    } else {
        return n;
    }
}

void main() {
    int n;
    printf("Insira um numero: ");
    scanf("%d", &n);
    printf("A soma dos digitos de %d e: %d\n", n, somaDigitos(n));
}