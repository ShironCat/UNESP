/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 06/09/17
    Lista 5, Exercício: 2
*/

#include <stdio.h>
#include <string.h>

void ordenar(int n, char nome[][100]) {
    int trocado, i;
    char aux[100];
    do {
        trocado = 0;
        for(i = 0; i < (n - 1); i++) {
            if(strcmp(nome[i], nome[i + 1]) > 0) {
                strcpy(aux, nome[i]);
                strcpy(nome[i], nome[i + 1]);
                strcpy(nome[i + 1], aux);
                trocado = 1;
            }
        }
    } while(trocado == 1);
}

void main() {
    int n, i;
    char nome[100][100];
    printf("Insira quantos nomes devem ser lidos: ");
    scanf("%d", &n);
    printf("Insira os nomes que devem ser ordenados:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", nome[i]);
    }
    ordenar(n, nome);
    for(i = 0; i < n; i++) {
        printf("%s\n", nome[i]);
    }
}