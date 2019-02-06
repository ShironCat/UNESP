#include <stdio.h>

void main() {
    int numero, contador = 0;
    char nomeArquivo[50];
    FILE *arquivo;
    scanf("%s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    while(!feof(arquivo)) {
        fscanf(arquivo, "%d ", &numero);
        contador++;
    }
    printf("%d\n", contador);
}