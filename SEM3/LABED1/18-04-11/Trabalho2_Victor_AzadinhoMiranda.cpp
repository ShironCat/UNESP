#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int numero;
    string texto;
    struct ELEMENTO *proximo, *anterior;
} Pagina;

Pagina *inserePagina(Pagina *fim, string texto) {
    if(fim == NULL) {
        fim = new Pagina();
        fim->numero = 1;
        fim->texto = texto;
        fim->anterior = NULL;
        fim->proximo = NULL;
    } else {
        Pagina *novo = new Pagina();
        novo->numero = fim->numero + 1;
        novo->texto = texto;
        novo->anterior = fim;
        novo->proximo = NULL;
        fim->proximo = novo;
        fim = novo;
    }
    return fim;
}

void modoLeitura(Pagina *inicio, int numeroPaginas) {
    int opcao, i;
    Pagina *aux = inicio;
    do {
        cout << "\nPágina: " << aux->numero << "\n\n";
        cout << aux->texto << "\n\n";
        cout << "1 - Buscar página\t";
        if(aux->proximo != NULL) cout << "2 - Próxima página\t";
        if(aux->anterior != NULL) cout << "3 - Página anterior\t";
        cout << "0 - Sair do modo de leitura\n";
        cout << "> ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "\nInsira o número da página para busca\n";
                cout << "> ";
                cin >> i;
                Pagina *busca;
                for(busca = inicio; busca != NULL && busca->numero != i; busca = busca->proximo);
                if(busca == NULL) {
                    cout << "\nPágina não encontrada!\n";
                } else {
                    aux = busca;
                }
                break;
            case 2:
                if(aux->proximo != NULL) aux = aux->proximo;
                break;
            case 3:
                if(aux->anterior != NULL) aux = aux->anterior;
                break;
            case 0: break;
            default:
                cout << "Opção inválida!\n\n";
        }
    } while(opcao != 0);
}

int main() {
    int opcao, numeroPaginas = 0;
    string texto;
    Pagina *inicio = NULL, *fim = NULL;
    do {
        cout << "\nEscolha uma opção\n";
        cout << "1 - Adicionar uma página ao fim\n";
        if(fim != NULL) cout << "2 - Entrar em modo leitura\n";
        cout << "0 - Sair\n";
        cout << "> ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "\nInsira o texto da página:\n";
                cin.ignore();
                getline(cin, texto);
                fim = inserePagina(fim, texto);
                if(inicio == NULL) inicio = fim;
                numeroPaginas++;
                break;
            case 2:
                if(fim != NULL) modoLeitura(inicio, numeroPaginas);
                break;
            case 0: break;
            default:
                cout << "Opção inválida!\n";
        }
    } while(opcao != 0);
    return 0;
}