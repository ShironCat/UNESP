//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 16/08/17
//Lista: 2, Exercicio: 3

#include <stdio.h>

int primo(int m) {
    int i, teste = 1;
    for(i = 2; i < m && teste; i++) {
        if(!(m%i)) teste--;
    }
    return teste;
}

void main() {
    int n, soma = 0, nsoma = 0, i;
    do {
        printf("Insira um numero inteiro nao negativo: ");
        scanf("%d", &n);
    } while(n < 0);
    for(i = 2; nsoma < n; i++) {
        if(primo(i)) {
            soma += i;
            nsoma++;
        }
    }
    printf("Resultado: %d\n", soma);
}