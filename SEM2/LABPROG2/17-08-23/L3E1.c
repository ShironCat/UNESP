//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 23/08/17
//Lista: 3, Número do exercício: 1

#include <stdio.h>

void operacao(int *a, int *b, char *c) {
    if(*c == '+') {
        *a += *b;
    } else if(*c == '-') {
        *a -= *b;
    } else if(*c == '*') {
        *a *= *b;
    } else if(*c == '/') {
        *a /= *b;
    }
}

void main() {
    int a, b;
    char c;
    printf("Insira dois numeros e um operador: ");
    scanf("%d %d %c", &a, &b, &c);
    operacao(&a, &b, &c);
    printf("Resultado: %d\n", a);
}