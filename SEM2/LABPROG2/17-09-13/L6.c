/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 13/09/17
    Lista 6
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void leitura(char lista[][100]) {
    int i = 0, op;
    do {
        printf("Insira um nome(maximo de 100 caracteres): ");
        fgets(lista[i++], 100, stdin);
        printf("Deseja ler outro nome?\n1_) Sim\n0_) Nao\n> ");
        scanf("%d", &op);
    } while(op);
}

void remover(char *string, int pos, int n) {
    int i;
    for(i = 0; i < n; i++) {
        *(string + pos++) = ' ';
    }
}

int buscar(char *texto, char *palavra, int *ocorrencia) {
    int i, j, k = 0, l = 0;
    for(i = 0; i < strlen(texto); i++) {
        if((int)toupper(*(texto + i)) == (int)toupper(*(palavra + 0))) {
            for(j = 0; j < strlen(palavra) && (int)toupper(*(texto + i++)) == (int)toupper(*(palavra + j)); j++) {
                ((int)toupper(*(texto + i++)) == (int)toupper(*(palavra + j))) ? (k = 1) : (k = 0);
            }
        }
        if(k) {
            *(ocorrencia + l++) = i - strlen(palavra);
            k = 0;
        }
    }
    return l;
}

void limpar(char *texto) {
    int i = 0, j = 0;
    do {
        if((int)*(texto + i) == (int)' ') {
            while((int)*(texto + ++i) == (int)' ');
            while((int)*(texto + i++) != (int)' ') strcpy((texto + j++), (texto + i++));
            *(texto + j++) = ' ';
        }
    } while(i < strlen(texto));
}