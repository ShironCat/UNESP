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
/* void WriteInFile(FILE *archive, FILE *tape, int internalMemorySize) {
    int index;
    char letter;
    //Lê o arquivo até o fim da memória interna
    for(index = 0; index < internalMemorySize; index++) {
        if(!feof(archive)) {
            fscanf(archive,"%c", &letter);
            fprintf(tape, "%c", letter);
        } else
            break;
    }
} */

void swapInt(int *number1, int *number2) {
    int auxNumber;
    auxNumber = *number1;
    *number1 = *number2;
    *number2 = auxNumber;
}

void IBVC_Part1(int *internalMemory, int internalMemorySize, FILE *archive, FILE *tape1, FILE *tape2, FILE *tape3) {
    int index, indexOrdering, indexBlock = 0;
    FILE *outTape;
    do {
        switch(indexBlock) {
            case 1:
                outTape = tape2;
                break;
            case 2:
                outTape = tape3;
                break;
            default:
                outTape = tape1;
                indexBlock = 0;
        }
        for(index = 0; index < internalMemorySize; index++) {
            if(!feof(archive))
                fscanf(archive, "%c ", internalMemory[index]);
            else
                internalMemory[index] = 255;
            for(indexOrdering = index; indexOrdering > 0; indexOrdering--) {
                if(indexOrdering > 0)
                    if(internalMemory[indexOrdering] < internalMemory[(indexOrdering - 1)])
                        swapInt(&internalMemory[indexOrdering], &internalMemory[(indexOrdering - 1)]);
            }
        }
        for(index = 0; index < internalMemorySize; index++) {
            if(internalMemory[index] < 255)
                fprintf(outTape, "%c", internalMemory[index]);
        }
        indexBlock++;
    } while(!feof(archive));
}

void IBVC_Part2(int internalMemorySize, FILE *tape1, FILE *tape2, FILE *tape3, FILE *tape4, FILE *tape5, FILE *tape6) {
    int index, indexTape1, indexTape2, indexTape3, indexTape4 = 0, indexTape5 = 0, indexTape6 = 0, indexBlock = 0;
    char internalMemory[internalMemorySize];
    FILE *auxTape, *outTape;
    for(index = 0; index < internalMemorySize; index++)
        internalMemory[index] = '\0';
    while(!feof(tape1) || !feof(tape2) || !feof(tape3)) {
        indexTape1 = indexTape2 = indexTape3 = 0;
        indexBlock++;
        switch(indexBlock) {
            case 1:
                outTape = tape4;
                break;
            case 2:
                outTape = tape5;
                break;
            case 3:
                outTape = tape6;
                break;
            default:
                printf("Limite de fitas atingido\n");
        }
        if(!feof(tape1))
            fscanf(tape1, "%c", internalMemory[0]);
        else
            internalMemory[0] = 255;
        if(!feof(tape2))
            fscanf(tape2, "%c", internalMemory[1]);
        else
            internalMemory[1] = 255;
        if(!feof(tape3))
            fscanf(tape3, "%c", internalMemory[2]);
        else
            internalMemory[2] = 255;
        do {
            if(internalMemory[0] <= internalMemory[1]) {
                if(internalMemory[0] <= internalMemory[2]) {
                    fprintf(outTape, "%c", internalMemory[0]);
                    if(indexTape1 < (internalMemorySize * indexBlock - 1)) {
                        fscanf(tape1, "%c", internalMemory[0]);
                        indexTape1++;
                    } else
                        internalMemory[0] = 255;
                    
                } else {
                    fprintf(outTape, "%c", internalMemory[2]);
                    if(indexTape3 < (internalMemorySize * indexBlock - 1)) {
                        fscanf(tape3, "%c", internalMemory[2]);
                        indexTape3++;
                    } else
                        internalMemory[2] = 255;
                }
            } else {
                if(internalMemory[1] <= internalMemory[2]) {
                    fprintf(outTape, "%c", internalMemory[1]);
                    if(indexTape2 < (internalMemorySize * indexBlock - 1)) {
                        fscanf(tape2, "%c", internalMemory[1]);
                        indexTape2++;
                    } else
                        internalMemory[1] = 255;
                } else {
                    fprintf(outTape, "%c", internalMemory[2]);
                    if(indexTape3 < (internalMemorySize * indexBlock - 1)) {
                        fscanf(tape3, "%c", internalMemory[2]);
                        indexTape3++;
                    } else
                        internalMemory[2] = 255;
                }
            }
        } while(indexTape1 < (internalMemorySize * indexBlock) || indexTape2 < (internalMemorySize * indexBlock) || indexTape3 < (internalMemorySize * indexBlock));
    }
}

//Imprime o conteúdo das fitas magnéticas
void PrintTapes( FILE *tape, char tapeName[10] ) {
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

void main () {
    char fileName[50];
    int internalMemorySize;
    //Leitura do tamanho da memória interna
    printf("\n\n\t\t***Ordenação por Intercalação Balanceada de vários Caminhos***");
    printf("\nMemória interna Disponível: ");
    scanf("%d", &internalMemorySize);
    //Leitura do nome do arquivo
    printf("\nArquivo a ser Ordenado: ");
    scanf("%s", fileName);

    FILE *archive = fopen(fileName, "r");
    //Se a abertura do arquivo foi realizada com sucesso
    if(archive != NULL) {
        //Declaração das fitas magnéticas
        FILE *tape01 = fopen("tape01.txt", "w");
        FILE *tape02 = fopen("tape02.txt", "w");
        FILE *tape03 = fopen("tape03.txt", "w");
        //Enquanto o conteúdo do arquivo não acabar
        while(!feof(archive)) {
            //Passa o conteúdo do arquivo para as fitas
            WriteInFile(archive, tape01, internalMemorySize);
            WriteInFile(archive, tape02, internalMemorySize);
            WriteInFile(archive, tape03, internalMemorySize);
        }
        //Fecha os arquivos
        fclose(tape01); fclose(tape02); fclose(tape03); fclose(archive);
        //Imprime as fitas
        PrintTapes( tape01, "tape01.txt" );
        PrintTapes( tape02, "tape02.txt" );
        PrintTapes( tape03, "tape03.txt" );

    //A abertura do arquivo não foi realizada com sucesso
    } else 
        printf("\nFalha na Abertura do Arquivo!");
}