#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    string id;
    struct ELEMENTO *prox;
} fila;

fila *mandarImprimir(fila *fim, string id) {
    fila *novo = new fila();
    novo->id = id;
    novo->prox = NULL;
    fim->prox = novo;
    fim = novo;
    return fim;
}

fila *consumirImpressao(fila *inicio) {
    fila *aux;
    if(inicio == NULL) {
        cout << "Fila vazia!\n";
    } else {
        aux = inicio;
        cout << "Imprimindo: " << inicio->id << "\n";
        inicio = inicio->prox;
        delete(aux);
    }
    return inicio;
}

int main() {
    fila *inicio = NULL, *fim = NULL;
    string id;
    int op = 1;
    cout << "Fila de Impressão\n";
    while(op != 0) {
        cout << "Escolha uma opção\n\n";
        cout << "1 - Mandar um documento para impressão\n";
        cout << "2 - Executar fila de impressão\n";
        cout << "0 - Sair\n\n";
        cout << "> ";
        cin >> op;
        switch(op) {
            case 1:
                cout << "\nInsira o nome do arquivo: ";
                cin >> id;
                if(inicio == NULL) {
                    inicio = fim = mandarImprimir(fim, id);
                } else {
                    fim = mandarImprimir(fim, id);
                }
                break;
            case 2:
                if(inicio == fim) {
                    fim = inicio = consumirImpressao(inicio);
                } else {
                    inicio = consumirImpressao(inicio);
                }
                break;
            case 0:
                break;
            default:
                cout << "Opção inválida!\n";
        }
    }
    return 0;
}