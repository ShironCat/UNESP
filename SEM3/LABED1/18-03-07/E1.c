#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[150], matricula[20];
    float nota1, nota2;
} aluno;

aluno *cadastraAluno() {
    aluno *novo;
    novo = (aluno*)malloc(sizeof(aluno));
    printf("Insira o nome do aluno: ");
    fgets(novo->nome, 150, stdin);
    printf("Insira a matricula do aluno: ");
    getchar();
    fgets(novo->matricula, 20, stdin);
    printf("Insira a primeira nota do aluno: ");
    scanf("%f", &novo->nota1);
    printf("Insira a segunda nota do aluno: ");
    scanf("%f", &novo->nota2);
    return novo;
}

void main() {
    int i;
    aluno *alunos[5];
    printf("Medias de 5 alunos\n");
    for(i = 0; i < 5; i++) alunos[i] = cadastraAluno();
    printf("Medias:\n");
    for(i = 0; i < 5; i++) {
        printf("%s - Media: %g\n", alunos[i]->nome, ((alunos[i]->nota1 + alunos[i]->nota2) / 2));
    }
}