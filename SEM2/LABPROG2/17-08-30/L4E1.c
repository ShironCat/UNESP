/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 1
*/

#include <stdio.h>

int ContaDigitos(int n) {
    if(n >= 10) {
        return 1 + ContaDigitos((int)(n / 10));
    } else {
        return 1;
    }
}

void main() {
    int n, i;
    printf("Insira um numero: ");
    scanf("%d", &n);
    printf("Esse numero possui %d digitos\n", ContaDigitos(n));
}