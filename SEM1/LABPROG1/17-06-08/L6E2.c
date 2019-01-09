#include "stdio.h"
#include "string.h"

void main() {
    char user[5], pw[7];
    printf("Insira seu nome de usuario: ");
    scanf("%s", user);
    printf("Insira sua senha: ");
    scanf("%s", pw);
    if(0 == strcmp(user, "Jose") && 0 == strcmp(pw, "1234abc")) {
        printf("Usuario \"Jose\" logado com sucesso!\n");
    } else if(0 == strcmp(user, "Maria") && 0 == strcmp(pw, "1bccd")) {
        printf("Usuario \"Maria\" logado com sucesso!\n");
    } else {
        printf("Usuario e/ou senha invalido(s)!\n");
    }
}