#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int valor;
    struct ELEMENTO *proximo;
} lista;

lista *listaAdicionaInicio(lista *inicio, int valor) {
    lista *novo = new lista();
    novo->valor = valor;
    novo->proximo = inicio;
    inicio = novo;
    return inicio;
}

lista *listaAdicionaFim(lista *fim, int valor) {
    lista *novo = new lista();
    novo->valor = valor;
    novo->proximo = NULL;
    fim->proximo = novo;
    fim = novo;
    return fim;
}

void listaExibe(lista *inicio, lista *fim) {
    if(inicio == NULL) {
        cout << "\nLista vazia";
    } else {
        cout << "\nLista: " << inicio->valor;
        while(inicio != fim) {
            inicio = inicio->proximo;
            cout << ", " << inicio->valor;
        }
    }
    cout << "\n";
}

int listaConta(lista *inicio, lista *fim) {
    if(inicio == NULL) {
        return 0;
    } else {
        int i = 1;
        while(inicio != fim) {
            i++;
            inicio = inicio->proximo;
        }
        return i;
    }
}

int listaChecaCrescente(lista *inicio, lista *fim) {
    if(inicio == NULL) {
        return 1;
    } else {
        int i = 1;
        while(i != 0 && inicio != fim) {
            if(inicio->valor > inicio->proximo->valor) {
                i = 0;
            } else {
                inicio = inicio->proximo;
            }
        }
        return i;
    }
}

int listaChecaAltura(lista *inicio, lista *fim, int valor) {
    if(inicio == NULL) {
        return 0;
    } else {
        int i = 1, id = 0;
        do {
            if(inicio->valor == valor) id = i;
        } while(inicio != fim);
        if(id != 0) {
            return listaConta(inicio, fim);
        } else {
            return 0;
        }
    }
}

int listaChecaProfundidade() {}

int main() {
    int opcao = 1, valor;
    lista *inicio = NULL, *fim = NULL;
    while(opcao != 0) {
        cout << "\nEscolha uma opcao:\n\n";
        cout << "1 - Adicionar um valor ao inicio da lista\n";
        cout << "2 - Adicionar um valor ao fim da lista\n";
        cout << "3 - Contar quantos elementos existem na lista\n";
        cout << "4 - Verificar se a lista e crescente\n";
        cout << "0 - Sair\n\n";
        cout << "> ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "\nInsira o valor a ser inserido no inicio da lista: ";
                cin >> valor;
                inicio = listaAdicionaInicio(inicio, valor);
                if(fim == NULL) fim = inicio;
                break;
            case 2:
                cout << "\nInsira o valor a ser inserido no fim da lista: ";
                cin >> valor;
                fim = listaAdicionaFim(fim, valor);
                if(inicio == NULL) inicio = fim;
                break;
            case 3:
                cout << "\nExiste(m) " << listaConta(inicio, fim) << " elemento(s) na lista!\n";
                break;
            case 4:
                (listaChecaCrescente(inicio, fim)) ? cout << "\nLista e crescente!\n" : cout << "\nLista NAO e crescente!\n";
                break;
            case 0:
                break;
            default:
                cout << "\nOpcao invalida!\n";
        }
        listaExibe(inicio, fim);
    }
    return 0;
}