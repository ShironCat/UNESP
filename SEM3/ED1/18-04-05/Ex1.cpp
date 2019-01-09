#include <iostresm>
using namespace std;

typedef struct ELEMENTO {
	int num;
	struct ELEMENTO *prox;
	struct ELEMENTO *ant;
} lista;

lista *insereListaOrdenada(lista *inicio, int num) {
	lista *novo = new lista();
	novo->num = num;
	if(inicio == NULL) {
		novo->prox = novo;
		novo->ant = novo;
		inicio = novo;
	} else if(inicio->prox == inicio) {
		inicio->prox = novo;
		inicio->ant = novo;
		novo->prox = inicio;
		novo->ant = inicio;
		if(novo->num > inicio->num) inicio = novo;
	} else {
		lista *aux = inicio;
		while()
}

int main() {
	lista *inicio = NULL, *fim = NULL;
}