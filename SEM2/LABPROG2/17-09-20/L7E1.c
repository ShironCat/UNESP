/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 20/09/17
    Lista 7, Exercício: 1
*/

#include <stdio.h>
#include <string.h>

int BoyerMoore(char *a, char *b) {
    int i, j, k, alfabeto[256], ocorre = 0, m = strlen(a), n = strlen(b);
    for(i = 0; i < 256; i++) alfabeto[i] = -1;
    for(i = 0; i < m; i++) alfabeto[a[i]] = i;
    k = m - 1;
    while(k <= n) {
        i = m - 1;
        j = k;
        while(i >= 0 && a[i] == b[j]) {
            i--;
            j--;
        }
        if(i < 0) ocorre++;
        k = k + m - alfabeto[b[k+1]];
        }
    return ocorre;
}

void main() {
    char texto[1000], palavra[100];
    printf("Insira um texto:\n");
    fgets(texto, 1000, stdin);
    printf("Insira a palavra a ser buscada no texto:\n");
    scanf("%s", palavra);
    printf("A palavra \"%s\" aparece %d veze(s) no texto.\n", palavra, BoyerMoore(palavra, texto));
}