#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limite_x, limite_y;

int redondo_x(int a) {
    if(a < 0) {
        return (limite_x - 1);
    } else if(a > (limite_x - 1)) {
        return 0;
    } else {
        return a;
    }
}

int redondo_y(int a) {
    if(a < 0) {
        return (limite_y - 1);
    } else if(a > (limite_y - 1)) {
        return 0;
    } else {
        return a;
    }
}

void main() {
    FILE *arquivo;
    char nome_arquivo[100];
    int vivo, i, j, universo[100][100], paralelo[100][100], vizinho, opcao = 1, x, y;
    system("clear");
    do {
        printf("Insira o nome do arquivo: ");
        scanf("%[^\n]", nome_arquivo);
        if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
            nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
        }
        printf("\n");
        arquivo = fopen(nome_arquivo, "r");
        if(!arquivo) printf("Erro na abertura do arquivo!\n");
    } while(!arquivo);
    fscanf(arquivo, "%d %d", &limite_y, &limite_x);
    for(i = 0; i < limite_x; i++) {
        for(j = 0; j < limite_y; j++) {
            universo[i][j] = 0;
            paralelo[i][j] = 0;
        }
    }
    fscanf(arquivo, "%d", &vivo);
    for(i = 0; i < vivo; i++) {
        fscanf(arquivo, "%d %d", &y, &x);
        universo[x][y]++;
    }
    fclose(arquivo);
    do {
        for(i = 0; i < limite_x; i++) {
            for(j = 0; j < limite_y; j++) {
                printf("%d", universo[i][j]);
            }
            printf("\n");
        }
        for(i = 0; i < limite_x; i++) {
            for(j = 0; j < limite_y; j++) {
                vizinho = 0;
                if(universo[i][redondo_y(j - 1)]) vizinho++;
                if(universo[i][redondo_y(j + 1)]) vizinho++;
                if(universo[redondo_x(i - 1)][j]) vizinho++;
                if(universo[redondo_x(i + 1)][j]) vizinho++;
                if(universo[redondo_x(i - 1)][redondo_y(j - 1)]) vizinho++;
                if(universo[redondo_x(i - 1)][redondo_y(j + 1)]) vizinho++;
                if(universo[redondo_x(i + 1)][redondo_y(j - 1)]) vizinho++;
                if(universo[redondo_x(i + 1)][redondo_y(j + 1)]) vizinho++;
                if(universo[i][j]) {
                    if(vizinho < 2 || vizinho > 3) {
                        paralelo[i][j] = 0;
                    } else {
                        paralelo[i][j] = 1;
                    }
                } else {
                    if(vizinho == 3) {
                        paralelo[i][j] = 1;
                    } else {
                        paralelo[i][j] = 0;
                    }
                }
            }
        }
        do {
            printf("\nEscolha sua proxima acao\n");
            printf("1 - Ver a proxima geracao\n");
            printf("2 - Salvar a geracao atual\n");
            printf("3 - Encerrar o programa\n> ");
            scanf("%d", &opcao);
            if(opcao == 2) {
                printf("\nInsira o nome do arquivo que deseja salvar: ");
                nome_arquivo[0] = '\0';
                getchar();
                scanf("%[^\n]", nome_arquivo);
                if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
                    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
                }
                arquivo = fopen(nome_arquivo, "w+");
                fprintf(arquivo, "%d %d\n", limite_x, limite_y);
                fprintf(arquivo, "%d\n", vivo);
                for(i = 0; i < limite_x; i++) {
                    for(j = 0; j < limite_y; j++) {
                        if(universo[i][j]) fprintf(arquivo, "%d %d\n", i, j);
                    }
                }
                fclose(arquivo); 
            } else if(opcao < 1 || opcao > 3) {
                opcao = 2;
                printf("Opcao Invalida!");
            }
        } while(opcao == 2);
        vivo = 0;
        for(i = 0; i < limite_x; i++) {
            for(j = 0; j < limite_y; j++) {
                universo[i][j] = paralelo[i][j];
                if(paralelo[i][j]) vivo++;
            }
        }
        system("clear");
    } while(opcao == 1);
}