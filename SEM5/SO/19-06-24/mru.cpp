#include <iostream>
#include <random>

typedef struct pagina {
    int id;
    int flag;
    struct pagina *prox;
} Pagina;

Pagina *mru(Pagina *pagina) {
    int mru = 0;
    int mru_id = -1;
    Pagina *auxiliar = pagina, *anterior = NULL;
    while(auxiliar != NULL) {
        if(auxiliar->flag > mru)
            mru_id = auxiliar->id;
        auxiliar = auxiliar->prox;
    }
    auxiliar = pagina;
    if(mru_id != -1) {
        while(auxiliar->id != mru_id) {
            anterior = auxiliar;
            auxiliar = auxiliar->prox;
        }
    }
}

int main() {
    int x;
    Pagina *lista = NULL;
    std::random_device rd;
    for(x = 0; x < 10; x++) {
        Pagina *pagina = new Pagina;
        pagina->id = x;
        pagina->flag = rd();
        pagina->prox = lista;
        lista = pagina;
    }
    return 0;
}