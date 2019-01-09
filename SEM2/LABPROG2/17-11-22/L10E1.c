/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 22/11/17
    Lista 10, Exercício: 1
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *prox;
} lista;

lista *insere_inicio(lista *l, int elem) {
    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->prox = l;
    novo->info = elem;
    return novo;
}

void imprime_lista(lista *l) {
    int a;
    do {
        a = 0;
        printf("%d ", l->info);
        if(l->prox != NULL) l = l->prox, a++;
    } while(a);
}

void main() {
    int a;
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    l->prox = NULL;
    printf("Insira o primeiro valor da lista: ");
    scanf("%d", &l->info);
    do {
        printf("Insira o proximo valor da lista(parar = -1): ");
        scanf("%d", &a);
        if(a != -1) l = insere_inicio(l, a);
    } while(a != -1);
    printf("\n");
    imprime_lista(l);
    printf("\n");
}