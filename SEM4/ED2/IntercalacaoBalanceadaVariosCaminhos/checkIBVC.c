#include <stdio.h>

void main() {
    int numero[2] = {0, 0}, contador = 0, ordenado = 1;
    char nomeArquivo[50];
    FILE *arquivo;
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    while(!feof(arquivo)) {
        fscanf(arquivo, "%d ", &numero[1]);
        contador++;
        if(numero[1] >= numero[0])
            numero[0] = numero[1];
        else
            ordenado = 0;
    }
    printf("%d %d\n", contador, ordenado);
}