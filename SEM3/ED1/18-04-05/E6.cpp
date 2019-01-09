#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    string nome;
    int idade;
    float nota1, nota2;
    struct ELEMENTO *prox;
} Lista;

typedef struct ELEMENTO {
    string nome;
    int idade;
    float nota1, nota2;
    struct ELEMENTO *prox;
    struct ELEMENTO *ant;
} ListaDupla;

Lista *insereLista(Lista *inicio, string nome, int idade, float nota1, float nota2) {
    Lista *novo = new Lista();
    novo->nome = nome;
    novo->idade = idade;
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->prox = inicio;
    return inicio = novo;
}

ListaDupla *geraListaDupla(listaDupla *inicioDupla, Lista *inicioF, Lista *inicioM) {
    int i, j = 3, k;
    string nome1, nome2, maior;
    Lista *MarcaF = inicioF, *aux, *anterior;
    ListaDupla *novo;
    while(inicioF->prox != NULL) inicioF = inicioF->prox;
    inicioF->prox = inicioM;
    inicioF = MarcaF;
    while(inicioF != NULL) {
        for(i = 0; i < inicioF->nome.size(); i++) nome1[i] = tolower(inicio->nome[i]);
        for(i = 0; i < inicioF->prox->nome.size(); i++) nome2[i] = tolower(inicio->prox->nome[i]);
        if(nome1.compare(nome2) > 0) {
            maior = inicioF->nome;
        } else {
            maior = inicioF->prox->nome;
        }
        inicioF = inicioF->prox->prox;
        for(i = 0; i < j; i++) {
            for(k = 0; k < inicioF->nome.size(); k++) nome1[k] = tolower(inicio->nome[k]);
            for(k = 0; k < maior.size(); k++) nome2[k] = tolower(maior[k]);
            if(nome1.compare(nome2) > 0) {
                maior = inicioF->nome;
            }
            inicioF = inicioF->prox;
        }
        inicioF = marcaF;
        while(inicioF->nome.compare(maior) != 0) {
            anterior = inicioF;
            inicioF = inicioF->prox;
        }
        aux = inicioF;
        novo = new ListaDupla();
        novo->nome = aux->nome;
        novo->idade = aux->idade;
        novo->nota1 = aux->nota1;
        novo->nota2 = aux->nota2;
        novo->prox = inicioDupla;
        if(inicioDupla == NULL) {
            novo->ant = inicioDupla;
        } else {
            novo->ant = inicioDupla->ant;
        }
        inicioDupla = novo;
        anterior->prox = aux->prox;
        inicioF = marcaF;
        delete(aux);
    }
    return inicioDupla;
}

int main() {
    int i, idade, sexo;
    float nota1, nota2;
    string nome;
    Lista *inicioM = NULL, *inicioF = NULL;
    ListaDupla *inicioDupla = NULL;
    for(i = 0; i < 5; i++) {
        cout << "Insira o nome do " << (i + 1) << "º aluno: ";
        cin >> nome;
        cout << "Insira a idade de \"" << nome << "\": ";
        cin >> idade;
        cout << "Insira a primeira nota de \"" << nome << "\": ";
        cin >> nota1;
        cout << "Insira a segunda nota de \"" << nome << "\": ";
        cin >> nota2;
        do {
            cout << "Selecione o sexo do aluno\n";
            cout << "1 - Feminino\n";
            cout << "2 - Masculino\n";
            cout << "> ";
            cin >> sexo;
            switch(sexo) {
                case 1:
                    inicioF = insereLista(inicioF, nome, idade, nota1, nota2);
                    break;
                case 2:
                    inicioM = insereLista(inicioM, nome, idade, nota1, nota2);
                    break;
                default:
                    cout << "Opção inválida!";
            }
        } while(sexo < 1 && sexo > 2);
    }
    return 0;
}