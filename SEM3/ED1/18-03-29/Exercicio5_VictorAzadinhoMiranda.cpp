#include <iostream>
using namespace std;

typedef struct ELEMENTO {
    string nome;
    float notaFinal;
    struct ELEMENTO *proximo;
    struct ELEMENTO *anterior;
} aluno;
//Declaração do struct aluno com nome, nota final, elemento proximo e elemento anterior.

aluno *insereInicio(aluno *inicio, string nome, float notaFinal) {
    aluno *novo = new aluno();
    novo->nome = nome;
    novo->notaFinal = notaFinal;
    novo->anterior = NULL;
    novo->proximo = inicio;
    if(inicio != NULL) inicio->anterior = novo;
    inicio = novo;
    return inicio;
}
//Função para inserção no início de uma lista duplamente encadeada não ordenada

void exibeAprovados(aluno *inicio) {
    cout << "\n";
    if(inicio == NULL) {
        cout << "Nenhum aluno cadastrado!";
    } else {
        int exibe = 0;
        while(inicio != NULL) {
            if(inicio->notaFinal >= 5.0) {
                cout << "Aluno " << inicio->nome << " aprovado com média " << inicio->notaFinal << "!\n";
                exibe = 1;
            }
            inicio = inicio->proximo;
        }
        if(!exibe) {
            cout << "Nenhum aluno foi aprovado!\n";
        }
    }
}
//Função para exibição dos alunos aprovados(nota final maior ou igual a 5).
//Caso essa condição não for encontrada nenhuma vez, ou seja, se nenhum aluno for aprovado, uma mensagem de alerta será emitida.

int main() {
    int i;
    float notaFinal;
    string nome;
    aluno *inicio = NULL, *fim = NULL;
    cout << "Controle de alunos!\n";
    for(i = 1; i <= 5; i++) {
        cout << "\nInsira o " << i << "º aluno!\n";
        cout << "Nome: ";
        cin >> nome;
        cout << "Nota final: ";
        cin >> notaFinal;
        inicio = insereInicio(inicio, nome, notaFinal);
        if(fim == NULL) fim = inicio;
    }
    exibeAprovados(inicio);
    return 0;
}
//Função main, onde a informação é inserida para que os alunos sejam cadastrados.