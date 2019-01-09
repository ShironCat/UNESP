/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 18/10/17
    Lista 8, Exercício: 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void GerarVetorAleatoriamente(int n, int v[]) {
    int i;
    double numero;
    numero = (double) INT_MAX*rand()/(RAND_MAX + 1.0);
    for(i = 0; i < n; i++) v[i] = numero[i];
}

void main() {
    int n, v[100], i;
    printf("Insira o tamanho desejado para o vetor(maximo 100): ");
    scanf("%d", &n);
    GerarVetorAleatoriamente(n, v);
    for(i = 0; i < n; i++) printf("%d", v[i]);
}