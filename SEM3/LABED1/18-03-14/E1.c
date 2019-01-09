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

pilha *pilhaRemove(pilha *topo) {
    pilha *aux = topo;
    topo = topo->prox;
    free(aux);
    return(topo);
}

int pilhaMaiorElemento(pilha *topo) {
    int maior = -1;
    while(topo != NULL) {
        if(topo->num > maior) maior = topo->num;
    }
    return(maior);
}

pilha *pilhaLimpa(pilha *topo) {
    pilha *aux = topo;
    while(aux != NULL) {
        topo = topo->prox;
        free(aux);
        aux = topo;
    }
    return(aux);
}

void main() {
    pilha *topo = NULL;
    int opcao, valor;
    while(opcao != 5) {
        printf("Programa de pilha\n\n");
        printf("Escolha uma das opcoes:\n");
        printf("1 - Inserir novo elemento(valor inteiro)\n");
        printf("2 - Remover elemento\n");
        printf("3 - Mostrar maior elemento\n");
        printf("4 - Esvaziar pilha\n");
        printf("5 - Sair\n\n");
        printf("> ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("\nInsira o valor do novo elemento(valor inteiro): ");
                scanf("%d", &valor);
                topo = pilhaInsere(topo, valor);
                printf("\nValor Inserido com sucesso!\n\n");
                break;
            case 2:
                topo = pilhaRemove(topo);
                printf("\nElemento removido com sucesso!\n\n");
                break;
            case 3:
                printf("\nO maior elemento e: %d\n\n", pilhaMaiorElemento(topo));
                break;
            case 4:
                topo = pilhaLimpa(topo);
                printf("\nPilha esvaziada com sucesso!\n\n");
                break;
            case 5: break;
            default:
                printf("\nOpcao invalida!\n\n");
        }
    }
}