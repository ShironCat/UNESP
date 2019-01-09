/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 11, Exercício: 2
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

lista *move_inicio(lista *l, int a) {
    lista *p = l, *aux, *antigo;
    aux = (lista*)malloc(sizeof(lista));
    while(p->prox != NULL && p->prox->info != a) p = p->prox;
    if(p->prox != NULL) {
        antigo = p->prox;
        aux->info = antigo->info;
        p->prox = antigo->prox;
        aux->prox = l;
        free(antigo);
        return aux;
    } else {
        return l;
    }
}

void main() {}