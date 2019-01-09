//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 23/08/17
//Lista: 3, Número do exercício: 5

#include <stdio.h>

void subsequencias(int n, int *m) {
    int i;
    printf("As subsequencias de m sao:\n");
    printf("%d", *m);
    for(i = 1; i < n; i++) {
        if(*(m + i) >= *(m + i - 1)) {
            printf(" %d", *(m + i));
        } else {
            printf("\n%d", *(m + i));
        }
    }
    printf("\n");
}

void main() {
    int n, m[100], i;
    printf("Insira o tamanho do vetor m: ");
    scanf("%d", &n);
    printf("Insira os valores do vetor m:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }
    subsequencias(n, m);
}