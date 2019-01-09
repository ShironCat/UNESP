//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 16/08/17
//Lista: 2, Exercicio: 4

#include <stdio.h>

int mdc(int a, int b) {
    int aux;
    if(b > a) {
        aux = a;
        a = b;
        b = aux;
    }
    if(!(a%b)) {
        return b;
    } else {
        return mdc(b, (a%b));
    }
}

void main() {
    int n, numeros[100], resultado, i;
    printf("Insira um numero inteiro positivo de quantos numeros deseja calcular MDC(maximo 100): ");
    scanf("%d", &n);
    printf("Insira os numeros inteiros nao negativos que serao usados para calcular MDC: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }
    resultado = mdc(numeros[0], numeros[1]);
    for(i = 2; i < n; i++) {
        resultado = mdc(resultado, numeros[i]);
    }
    printf("MDC: %d\n", resultado);
}