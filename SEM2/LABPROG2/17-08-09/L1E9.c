#include <stdio.h>

int a, n, v[100], i;

void b() {
    for(i = 0; i < n; i++) scanf("%d", &v[i]);
    for(i = 0; i < n; i++) printf("%d\n", v[i]);
}

void c() {
    int *p;
    p = v;
    for(i = 0; i < n; i++) scanf("%d", (p + i));
    for(i = 0; i < n; i++) printf("%d\n", *(p + i));
}

void main() {
    printf("Escolha o metodo desejado:\n0) Indexacao de vetor v[i]\n1) Aritmetica de ponteiros\n> ");
    scanf("%d", &a);
    printf("Insira quantos numeros voce deseja ler(maximo 100): ");
    scanf("%d", &n);
    printf("Insira os numeros do vetor: ");
    (a) ? b() : c();
}