/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 30/08/17
    Lista 4, Exercício: 5
*/

#include <stdio.h>

int conversao(int n) {
    if((n / 2) != 0) {
        return n % 2 + conversao((n / 2)) * 10;
    } else {
        return (n % 2);
    }
}

float calculo(float n) {
    if(n > 1) {
        return (n * n + 1) / (n + 3) + calculo((n - 1));
    } else {
        return (2.0 / 4.0);
    }
}

void main() {
    float n;
    int op;
    printf("Insira um numero n: ");
    scanf("%f", &n);
    printf("Escolha qual funcao voce deseja utiizar:\n1) Conversao de um numero natural em base binaria\n0) Calculo de (n^2+1)/(n+3)\n> ");
    scanf("%d", &op);
    printf("Resultado: ");
    (op) ? printf("%d", conversao((int)n)) : printf("%f", calculo(n));
    printf("\n");
}