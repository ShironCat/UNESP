//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 16/08/17
//Lista: 2, Exercicio: 2

#include <stdio.h>

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    return a / b;
}

void main() {
    int num1, num2, op;
    printf("Insira dois numeros para efetuar uma operacao: ");
    scanf("%d %d", &num1, &num2);
    printf("Escolha qual operacao voce quer efetuar:\n1) Soma\n2) Subtracao\n3) Multiplicacao\n4) Divisao\n> ");
    scanf("%d", &op);
    printf("Resultado: ");
    if(op == 1) {
        printf("%d\n", soma(num1, num2));
    } else if(op == 2) {
        printf("%d\n", subtracao(num1, num2));
    } else if(op == 3) {
        printf("%.0f\n", multiplicacao(num1, num2));
    } else if (op == 4) {
        printf("%.2f\n", divisao(num1, num2));
    }
}