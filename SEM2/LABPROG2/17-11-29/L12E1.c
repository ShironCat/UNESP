/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 29/11/17
    Lista 12, Exercício: 1
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

int lista_igual(lista *l, lista *p) {
    while(l != NULL && p != NULL) {
        if(l->info == p->info) {
            if(l->prox == NULL && p->prox == NULL) {
                return 1;
            } else {
                l = l->prox;
                p = p->prox;
            }
        } else {
            return 0;
        }
    }
    return 0;
}

void main() {}