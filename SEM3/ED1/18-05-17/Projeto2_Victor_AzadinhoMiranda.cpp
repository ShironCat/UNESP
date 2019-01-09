#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int valor, alturaEsquerda, alturaDireita;
    struct ELEMENTO *esquerda, *direita;
} Arvore;

Arvore *rotacaoEsquerda(Arvore *aux) {
    Arvore *aux1, *aux2;
    aux1 = aux->direita;
    aux2 = aux1->esquerda;
    aux->direita = aux2;
    aux1->esquerda = aux;
    if(aux->direita == NULL) {
        aux->alturaDireita = 0;
    } else if(aux->direita->alturaEsquerda > aux->direita->alturaDireita) {
        aux->alturaDireita = aux->direita->alturaEsquerda + 1;
    } else {
        aux->alturaDireita = aux->direita->alturaDireita + 1;
    }
    if(aux1->esquerda->alturaEsquerda > aux1->esquerda->alturaDireita) {
        aux1->alturaEsquerda = aux1->esquerda->alturaEsquerda + 1;
    } else {
        aux1->alturaEsquerda = aux1->esquerda->alturaDireita + 1;
    }
    return aux1;
}

Arvore *rotacaoDireita(Arvore *aux) {
    Arvore *aux1, *aux2;
    aux1 = aux->esquerda;
    aux2 = aux1->direita;
    aux->esquerda = aux2;
    aux1->direita = aux;
    if(aux->esquerda == NULL) {
        aux->alturaEsquerda = 0;
    } else if(aux->esquerda->alturaEsquerda > aux->esquerda->alturaDireita) {
        aux->alturaEsquerda = aux->esquerda->alturaEsquerda + 1;
    } else {
        aux->alturaEsquerda = aux->esquerda->alturaDireita + 1;
    }
    if(aux1->direita->alturaEsquerda > aux1->direita->alturaDireita) {
        aux1->alturaDireita = aux1->direita->alturaEsquerda + 1;
    } else {
        aux1->alturaDireita = aux1->direita->alturaDireita + 1;
    }
    return aux1;
}

Arvore *balanceamento(Arvore *aux) {
    int d, df;
    d = aux->alturaDireita - aux->alturaEsquerda;
    if(d == 2) {
        df = aux->direita->alturaDireita - aux->direita->alturaEsquerda;
        if(df >= 0) {
            aux = rotacaoEsquerda(aux);
        } else {
            aux->direita = rotacaoDireita(aux->direita);
            aux = rotacaoEsquerda(aux);
        }
    } else if(d == -2) {
        df = aux->esquerda->alturaDireita - aux->esquerda->alturaEsquerda;
        if(df <= 0) {
            aux = rotacaoDireita(aux);
        } else {
            aux->esquerda = rotacaoEsquerda(aux->esquerda);
            aux = rotacaoDireita(aux);
        }
    }
    return aux;
}

Arvore *inserir(Arvore *aux, int valor) {
    Arvore *novo;
    if(aux == NULL) {
        novo = new Arvore();
        novo->valor = valor;
        novo->alturaEsquerda = novo->alturaDireita = 0;
        novo->esquerda = novo->direita = NULL;
        aux = novo;
    } else if(valor < aux->valor) {
        aux->esquerda = inserir(aux->esquerda, valor);
        if(aux->esquerda->alturaDireita > aux->esquerda->alturaEsquerda) {
            aux->alturaEsquerda = aux->esquerda->alturaDireita + 1;
        } else {
            aux->alturaEsquerda = aux->esquerda->alturaEsquerda + 1;
        }
        aux = balanceamento(aux);
    } else {
        aux->direita = inserir(aux->direita, valor);
        if(aux->direita->alturaDireita > aux->direita->alturaEsquerda) {
            aux->alturaDireita = aux->direita->alturaDireita + 1;
        } else {
            aux->alturaDireita = aux->direita->alturaEsquerda + 1;
        }
        aux = balanceamento(aux);
    }
    return aux;
}

int consultar(Arvore *aux, int valor, int achou) {
    if(aux != NULL && achou == 0) {
        if(aux->valor == valor) {
            achou = 1;
        } else if(valor < aux->valor) {
            achou = consultar(aux->esquerda, valor, achou);
        } else {
            achou = consultar(aux->direita, valor, achou);
        }
    }
    return achou;
}

Arvore *atualiza(Arvore *aux) {
    if(aux != NULL) {
        aux->esquerda = atualiza(aux->esquerda);
        if(aux->esquerda == NULL) {
            aux->alturaEsquerda = 0;
        } else if(aux->esquerda->alturaEsquerda > aux->esquerda->alturaDireita) {
            aux->alturaEsquerda = aux->esquerda->alturaEsquerda + 1;
        } else {
            aux->alturaEsquerda = aux->esquerda->alturaDireita + 1;
        }
        aux->direita = atualiza(aux->direita);
        if(aux->direita == NULL) {
            aux->alturaDireita = 0;
        } else if(aux->direita->alturaEsquerda > aux->direita->alturaDireita) {
            aux->alturaDireita = aux->direita->alturaEsquerda + 1;
        } else {
            aux->alturaDireita = aux->direita->alturaDireita + 1;
        }
        aux = balanceamento(aux);
    }
    return aux;
}

Arvore *remover(Arvore *aux, int valor) {
    Arvore *aux1, *aux2;
    if(aux->valor == valor) {
        if(aux->esquerda == aux->direita) {
            delete(aux);
        } else if(aux->esquerda == NULL) {
            aux1 = aux->direita;
            delete(aux);
            return aux1;
        } else if(aux->direita == NULL) {
            aux1 = aux->esquerda;
            delete(aux);
            return aux1;
        } else {
            aux2 = aux->direita;
            aux1 = aux->direita;
            while(aux1->esquerda != NULL) aux1 = aux1->esquerda;
            aux1->esquerda = aux->esquerda;
            delete(aux);
            return aux2;
        }
    } else if(aux->valor < valor) {
        aux->direita = remover(aux->direita, valor);
    } else {
        aux->esquerda = remover(aux->esquerda, valor);
    }
    aux = atualiza(aux);
    return aux;
}

void exibirOrdem(Arvore *aux) {
    if(aux != NULL) {
        exibirOrdem(aux->esquerda);
        cout << aux->valor << " ";
        exibirOrdem(aux->direita);
    }
}

void exibirPreOrdem(Arvore *aux) {
    if(aux != NULL) {
        cout << aux->valor << " ";
        exibirPreOrdem(aux->esquerda);
        exibirPreOrdem(aux->direita);
    }
}

void exibirPosOrdem(Arvore *aux) {
    if(aux != NULL) {
        exibirPosOrdem(aux->esquerda);
        exibirPosOrdem(aux->direita);
        cout << aux->valor << " ";
    }
}

int altura(Arvore *aux) {
    if(aux != NULL) {
        if(aux->alturaEsquerda > aux->alturaDireita) {
            return aux->alturaEsquerda + 1;
        } else {
            return aux->alturaDireita + 1;
        }
    }
    return 0;
}

int quantidadeNos(Arvore *aux) {
    if(aux != NULL) return quantidadeNos(aux->esquerda) + quantidadeNos(aux->direita) + 1;
    return 0;
}

int main() {
    Arvore *arvore = NULL;
    int opcao, valor;
    do {
        cout << "\nInsira uma opção:\n";
        cout << "1 - Inserir um número\n";
        cout << "2 - Remover um número\n";
        cout << "3 - Exibir em ordem\n";
        cout << "4 - Exibir em pré-ordem\n";
        cout << "5 - Exibir em pós-ordem\n";
        cout << "6 - Mostrar a altura da árvore e quantidade de nós\n";
        cout << "0 - Sair\n";
        cout << "> ";
        cin >> opcao;
        switch(opcao) {
            case 1:
                cout << "\nInsira um valor para ser inserido: ";
                cin >> valor;
                arvore = inserir(arvore, valor);
                break;
            case 2:
                cout << "\nInsira um valor para ser removido: ";
                cin >> valor;
                arvore = remover(arvore, valor);
                break;
            case 3:
                cout << "\nÁrvore em ordem:\n";
                exibirOrdem(arvore);
                cout << "\n";
                break;
            case 4:
                cout << "\nÁrvore em pré-ordem:\n";
                exibirPreOrdem(arvore);
                cout << "\n";
                break;
            case 5:
                cout << "\nÁrvore em pós-ordem:\n";
                exibirPosOrdem(arvore);
                cout << "\n";
                break;
            case 6:
                cout << "\nAltura da árvore: " << altura(arvore) << "\n";
                cout << "Quantidade de nós: " << quantidadeNos(arvore) << "\n";
            case 0: break;
            default:
                cout << "\nOpção inválida!\n";
                break;
        }
    } while(opcao != 0);
    return 0;
}