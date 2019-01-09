/*
    Nome: Victor Azadinho Miranda
    Turma: 2
    Compilador: GCC
    Data: 25/10/17
    Lista 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

double Tempo() {
    // return (double) clock()/CLOCKS_PER_SEC;
    return (double) time(NULL);
}

static void Intercala(int p, int q, int r, double v[]) {
    int i, j, k, *w;
    w = malloc((r-p) * sizeof(int));
    i = p;
    j = q;
    k = 0;
    while(i < q && j < r) {
       if (v[i] <= v[j]) {
           w[k++] = v[i++];
       } else {
           w[k++] = v[j++];
       }
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for(i = p; i < r; ++i) v[i] = w[i - p];
    free(w);
}

void MergeSort(int p, int r, double v[], double *ti, double *tf, double duracao) {
    if(*ti == -1) {
        *ti = Tempo();
    } else {
        *tf = Tempo();
    }
    if(((*tf) - (*ti)) > duracao) return;
    if(p < r-1) {
        int q = (p + r) / 2;
        MergeSort(p, q, v, ti, tf, duracao);
        MergeSort(q, r, v, ti, tf, duracao);
        Intercala(p, q, r, v);
     }
}

int Separa(int v[], int p, int r) {
    int c = v[p], i = (p + 1), j = r, t;
    while(i <= j) {
       if(v[i] <= c) {
           ++i;
       } else if(c < v[j]) {
           --j; 
       } else {
          t = v[i], v[i] = v[j], v[j] = t;
          ++i; --j;
       }
    }
    v[p] = v[j], v[j] = c;
    return j;
}

void QuickSort(int v[], int p, int r) {
    int j;
    if (p < r) {
       j = Separa(v, p, r);
       QuickSort(v, p, j-1);
       QuickSort(v, j+1, r);
    }
}

void main() {
    int n, i, opcao;
    double duracao, tempoinicial = -1, tempofinal, tempototal;
    printf("Forneca o tempo maximo que o programa devera executar: ");
    scanf("%lf", &duracao);
    printf("Duracao dos testes = %.2f segundos\n", duracao);
    printf("Insira o tamanho do vetor:\n");
    scanf("%d", &n);
    double v[n];
    printf("Escolha o algoritmo a ser utilizado:\n");
    printf("Mergesort <1>\n");
    printf("Quicksort <2>\n");
    scanf("%d", &opcao);
    for(i = 0; i < n; i++) v[i] = (double) INT_MAX * rand() / (RAND_MAX + 1.0);
    switch(opcao) {
        case 1:
            printf("Mergesort:\n");
            MergeSort(0, n, v, &tempoinicial, &tempofinal, duracao);
            tempototal = tempofinal - tempoinicial;
            if(tempototal > duracao) {
                printf("A funcao estorou o tempo limite: %lf\n", tempototal);
                printf("%lf %lf\n", tempoinicial, tempofinal);
            } else {
                for(i = 0; i < n; i++) printf("%lf\n", v[i]);
                printf("Tempo gasto: %lf\n", tempototal);
                printf("%lf %lf\n", tempoinicial, tempofinal);
            }
            break;
        case 2:
            printf("Quicksort:\n");
            break;
    }
}