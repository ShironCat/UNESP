#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int num;
    struct ELEMENTO *prox, *ant;
} Lista;

Lista *insereLista(Lista *inicio, int num) {
    Lista *novo = new Lista();
    novo->num = num;
    if(inicio == NULL) {
        novo->prox = novo->ant = novo;
        inicio = novo;
    } else {
        novo->prox = inicio;
        novo->ant = inicio->ant;
        inicio->ant->prox = novo;
        inicio->ant = novo;
        inicio = novo;
    }
    return inicio;
}

Lista *intercalaInicioFim(Lista *inicio1, Lista *inicio2, Lista *inicioFim, int n) {
    int i;
    for(i = 0; i < n; i++) {
        inicioFim = insereLista(inicioFim, inicio2->num);
        inicioFim = insereLista(inicioFim, inicio1->num);
        inicio1 = inicio1->prox;
        inicio2 = inicio2->prox;
    }
    return inicioFim;
}

Lista *intercalaFimInicio(Lista *inicio1, Lista *inicio2, Lista *fimInicio, int n) {
    int i;
    inicio1 = inicio1->ant;
    inicio2 = inicio2->ant;
    for(i = 0; i < n; i++) {
        fimInicio = insereLista(fimInicio, inicio2->num);
        fimInicio = insereLista(fimInicio, inicio1->num);
        inicio1 = inicio1->ant;
        inicio2 = inicio2->ant;
    }
    return fimInicio;
}

int main() {
    int n, num, i, j;
    Lista *inicio1 = NULL, *inicio2 = NULL, *inicioFim = NULL, *fimInicio = NULL;
    cout << "Insira quantos elementos as listas terão: ";
    cin >> n;
    for(i = 0; i < 2; i++) {
        cout << "insira os elementos da " << ((i) ? "segunda" : "primeira") << " lista:\n";
        for(j = 0; j < n; j++) {
            cin >> num;
            if(i) {
                inicio2 = insereLista(inicio2, num);
            } else {
                inicio1 = insereLista(inicio1, num);
            }
        }
    }
    inicioFim = intercalaInicioFim(inicio1, inicio2, inicioFim, n);
    cout << "Lista intercalada do inicio ao fim:\n";
    for(i = 0; i < (n * 2); i++) {
        cout << inicioFim->num << " ";
        inicioFim = inicioFim->prox;
    }
    fimInicio = intercalaFimInicio(inicio1, inicio2, fimInicio, n);
    cout << "\nLista intercalada do fim ao inicio:\n";
    for(i = 0; i < (n * 2); i++) {
        cout << fimInicio->num << " ";
        fimInicio = fimInicio->prox;
    }
    cout << "\n";
    return 0;
}