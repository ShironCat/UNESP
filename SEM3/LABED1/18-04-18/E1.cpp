#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct ELEMENTO {
    string nome;
    struct ELEMENTO *prox;
} lista;

lista *insereLista(lista *inicio, lista *fim, string nome) {
    lista *novo = new lista();
    novo->nome = nome;
    if(inicio == NULL) {
        novo->prox = novo;
    } else {
        novo->prox = inicio;
        fim->prox = novo;
    }
    return inicio = novo;
}

lista *removeLista(lista* inicio, lista *anterior) {
    lista *aux = inicio;
    inicio = inicio->prox;
    anterior->prox = inicio;
    delete(aux);
    return inicio;
}

void sorteiaSoldado(lista *inicio, lista *fim, int n, int i) {
    int j;
    lista *aux, *anterior;
    if(inicio == fim) {
        cout << "Há apenas um soldado para se salvar: " << inicio->nome << "\n";
    } else {
        for(j = 1; j < i; j++) {
            anterior = inicio;
            inicio = inicio->prox;
        }
        cout << inicio->nome << "\n";
        inicio = removeLista(inicio, anterior);
        while(inicio != inicio->prox) {
            for(j = 0; j < n; j++) {
                anterior = inicio;
                inicio = inicio->prox;
                cout << inicio->nome << "\n";
                removeLista(inicio, anterior);
            }
        }
        cout << inicio->nome << " buscará ajuda!\n";
    }
}

int main() {
    int n, soldados, i;
    string nome;
    lista *inicio = NULL, *fim = NULL;
    srand(time(NULL));
    cout << "Insira quantos soldados estão no circulo: ";
    cin >> soldados;
    for(i = 0; i < soldados; i++) {
        cout << "Insira o nome do " << (i + 1) << "º soldado: ";
        cin >> nome;
        inicio = insereLista(inicio, fim, nome);
        if(fim == NULL) fim = inicio;
    }
    cout << "Insira o valor de n: ";
    cin >> n;
    sorteiaSoldado(inicio, fim, n, rand() % (soldados + 1));
    return 0;
}