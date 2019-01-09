/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 06/09/17
    Lista 5, Exercício: 3
*/

#include <stdio.h>

int verificar(int n, char *num) {
    int a = 0, i, j = 2;
    for(i = n - 1; i > -1; i--) a += ((int)num[i] - 48) * j++;
    a = 11 - (a%11);
    if(a == ((int)num[n + 1] - 48)) {
        return 1;
    } else {
        return 0;;
    }
}

void main() {
    int n;
    char num[100];
    printf("Insira o tamanho do numero a ser checado: ");
    scanf("%d", &n);
    printf("Insira o numero com digito verificador:\n");
    scanf("%s", num);
    (verificar(n, num)) ? printf("Correto!\n") : printf("Incorreto!\n");
}