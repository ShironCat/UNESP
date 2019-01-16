/*      Luiza Torello Vieira e Victor Azadinho Miranda      ||      ED2

        Implemente o algoritmo de intercalação balanceada de vários caminhos. O programa deve ordenar 
    valores inteiros entre 0 e 999 presentes em um arquivo texto. Existem 6 fitas magnéticas disponí-
    veis que serão simuladas como um arquivo texto. O tamanho da área interna de ordenação deve ser
    de livre escolha do usuário.

        Os estados das fitas devem ser salvos em arquivos-texto, cada um representando uma das 6 fitas
    (além de um arquivo inicial com os dados desordenados). A cada intercalação, a ordenação deve ser
    temporariamente interrompida para que seja possível visualizar o estado dos arquivos das fitas. Ao
    final, deve estar disponível um arquivo texto com todos os valores ordenados.

    Entrega: 06/02/2019
*/
#include <stdio.h>
#include <stdlib.h>

void WriteInFile ( FILE *archive, FILE *tape ) {
    int aux;
    for ( int i = 0; i < 3; i++ ) {
        if ( feof(archive) == 0 ) {
            fscanf( archive," %d ", &aux );
            fprintf(tape, aux);
        } else
            break;
    }
}

void RadixSort(int internalMemorySize, FILE *tape1, FILE *tape2, FILE *tape3, FILE *tape4) {
    int indexTape1 = 0, indexTape2 = 0, indexTape3 = 0, i;
    char internalMemory[internalMemorySize];
    for(i = 0; i < internalMemorySize, i++)
        internalMemory[i] = '\0';
    while(feof(tape1) == 0 || feof(tape2) == 0 || feof(tape3) == 0) {
    }
}

void main () {
    char file[50];
    int memory;

    printf("\n\n\t\t***Ordenação por Intercalação Balanceada de vários Caminhos***");
    printf("\nMemória interna Disponível: ");
    scanf("%d",&memory);

    printf("\nArquivo a ser Ordenado: ");
    scanf("%s",file);

    FILE *archive = fopen( file, "r");
    if ( archive != NULL ) {
        
        FILE *tape01 = fopen("tape01.txt", "w");
        FILE *tape02 = fopen("tape02.txt", "w");
        FILE *tape03 = fopen("tape03.txt", "w");

        while ( feof(archive) == 0 ) {
            WriteInFile( archive, tape01 );
            WriteInFile( archive, tape02 );
            WriteInFile( archive, tape03 );
        }
        fclose(archive);
    } else 
        printf("\nFalha na Abertura do Arquivo!");    
}