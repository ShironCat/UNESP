/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 29/11/17
    Lista 12, Exercício: 2
*/

#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

lista *lista_interseccao(lista *l, lista *p) {
    lista *q;
    while(l != NULL && p != NULL) {
        if(l->info == p->info) {
            
        }
    }
}

void main() {}