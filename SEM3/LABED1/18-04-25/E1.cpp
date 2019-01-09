#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int num;
    struct ELEMENTO *prox, *ant;
} Lista;

Lista *insereLista(Lista *lista, int opcao, int num) {
    Lista *novo = new Lista();
    novo->num = num;
    if(inicio == NULL) {
        novo->prox = novo->ant = novo;
    } else if(opcao == 1) {
        novo->prox = lista;
        novo->ant = lista->ant;
        lista->ant->prox = novo;
        lista->ant = novo;
    } else if(opcao == 2) {
        novo->ant = lista;
        novo->prox = lista->prox;
        lista->prox->ant = novo;
        lista->prox = novo;
    }
    return lista = novo;
}

void consultaListaInicio(Lista *inicio, Lista *fim) {
    if(inicio == NULL) {
        cout << "Lista vazia!\n";
    } else {
        cout << inicio->num << "\n";
        while(inicio != fim) {
            inicio = inicio->prox;
            cout << inicio->num << "\n";
        }
    }
}

void consultaListaFim(Lista *inicio, Lista *fim) {
    if(fim == NULL) {
        cout << "Lista vazia!\n";
    } else {
        cout << fim->num << "\n";
        while(fim != inicio) {
            fim = fim->ant;
            cout << fim->num << "\n";
        }
    }
}

Lista *removeLista(Lista *inicio, Lista *fim, int num) {
    Lista *aux;
    if(inicio == NULL) {
        cout << "Lista vazia!\n";
    } else if(inicio == fim) {
        aux = inicio;
        inicio = NULL;
        delete(aux);
    } else {
        while(inicio != fim) {
            if(inicio->num == num) {
                aux = inicio;
                inicio = inicio->prox;
                delete(aux);
            } else {
                inicio = inicio->prox;
            }
        }
        do {
            if(inicio->num = num) {
                aux = inicio;
                
            }
        }
    }
    return inicio;
}

void main() {
    int opcao;
    Lista *inicio = NULL, *fim = NULL;
    do {
        cout << "Insira uma opção:\n";
        cout << "1 - Inserir inicio\n";
        cout << "2 - Inserir fim\n";
        cout << "3 - Consultar a partir do início\n";
        cout << "4 - Consultar a partir do fim\n";
        cout << "5 - Remover\n";
        cout << "6 - Esvaziar a lista\n";
        cout << "0 - Sair\n";
        cout << "\n> ";
        cin >> opcao;
    }
}