/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 06/12/17
    Lista 13, Exercício: 2
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

// int contarListaCircularCabecalho(lista *l, lista *p) {
// 	if(p == NULL) p = l;
// 	if(l->prox == p) {
// 		return 0;
// 	} else {
// 		return contarListaCircularCabecalho(l->prox, p) + 1;
// 	}
// }

int contarListaCircularCabecalho(lista *l) {
    int i;
    lista *p = l;
    for(i = 0; l->prox != p; i++) l = l->prox;
    return i;
}

void main() {}