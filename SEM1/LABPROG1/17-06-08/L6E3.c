#include "stdio.h"

void main() {
    int x;
    float ponto[10], media = 0, resultado = 0;
    printf("Insira 10 valores:\n");
    for(x = 0; x < 10; x++) {
        scanf("%f", &ponto[x]);
        media += ponto[x];
    }
    media /= 10;
    for(x = 0; x < 10; x++ ) {
        resultado += (ponto[x] - media) * (ponto[x] - media);
    }
    printf("Media: %.2f\nVariancia: %.2f\n", media, resultado);
}