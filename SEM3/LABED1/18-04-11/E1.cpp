#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    string nome;
    float altura;
    struct ELEMENTO *proximo;
} lista;

lista *insereListaOrdenado(lista *inicio, string nome, float altura) {
    lista *novo = new lista();
    novo->nome = nome;
    novo->altura = altura;
    if(inicio == NULL) {
        novo->proximo = inicio;
        inicio = novo;
    } else {
        lista *aux = inicio;
        while(novo->altura < aux->altura && aux->proximo != NULL) aux = aux->proximo;
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    return inicio;
}

lista *ajustaFim(lista *inicio, lista *fim) {
    if(inicio == NULL) {
        fim = NULL;
    } else if(inicio->proximo == NULL) {
        fim = inicio;
    } else {
        fim = ajustaFim(inicio->proximo, fim);
    }
    return fim;
}

void exibeLista(lista *inicio, lista *fim) {
    if(inicio == NULL) {
        cout << "Lista vazia!\n";
    } else {
        while(inicio != fim->proximo) {
            cout << "Nome do atleta: " << inicio->nome << "\tAltura do atleta: " << inicio->altura << "m\n";
            inicio = inicio->proximo;
        }
    }
}

int main() {
    lista *inicio = NULL, *fim = NULL;
    int opcao;
    string nome;
    float altura;
    do {
        cout << "\nEscolha uma opção\n\n";
        cout << "1 - Adicionar um atleta\n";
        cout << "2 - Exibe atletas\n";
        cout << "0 - Sair\n\n";
        cout << "> ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "\nInsira o nome do atleta: ";
                cin >> nome;
                cout << "Insira a altura do atleta(em metros): ";
                cin >> altura;
                inicio = insereListaOrdenado(inicio, nome, altura);
                fim = ajustaFim(inicio, fim);
                break;
            case 2:
                cout << "\nAtletas\n\n";
                exibeLista(inicio, fim);
                break;
            case 0: break;
            default:
                cout << "\nOpção inválida!\n";
        }
    } while(opcao != 0);
}