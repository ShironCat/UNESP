#include <stdio.h>

void main() {
    int valor, *p1, idade, vetor[3], *p4, *p5;
    float temp, *p2;
    char aux, *nome = "Algoritmos", *p3;
    /* (a) */
    valor = 10;
    p1 = &valor;
    *p1 = 20;
    printf("(a) %d\n", valor);
    /* (b) */
    temp = 26.5;
    p2 = &temp;
    *p2 = 29.0;
    printf("(b) %.1f\n", temp);
    /* (c) */
    p3 = &nome[0];
    aux = *p3;
    printf("(c) %c\n", aux);
    /* (d) */
    p3 = &nome[4];
    aux = *p3;
    printf("(d) %c\n", aux);
    /* (e) */
    p3 = nome;
    printf("(e) %c\n", *p3);
    /* (f) */
    p3 = p3 + 4;
    printf("(f) %c\n", *p3);
    /* (g) */
    p3--;
    printf("(g) %c\n", *p3);
    /* (h) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;
    idade = *p4;
    printf("(h) %d\n", idade);
    /* (i) */
    p5 = p4 + 1;
    idade = *p5;
    printf("(i) %d\n", idade);
}