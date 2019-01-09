#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int num;
    struct ELEMENTO *esq, *dir;
} Arvore;

Arvore *insereArvore(Arvore *raiz, int num) {
    if(raiz == NULL) {
        raiz = new Arvore();
        raiz->num = num;
        raiz->esq = raiz->dir = NULL;
    } else if(num < raiz->num) {
        raiz->esq = insereArvore(raiz->esq, num);
    } else {
        raiz->dir = insereArvore(raiz->dir, num);
    }
    return raiz;
}

void mostrarFolha(Arvore *raiz) {
    if(raiz != NULL) {
        if(raiz->esq != NULL) {
            mostrarFolha(raiz->esq);
            if(raiz->dir != NULL) mostrarFolha(raiz->dir);
        } else if(raiz->dir != NULL) {
            mostrarFolha(raiz->dir);
        } else {
            cout << raiz->num << " ";
        }
    }
}
//Mostra as folhas da árvore.

int ancestralArvore(Arvore *raiz, int num, int achou) {
    if(raiz != NULL && achou == 0) {
        if(raiz->num == num) {
            achou = 1;
        } else if(num < raiz->num) {
            if(achou = ancestralArvore(raiz->esq, num, achou)) cout << raiz->num << " ";
            //Verifica se o nó foi encontrado e, se sim, exibe o valor do ancestral.
        } else {
            if(achou = ancestralArvore(raiz->dir, num, achou)) cout << raiz->num << " ";
            //Verifica se o nó foi encontrado e, se sim, exibe o valor do ancestral.
        }
    }
    return achou;
}
//Mostra os ancestrais de um nó escolhido pelo usuário.

int main() {
    int opcao, num;
    Arvore *raiz = NULL;
    do {
        cout << "\nInsira sua opção\n";
        cout << "1 - Inserir número\n";
        cout << "2 - Mostrar os nós folha\n";
        cout << "3 - Mostrar os ancestrias de um nó\n";
        cout << "0 - Sair\n";
        cout << "> ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "\nInsira o número: ";
                cin >> num;
                raiz = insereArvore(raiz, num);
                break;
            case 2:
                cout << "\nNós Folha:\n";
                mostrarFolha(raiz);
                cout << "\n";
                break;
            case 3:
                cout << "\nInsira o número do nó: ";
                cin >> num;
                cout << "\nNós ancestrais:\n";
                (ancestralArvore(raiz, num, 0)) ? cout << "\n" : cout << "Nó não encontrado!\n";
                //Verifica se o nó foi encontrado, se não, exibe um aviso para o usuário.
                break;
            case 0: break;
            default:
                cout << "\nOpção inválida!\n";
        }
    } while(opcao != 0);
    return 0;
}