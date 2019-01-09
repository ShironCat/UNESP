//Nome: Victor Azadinho Miranda
//Turma: 2
//Compilador: GCC
//Data: 16/08/17
//Lista: 2, Exercicio: 5

#include <stdio.h>

char conceito(float nota) {
    if(nota >= 0 && nota <= 4.9) {
        return 'D';
    } else if(nota >= 5 && nota <= 6.9) {
        return 'C';
    } else if(nota >= 7 && nota <= 8.9) {
        return 'B';
    } else if(nota >= 9 && nota <= 10) {
        return 'A';
    }
}