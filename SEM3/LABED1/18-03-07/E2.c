#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[150], sexo;
    float altura, peso;
    int cpf;
} pessoa;

pessoa *cadastraPessoa() {
    pessoa *novo;
    novo = (pessoa*)malloc(sizeof(pessoa));
    printf("Insira o nome da pessoa: ");
    scanf("%[^\n]", novo->nome);
    printf("Insira a altura da pessoa: ");
    scanf("%f", &novo->altura);
    printf("Insira o peso da pessoa: ");
    scanf("%f", &novo->peso);
    printf("Insira o cpf da pessoa: ");
    scanf("%d", &novo->cpf);
    printf("Insira o sexo da pessoa(F/M): ");
    scanf("%c", &novo->sexo);
    return novo;
}

void main() {
    int i, busca;
    pessoa *pessoas[5];
    printf("IMC de pessoas\n");
    for(i = 0; i < 5; i++) pessoas[i] = cadastraPessoa();
    printf("Busca por cpf: ");
    scanf("%d", &busca);
    for(i = 0; i < 5 && pessoas[i]->cpf != busca; i++);
    if(i == 5) {
        printf("Pessoa nao encontrada\n");
    } else {
        printf("Nome: %s", pessoas[i]->nome);
        printf("Altura: %g", pessoas[i]->altura);
        printf("Peso: %g", pessoas[i]->peso);
        printf("CPF: %d", pessoas[i]->cpf);
        printf("Sexo: %c", pessoas[i]->sexo);
        printf("IMC: %f", (pessoas[i]->peso / (pessoas[i]->altura * pessoas[i]->altura)));
    }
}