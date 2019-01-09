/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 06/09/17
    Lista 5, Exercício: 1
*/

#include <stdio.h>
#include <string.h>

void permutacao(char *str) {
    int tamanho = strlen(str), i, j;
    for(i = 0; i < tamanho; i++) {
        for(j = tamanho; j > 0; j--) {
            *(str + j) = *(str + j - 1);
        }
        *(str + 0) = *(str + tamanho);
        *(str + tamanho) = '\0';
        printf("%s\n", str);
    }
}

void main() {
    char str[100];
    printf("Insira uma palavra para ser permutada:\n");
    scanf("%s", str);
    permutacao(str);
}