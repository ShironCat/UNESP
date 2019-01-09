#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO {
    char nome[256];
    int idade;
    int numeroMatricula;
    char sexo;
    struct ELEMENTO *proximo;
    struct ELEMENTO *anterior;
} lista;

int checaMatricula(lista *tabela, int numeroMatricula) {
    while(tabela != NULL && tabela->numeroMatricula != numeroMatricula) tabela = tabela->proximo;
    if(tabela == NULL) {
        return 1;
    } else {
        return 0;
    }
}

lista *inserirLista(lista *tabela, char nome[256], int idade, int numeroMatricula, char sexo) {
    int i;
    lista *novo = (lista*)malloc(sizeof(lista)), *inicio = tabela;
    for(i = 0; i < 256; i++) novo->nome[i] = nome[i];
    novo->idade = idade;
    novo->numeroMatricula = numeroMatricula;
    novo->sexo = sexo;
    novo->proximo = NULL;
    if(tabela == NULL) {
        novo->anterior = NULL;
        inicio = novo;
    } else {
        while(tabela->proximo != NULL) tabela = tabela->proximo;
        novo->anterior = tabela;
        tabela->proximo = novo;
    }
    return inicio;
}

lista *removerLista(lista *tabela, int numeroMatricula) {
    lista *auxiliar = tabela;
    while(auxiliar != NULL && auxiliar->numeroMatricula != numeroMatricula) auxiliar = auxiliar->proximo;
    if(auxiliar != NULL) {
        if(auxiliar->anterior == NULL) {
            tabela = tabela->proximo;
            if(tabela != NULL) tabela->anterior = NULL;
        } else if(auxiliar->proximo == NULL) {
            auxiliar->anterior->proximo = NULL;
        } else {
            auxiliar->anterior->proximo = auxiliar->proximo;
            auxiliar->proximo->anterior = auxiliar->anterior;
        }
    }
    free(auxiliar);
    return tabela;
}

void exibirLista(lista *tabela) {
    while(tabela != NULL) {
        printf("Matricula: %d - Nome: %s  Idade: %d  Sexo: %c\n", tabela->numeroMatricula, tabela->nome, tabela->idade, tabela->sexo);
        tabela = tabela->proximo;
    }
}

void main() {
    int i, n, opcao, idade, numeroMatricula, hash, checaMatriculaResultado;
    char nome[256], sexo;
    printf("Insira o valor de N: ");
    scanf("%d", &n);
    lista *tabela[n];
    for(i = 0; i < n; i++) {
        tabela[i] = (lista*)malloc(sizeof(lista));
        tabela[i] = NULL;
    }
    do {
        printf("\nEscolha uma opcao\n");
        printf("1 - Inserir um registro\n");
        printf("2 - Remover um registro\n");
        printf("3 - Exibir a tabela\n");
        printf("0 - Sair\n");
        printf("> ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Insira o nome: ");
                getchar();
                scanf("%[^\n]", nome);
                printf("Insira a idade: ");
                scanf("%d", &idade);
                do {
                    printf("Insira o numero de matricula: ");
                    scanf("%d", &numeroMatricula);
                    hash = numeroMatricula % n;
                    checaMatriculaResultado = checaMatricula(tabela[hash], numeroMatricula);
                    if(!checaMatriculaResultado) printf("Numero de matricula ja cadastrado!\n");
                } while(!checaMatriculaResultado);
                getchar();
                printf("Insira o sexo(f/m): ");
                scanf("%c", &sexo);
                tabela[hash] = inserirLista(tabela[hash], nome, idade, numeroMatricula, sexo);
                break;
            case 2:
                printf("Insira o numero de matricula do elemento a ser removido: ");
                scanf("%d", &numeroMatricula);
                hash = numeroMatricula % n;
                tabela[hash] = removerLista(tabela[hash], numeroMatricula);
                break;
            case 3:
                printf("\nTabela de Hash:\n");
                for(i = 0; i < n; i++) {
                    printf("Hash %d\n", i);
                    exibirLista(tabela[i]);
                    printf("\n");
                }
                break;
            case 0: break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}