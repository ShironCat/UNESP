/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 11, Exercício: 6
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

lista *remove_repetido(lista *l) {
    lista *p = l;
    while(l->prox != NULL) {
        if(l->prox->info == l->info) {
            lista *aux;
            aux = l->prox;
            l->prox = aux->prox;
            free(aux);
        } else {
            l = l->prox;
        }
    }
    return p;
}

void main() {}