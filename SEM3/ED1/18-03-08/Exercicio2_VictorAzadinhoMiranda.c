#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    char nome[150];
    int idade;
    float nota;
    struct elemento *prox;
} aluno;

aluno *alunoInserir(aluno *topo) {
    aluno *novo;
    novo = (aluno*)malloc(sizeof(aluno));
    printf("Insira o nome do aluno: ");
    getchar();
    scanf("%[^\n]", novo->nome);
    printf("Insira a idade do aluno: ");
    scanf("%d", &novo->idade);
    printf("Insira a nota do aluno: ");
    scanf("%f", &novo->nota);
    printf("\n");
    novo->prox = topo;
    topo = novo;
    return(topo);
}

int alunoCheca(aluno *topo) {
    if(topo == NULL) {
        printf("Nenhum aluno cadastrado!\n\n");
        return(0);
    } else {
        return(1);
    }
}

aluno *alunoRemove(aluno *topo) {
    if(alunoCheca(topo)) {
        aluno *aux = topo;
        topo = topo->prox;
        free(aux);
        printf("Aluno removido com sucesso!\n\n");
        return(topo);
    }
}

aluno *alunoLimpa(aluno *topo) {
    if(alunoCheca(topo)) {
        aluno *aux = topo;
        while(aux != NULL) {
            topo = topo->prox;
            free(aux);
            aux = topo;
        }
        printf("Alunos removidos com sucesso!\n\n");
        return(topo);
    }
}

void alunoConsulta(aluno *topo, int op) {
    if(alunoCheca(topo)) {
        aluno *aux = topo;
        int id = 0;
        if(op) {
            printf("Alunos aprovados:\n\n");
        }
        while(aux != NULL) {
            if(!op || aux->nota >= 5) {
                printf("Nome do aluno: %s\n", aux->nome);
                printf("Idade do aluno: %d\n", aux->idade);
                printf("Nota do aluno: %g\n\n", aux->nota);
                id++;
            }
            aux = aux->prox;
        }
        if(op && id == 0) printf("Nenhum aluno aprovado!\n\n");
    }
}

void alunoMenorNota(aluno *topo) {
    aluno *aux = topo;
    int id = -1, nota = 11, i = 0;
    while(aux != NULL) {
        if(aux->nota < nota) {
            id = i;
        }
        aux = aux->prox;
        i++;
    }
    aux = topo;
    i = 0;
    while(id != i) aux = aux->prox, i++;
    printf("Nome do aluno com a menor nota: %s\n", aux->nome);
    printf("Nota do aluno: %g\n\n", aux->nota);
}

void alunoConsultaUltimo(aluno *topo) {
    printf("Nome do aluno: %s\n", topo->nome);
    printf("Idade do aluno: %d\n", topo->idade);
    printf("Nota do aluno: %g\n\n", topo->nota);
}

void main() {
    aluno *topo = NULL;
    int op = 1, id = 0;
    printf("Controle de alunos\n\n");
    while(op != 0) {
        printf("Escolha uma opcao:\n");
        printf("1 - Cadastrar um aluno\n");
        printf("2 - Exibir ultimo aluno\n");
        printf("3 - Remover ultimo aluno\n");
        printf("4 - Exibir todos os alunos\n");
        printf("5 - Remover todos os alunos\n");
        if(id >= 5) {
            printf("6 - Exibir o aluno com a menor nota\n");
            printf("7 - Exibir alunos aprovados(nota maior ou igual a 5)\n");
        }
        printf("0 - Sair\n");
        printf("> ");
        scanf("%d", &op);
        printf("\n");
        switch(op) {
            case 0: break;
            case 1:
                topo = alunoInserir(topo);
                id++;
                break;
            case 2:
                alunoConsultaUltimo(topo);
                break;
            case 3:
                topo = alunoRemove(topo);
                if(id > 0) id--;
                break;
            case 4:
                alunoConsulta(topo, 0);
                break;
            case 5:
                topo = alunoLimpa(topo);
                id = 0;
                break;
            case 6:
                alunoMenorNota(topo);
                break;
            case 7:
                alunoConsulta(topo, 1);
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
    }
}