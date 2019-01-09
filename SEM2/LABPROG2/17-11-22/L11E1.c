/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 11, Exercício: 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

void busca_insere(lista *l, int a) {
    while(l->prox != NULL && a < l->prox->info) l = l->prox;
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->info = a;
    novo->prox = l->prox;
    l->prox = novo;
}

int busca_remove(lista *l, int a) {
    while(l->prox != NULL && a < l->prox->info) l = l->prox;
    if(l->prox != NULL) {
        lista *antigo;
        antigo = (lista*)malloc(sizeof(lista));
        antigo = l->prox;
        l->prox = antigo->prox;
        free(antigo);
        return 1;
    } else {
        return 0;
    }
}