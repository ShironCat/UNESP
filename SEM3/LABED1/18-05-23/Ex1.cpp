#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    int num, altd, alte;
    struct ELEMENTO *dir, *esq;
} Arvore;

Arvore *rotacaoEsquerda(Arvore *aux) {
    Arvore *aux1, *aux2;
    aux1 = aux->dir;
    aux2 = aux1->esq;
    aux->dir = aux2;
    aux1->esq = aux;
    if(aux->dir == NULL) {
        aux->altd = 0;
    } else if(aux->dir->alte > aux->dir->altd) {
        aux->altd = aux->dir->alte + 1;
    } else {
        aux->altd = aux->dir->altd + 1;
    }
    if(aux1->esq->alte > aux1->esq->altd) {
        aux1->alte = aux1->esq->alte + 1;
    } else {
        aux1->alte = aux1->esq->altd + 1;
    }
    return aux1;
}

Arvore *rotacaoDireita(Arvore *aux) {
    Arvore *aux1, *aux2;
    aux1 = aux->esq;
    aux2 = aux1->dir;
    aux->esq = aux2;
    aux1->dir = aux;
    if(aux->esq == NULL) {
        aux->alte = 0;
    } else if(aux->esq->alte > aux->esq->altd) {
        aux->alte = aux->esq->alte + 1;
    } else {
        aux->alte = aux->esq->altd + 1;
    }
    if(aux1->dir->alte > aux1->dir->altd) {
        aux1->altd = aux1->dir->alte + 1;
    } else {
        aux1->altd = aux1->dir->altd + 1;
    }
    return aux1;
}

Arvore *balanceamento(Arvore *aux) {
    int d, df;
    d = aux->altd - aux->alte;
    if(d == 2) {
        df = aux->dir->altd - aux->dir->alte;
        if(df >= 0) {
            aux = rotacaoEsquerda(aux);
        } else {
            aux->dir = rotacaoDireita(aux->dir);
            aux = rotacaoEsquerda(aux);
        }
    } else if(d == -2) {
        df = aux->esq->altd - aux->esq->alte;
        if(df <= 0) {
            aux = rotacaoDireita(aux);
        } else {
            aux->esq = rotacaoEsquerda(aux->esq);
            aux = rotacaoDireita(aux);
        }
    }
    return aux;
}

Arvore *inserir(Arvore *aux, int num) {
    Arvore *novo;
    if(aux == NULL) {
        novo = new Arvore();
        novo->num = num;
        novo->altd = 0;
        novo->alte = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        aux = novo;
    } else if(num < aux->num) {
        aux->esq = inserir(aux->esq, num);
        if(aux->esq->altd > aux->esq->alte) {
            aux->alte = aux->esq->altd + 1;
        } else {
            aux->alte = aux->esq->alte + 1;
        }
        aux = balanceamento(aux);
    } else {
        aux->dir = inserir(aux->dir, num);
        if(aux->dir->altd > aux->dir->alte) {
            aux->altd = aux->dir->altd + 1;
        } else {
            aux->altd = aux->dir->alte + 1;
        }
        aux = balanceamento(aux);
    }
    return aux;
}

int consultar(Arvore *aux, int num, int achou) {
    if(aux != NULL && achou == 0) {
        if(aux->num == num) {
            achou = 1;
        } else if(num < aux->num) {
            achou = consultar(aux->esq, num, achou);
        } else {
            achou = consultar(aux->dir, num, achou);
        }
    }
    return achou;
}

Arvore *atualiza(Arvore *aux) {
    if(aux != NULL) {
        aux->esq = atualiza(aux->esq);
        if(aux->esq == NULL) {
            aux->alte = 0;
        } else if(aux->esq->alte > aux->esq->altd) {
            aux->alte = aux->esq->alte + 1;
        } else {
            aux->alte = aux->esq->altd + 1;
        }
        aux->dir = atualiza(aux->dir);
        if(aux->dir == NULL) {
            aux->altd = 0;
        } else if(aux->dir->alte > aux->dir->altd) {
            aux->altd = aux->dir->alte + 1;
        } else {
            aux->altd = aux->dir->altd + 1;
        }
        aux = balanceamento(aux);
    }
    return aux;
}

Arvore *remover(Arvore *aux, int num) {
    Arvore *p, *p2;
    if(aux->num == num) {
        if(aux->esq == aux->dir) {
            delete(aux);
        } else if(aux->esq == NULL) {
            p = aux->dir;
            delete(aux);
            return p;
        } else if(aux->dir == NULL) {
            p = aux->esq;
            delete(aux);
            return p;
        } else {
            p2 = aux->dir;
            p = aux->dir;
            while(p->esq != NULL) p = p->esq;
            p->esq = aux->esq;
            delete(aux);
            return p2;
        }
    } else if(aux->num < num) {
        aux->dir = remover(aux->dir, num);
    } else {
        aux->esq = remover(aux->esq, num);
    }
    aux = atualiza(aux);
    return aux;
}