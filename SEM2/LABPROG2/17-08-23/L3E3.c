//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 23/08/17
//Lista: 3, Número do exercício: 3

#include <stdio.h>

void intercalacao(int *a, int *b, int *c, int *n) {
    int i, *d;
    d = *c;
    for(i = 0; i < (*n * 2); i++) {
        if(*(a + i) >= *(b + i)) {
            *d++ = *(b + i);
            *d++ = *(a + i);
        } else {
            *d++ = *(a + i);
            *d++ = *(b + i);
        }
    }
}

void main() {
    int a[100], b[100], c[200], i, n;
    printf("Insira o tamanho dos vetores a e b: ");
    scanf("%d", &n);
    printf("Insira os valores do vetor a: ");
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Insira os valores do vetor b: ");
    for(i = 0; i < n; i++) scanf("%d", &b[i]);
    intercalacao(a, b);
    printf("Vetor c:\n");
    for(i = 0; i < (n * 2); i++) printf("%d ", c[i]);
    printf("\n");
}