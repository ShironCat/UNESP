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

//Passa o conteúdo do arquivo para uma fita magnética
void WriteInFile ( FILE *archive, FILE *tape, int internalMemorySize ) {
    char aux;
    //Lê o arquivo até o fim da memória interna
    for ( int i = 0; i < internalMemorySize; i++ ) {
        if ( feof(archive) == 0 ) {
            fscanf( archive," %c ", &aux );
            fprintf(tape, " %c ", aux);
        } else
            break;
    }
}
//Imprime o conteúdo das fitas magnéticas
void PrintTapes( FILE *tape, char tapeName[50] ) {
    char aux;
    tape = fopen(tapeName, "r");
    if ( tape != NULL ) {
        printf("\n%s: ", tapeName );
        while ( feof(tape) == 0 ) {
            fscanf( tape," %c ", &aux );
            printf(" %c ", aux);
        }
        fclose(tape);
    } else 
        printf("\nFalha na abertura do arquivo!");
}

void RadixSort(int internalMemorySize, FILE *arquive, FILE *tape1, FILE *tape2, FILE *tape3, FILE *tape4, FILE *tape5, FILE *tape6) {
    int indexTape1 = 0, indexTape2 = 0, indexTape3 = 0, i;
    char internalMemory[internalMemorySize];
    for(i = 0; i < internalMemorySize; i++)
        internalMemory[i] = '\0';
    while(feof(tape1) == 0 || feof(tape2) == 0 || feof(tape3) == 0) {
    }
}

void main () {
    char file[50];
    int internalMemorySize;
    //Leitura do tamanho da memória interna
    printf("\n\n\t\t***Ordenação por Intercalação Balanceada de vários Caminhos***");
    printf("\nMemória interna Disponível: ");
    scanf("%d",&internalMemorySize);
    //Leitura do nome do arquivo
    printf("\nArquivo a ser Ordenado: ");
    scanf("%s",file);

    FILE *archive = fopen( file, "r");
    //Se a abertura do arquivo foi realizada com sucesso
    if ( archive != NULL ) {
        //Declaração das fitas magnéticas
        FILE *tape01 = fopen("tape01.txt", "w");
        FILE *tape02 = fopen("tape02.txt", "w");
        FILE *tape03 = fopen("tape03.txt", "w");
        //Enquanto o conteúdo do arquivo não acabar
        while ( feof(archive) == 0 ) {
            //Passa o conteúdo do arquivo para as fitas
            WriteInFile( archive, tape01, internalMemorySize );
            WriteInFile( archive, tape02, internalMemorySize );
            WriteInFile( archive, tape03, internalMemorySize );
        }
        //Fecha os arquivos
        fclose(tape01); fclose(tape02); fclose(tape03); fclose(archive);
        //Imprime as fitas
        PrintTapes( tape01, "tape01.txt" );
        PrintTapes( tape01, "tape01.txt" );
        PrintTapes( tape01, "tape01.txt" );

    //A abertura do arquivo não foi realizada com sucesso
    } else 
        printf("\nFalha na Abertura do Arquivo!");
}