//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 16/08/17
//Lista: 2, Exercicio: 6

#include <stdio.h>
#include <math.h>

int encaixa(int a, int b) {
    int multiplo, i;
    if(a < b) {
        return 0;
    } else {
        a -= b;
        for(i = 10; i > b; (i * 10));
        if(!(a%i)) {
            return 1;
        } else {
            return 0;
        }
    }
}

void main() {
    int a, b, i, o = -1;
    printf("Insira dois numeros inteiros positivos a e b: ");
    scanf("%d %d", &a, &b);
    if(a > b) {
        for(i = 0; ((int)(a * pow(10, i))) > b; i--) if(encaixa(((int)(a * pow(10, i))), b)) o = 1;
    } else if(b > a) {
        for(i = 1; ((int)(b * pow(10, i))) > a; --i) if(encaixa(((int)(b * pow(10, i))), a)) o = 0;
    }
    if(o != -1) {
        printf("%c e segmento de %c\n", ((o) ? 'b' : 'a'), ((o) ? 'a' : 'b'));
    } else if(a == b) {
        printf("ambos sao segmentos um do outro\n");
    } else {
        printf("um nao e segmento do outro\n");
    }
}