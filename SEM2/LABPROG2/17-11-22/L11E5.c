/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 11, Exercício: 5
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

lista *intercala_lista(lista *l, lista *p) {
    if(l->prox == NULL) {
        return p;
    } else if(p->prox == NULL) {
        return l;
    } else {
        lista *r, *s, *aux;
        r = (lista*)malloc(sizeof(lista));
        s = r;
        while(l->prox != NULL || p->prox != NULL) {
            if(p->prox != NULL) {
                aux = p->prox;
                p->prox = aux->prox;
            }
        }
        return s;
    }
}

void main() {}