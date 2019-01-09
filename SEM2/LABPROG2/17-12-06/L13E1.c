/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 06/12/17
    Lista 13, Exercício: 1
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int info;
	struct node *ant;
	struct node *prox;
} lista;

lista *buscaListaDuplaCircularCabecalho(lista *l, int a) {
	lista *h = l;
	while(l->prox != h)	{
		l = l->prox;
		if(l->info == a) return l;
	}
	return NULL;
}

int insereInicioListaDuplaCircularCabecalho(lista *l, int a) {
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo->info = a;
	novo->prox = l->prox;
	novo->ant = l;
	l->prox = novo;
	if(l->ant = l) l->ant = novo;
	return 1;
}

int  insereFimListaDuplaCircularCabecalho(lista *l, int a) {
	lista *novo;
	novo = (lista*)malloc(sizeof(lista));
	novo->info = a;
	novo->ant = l->ant;
	novo->prox = l;
	l->ant = novo;
	if(l->prox = l) l->prox = novo;
	return 1;
}

int removeListaDuplaCircularCabecalho(lista *l, int a) {
	lista *antigo, *anterior, *proximo;
	antigo = buscaListaDuplaCircularCabecalho(l, a);
	if(antigo != NULL) {
		anterior = antigo->ant;
		proximo = antigo->prox;
		anterior->prox = proximo;
		proximo->ant = anterior;
		free(antigo);
		return 1;
	}
	return 0;
}

void imprimeListaDuplaCircularCabecalho(lista *l) {
	lista *aux = l;
	while(l->prox != aux) {
		l = l->prox;
		printf("%d ", l->info);
	}
}

void main() {
	int op = -1, a;
	lista *l;
	l = (lista*)malloc(sizeof(lista));
	l->prox = l;
	l->ant = l;
	while(op != 0) {
		system("clear");
		printf("Lista Duplamente Encadeada com Cabecalho\n");
		printf("Estado atual da lista:\n");
		imprimeListaDuplaCircularCabecalho(l);
		printf("\n\n");
		printf("Escolha uma das acoes abaixo:\n");
		printf("1 - Inserir valor no inicio da lista\n");
		printf("2 - Inserir valor no fim da lista\n");
		printf("3 - Remover valor da lista\n");
		printf("0 - SAIR\n");
		printf("> ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("Insira o valor que sera inserido no inicio da lista:\n");
				printf("> ");
				scanf("%d", &a);
				(insereInicioListaDuplaCircularCabecalho(l, a)) ? (printf("Operacao realizada com sucesso!")) : (printf("ERRO"));
				break;
			case 2:
				printf("Insira o valor que sera inserido no fim da lista:\n");
				printf("> ");
				scanf("%d", &a);
				(insereFimListaDuplaCircularCabecalho(l, a)) ? (printf("Operacao realizada com sucesso!")) : (printf("ERRO"));
				break;
			case 3:
				printf("Insira o valor que sera removido da lista:\n");
				printf("> ");
				scanf("%d", &a);
				(removeListaDuplaCircularCabecalho(l, a)) ? (printf("Operacao realizada com sucesso!")) : (printf("Item nao encontrado na lista"));
				break;
			default:
				op = 0;
		}
	}
	system("clear");
}