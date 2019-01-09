#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int num;
    struct elemento *prox;
} pilha;

pilha *pilhaInsere(pilha *topo, int num) {
    pilha *novo = (pilha*)malloc(sizeof(pilha));
    novo->num = num;
    novo->prox = topo;
    topo = novo;
    return(topo);
}

int pilhaCompara(pilha *topo1, pilha *topo2) {
    while(topo1 != NULL || topo2 != NULL) {
        if(topo1->num == topo2->num) {
            topo1 = topo1->prox;
            topo2 = topo2->prox;
        } else {
            return(0);
        }
    }
    return(1);
}

void main() {
    pilha *topo1 = NULL, *topo2 = NULL;
    int i, num;
    printf("Insira os 5 numeros da primeira pilha: ");
    for(i = 0; i < 5; i++) scanf("%d", &num), topo1 = pilhaInsere(topo1, num);
    printf("Insira os 5 numeros da segunda pilha: ");
    for(i = 0; i < 5; i++) scanf("%d", &num), topo2 = pilhaInsere(topo2, num);
    (pilhaCompara(topo1, topo2)) ? printf("As pilhas sao iguais!\n") : printf("As pilhas sao diferentes!\n");
}