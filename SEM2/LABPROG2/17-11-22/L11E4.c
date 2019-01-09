/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 11, Exercício: 4
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

void concatena_lista(lista *l, lista *p) {
    lista *aux = l;
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = p;
}

void main() {}