#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int valor;
    struct ELEMENTO *proximo;
} pilha;

pilha *inserePilha(pilha *topo, int valor) {
    pilha *novo = new pilha();
    novo->valor = valor;
    novo->proximo = topo;
    topo = novo;
    return topo;
}

pilha *removePilha(pilha *topo) {
    pilha *aux = topo;
    topo = topo->proximo;
    delete(aux);
    return topo;
}

void breadcrumbing(pilha *topo, string pagina[16]) {
    if(topo->proximo != NULL) {
        breadcrumbing(topo->proximo, pagina);
        cout << " > " << pagina[topo->valor];
    } else {
        cout << pagina[topo->valor];
    }
}

int main() {
    int opcao = 1, filho[16] = {3, 3, 3, 2, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, idFilho[16] = {1, 4, 7, 10, -1, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, i = 0, j, k;
    string pagina[16] = {"home", "esportes", "notícias", "entretenimento", "basquete", "futebol", "tênis", "campinas", "rio preto", "são paulo", "novelas", "fofocas", "corinthians", "palmeiras", "santos", "são paulo"};
    pilha *topo = inserePilha(topo, 0);
    cout << "Bem vindo ao MeuSite!\n";
    while(opcao != 0) {
        cout << "\nVocê está em: ";
        breadcrumbing(topo, pagina);
        cout << "\n\nInsira sua escolha\n\n";
        k = idFilho[i];
        for(j = 1; j <= filho[i]; j++) {
            cout << j << " - Ir para: " << pagina[k++] << "\n";
        }
        if(i > 0) cout << "-1 - Voltar\n";
        cout << "0 - Sair\n";
        cout << "> ";
        cin >> opcao;
        if(opcao > -1 && opcao < 5 && opcao <= filho[i]) {
            i = opcao + idFilho[i] - 1;
            topo = inserePilha(topo, i);
        } else if(opcao == -1 && i > 0) {
            topo = removePilha(topo);
            i = topo->valor;
        } else {
            cout << "\nOpção inválida!\n";
        }
    }
}