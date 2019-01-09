/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 11, Exercício: 3
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

int conta_lista(lista *l) {
    if(l->prox == NULL) {
        return 1;
    } else {
        return conta_lista(l->prox) + 1;
    }
}

void main() {}