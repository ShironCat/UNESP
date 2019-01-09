/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 20/09/17
    Lista 7, Exercício: 2
*/

#include <stdio.h>
#include <string.h>

int BoyerMoore(char *a, char *b) {
    int ult[256], m = strlen(a), n = strlen(b);
    for(int i = 0; i < 256; ++i) ult[i] = 0;
    for(int i = 0; i < m; ++i) ult[a[i]] = i;
    int ocorrs = 0, k = m - 1;
    while(k < n) {
        int i = m, j = k;
        while(i >= 0 && a[i] == b[j]) --i, --j;
        if(i < 0) ++ocorrs;
        k += m - ult[b[k]]; /* O motivo para o algoritmo nao funcionar corretamente é a falta de uma
        soma por 1 na variável K nessa linha. Para funcionar o correto seria:
            k += m - ult[b[k    +1   ]];
        */
    }
    return ocorrs;
}

void main() {
    printf("%d\n", BoyerMoore("teste", "teste teste teste")); /* Era esperado que o programa imprimisse
    o número 3, porém ele imprime o número 0. */
}