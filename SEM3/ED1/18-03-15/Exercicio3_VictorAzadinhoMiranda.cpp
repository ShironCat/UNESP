#include <iostream>
using namespace std;

typedef struct ELEMENTO{
    int valor;
    struct ELEMENTO *proximo;
} estrutura;

int main() {
    estrutura *pilhaTopo = NULL, *filaInicio = NULL, *filaFim = NULL, *pilhaNovo, *filaNovo, *auxiliarPilha, *auxiliarFila;
    int i, valor;
    cout << "Insira 10 valores na pilha: ";
    for(i = 0; i < 10; i++) {
        cin >> valor;
        pilhaNovo = new estrutura();
        pilhaNovo->valor = valor;
        pilhaNovo->proximo = pilhaTopo;
        pilhaTopo = pilhaNovo;
    }
    cout << "Insira 10 valores na fila: ";
    for(i = 0; i < 10; i++) {
        cin >> valor;
        filaNovo = new estrutura();
        filaNovo->valor = valor;
        filaNovo->proximo = NULL;
        if(filaInicio == NULL) {
            filaInicio = filaNovo;
            filaFim = filaNovo;
        } else {
            filaFim->proximo = filaNovo;
            filaFim = filaNovo;
        }
    }
    auxiliarPilha = pilhaTopo;
    auxiliarFila = filaInicio;
    cout << "Resultado:\n";
    for(i = 0; i < 10; i++) {
        cout << "Fila: " << auxiliarFila->valor << " + Pilha: " << auxiliarPilha->valor << " = " << (auxiliarFila->valor + auxiliarPilha->valor) << "\n";
        auxiliarPilha = auxiliarPilha->proximo;
        auxiliarFila = auxiliarFila->proximo;
    }
    return 0;
}