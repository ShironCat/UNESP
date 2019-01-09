/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 10, Exercício: 2
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *prox;
} lista;

void insere_inicio(lista *l, int elem) {
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->info = elem;
    novo->prox = l -> prox;
    l->prox = novo;
}

void imprime_lista(lista *l) {
    while(l->prox != NULL) {
        l = l->prox;
        printf("%d ", l->info);
    }
}

void main() {
    int a;
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    l->info = 0;
    l->prox = NULL;
    do {
        printf("Insira o proximo valor da lista(parar = -1): ");
        scanf("%d", &a);
        if(a != -1) insere_inicio(l, a);
    } while(a != -1);
    printf("\n");
    imprime_lista(l);
    printf("\n");
}