//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 16/08/17
//Lista: 2, Exercicio: 1

#include <stdio.h>

int soma(int a) {
    if(a > 1) {
        return a + soma(a - 1);
    } else {
        return a;
    }
}

void main() {
    int numero;
    printf("Insira um numero inteiro positivo para ser somado: ");
    scanf("%d", &numero);
    printf("%d\n", soma(numero));
}