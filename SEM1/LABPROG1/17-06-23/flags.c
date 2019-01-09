#include "stdio.h"

#define CONTEINER    1
#define MOVIVEL      2
#define ACUMULAVEL   4
#define COLETAVEL    8
#define ARREMESSAVEL 16

void main() {
    int status = 0, opcao;
    // printf("Status do objeto:\nConteiner: %s\nMovivel: %s\nAcumulavel: %s\nColetavel: %s\nArremessavel: %s\n",
    //     ((status & CONTEINER) ? "TRUE" : "FALSE"),
    //     ((status & MOVIVEL) ? "TRUE" : "FALSE"),
    //     ((status & ACUMULAVEL) ? "TRUE" : "FALSE"),
    //     ((status & COLETAVEL) ? "TRUE" : "FALSE"),
    //     ((status & ARREMESSAVEL) ? "TRUE" : "FALSE"));
    printf("Deseja executar qual operacao?\n1 - Verificar por flags\n2 - Ativar flags\n3 - Desativar flags\n4 - Resetar todas as flags\n");
    scanf("%d", &opcao);
    
}