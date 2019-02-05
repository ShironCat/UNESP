/*      Luiza Torello Vieira, Victor Azadinho Miranda e Victor Cipolato     ||      ED2

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

void swapInt(int *number1, int *number2) {
    int auxNumber;
    auxNumber = *number1;
    *number1 = *number2;
    *number2 = auxNumber;
}

void bubble_sort (int *internalMemory, int *originalTape, int n) {
    int k, j, aux;

    for (k = 1; k < n; k++)
        for (j = 0; j < n - 1; j++)
            if (internalMemory[j] > internalMemory[j + 1]) {
                swapInt( &internalMemory[j], &internalMemory[j + 1] );
                swapInt( &originalTape[j], &originalTape[j + 1] );
            }
}

void IBVC_Part1( int internalMemorySize, FILE *archive, FILE *tape[] ) {
    int internalMemory[internalMemorySize], index, indexOrdering, indexBlock = 0;
    FILE *outTape;
    for(index = 0; index < internalMemorySize; index++)
        internalMemory[index] = 1000;
    while(!feof(archive)) {
        switch(indexBlock) {
            case 1:
                outTape = tape[1];//Fita 2
                break;
            case 2:
                outTape = tape[2];//Fita 3
                break;
            default:
                outTape = tape[0];//Fita 1
                indexBlock = 0;
        }
        for(index = 0; index < internalMemorySize; index++) {
            if(!feof(archive)){
                fscanf(archive, "%d ", &internalMemory[index]);
            }
            else
                internalMemory[index] = 1000;
            for(indexOrdering = index; indexOrdering > 0; indexOrdering--) {
                if(indexOrdering > 0)
                    if(internalMemory[indexOrdering] < internalMemory[(indexOrdering - 1)])
                        swapInt(&internalMemory[indexOrdering], &internalMemory[(indexOrdering - 1)]);
            }
        }
        for(index = 0; index < internalMemorySize; index++) {
            if(internalMemory[index] < 1000)
                fprintf(outTape, "%d ", internalMemory[index]);
        }
        indexBlock++;
    }
}

void IBVC_Part2( int internalMemorySize, FILE *tape[] ) {
    int internalMemory[internalMemorySize], originalTape[internalMemorySize];
    int indexTape[3] = { 0, 0, 0 }, indexBlock = 0, index;
    FILE *outTape, *inTape;
    //Volta ao início dos arquivos
    for ( index = 0; index < 6; index++ )
        fseek(tape[ index ], 0, SEEK_SET);
    //Preenchimento da memória interna com valor 'impossivel'
    for(index = 0; index < internalMemorySize; index++) {
        internalMemory[index] = 1000;
        originalTape[index]   = 3;
    }
    //Enquanto alguma fita ainda tiver conteúdo, realiza o laço
    while(!feof(tape[0]) || !feof(tape[1]) || !feof(tape[2])) {
        // Zera os indices das fitas
        for ( index = 0; index < 3; index++ ) 
            indexTape[index] = 0;
        //Seleção da fita a ser escrita na 'passada'
        indexBlock++;
        switch(indexBlock) {
            case 1:
                outTape = tape[3];
                break;
            case 2:
                outTape = tape[4];
                break;
            case 3:
                outTape = tape[5];
                break;
            default:
                printf("Limite de fitas atingido\n");
        }
        for ( index = 0; index < internalMemorySize; index++ ) {
            //Preenchimento da memória interna com o conteúdo das fitas (ou 1000 caso a fita esteja vazia)
            //Fita 1
            if( !feof(tape[0]) ) {
                fscanf(tape[0], "%d ", &internalMemory[index]);
                originalTape[index++] = 0;
            } else
                internalMemory[index++] = 1000;
            //Fita 2
            if(!feof(tape[1]) && index < internalMemorySize ) {
                fscanf(tape[1], "%d ", &internalMemory[index]);
                originalTape[index++] = 1;
            }else
                internalMemory[index++] = 1000;
            //Fita 3
            if(!feof(tape[2]) && index < internalMemorySize ) {
                fscanf(tape[2], "%d ", &internalMemory[index]);
                originalTape[index++] = 2;
            } else
                internalMemory[index++] = 1000;
        }
        do {
            //Ordenação da memória interna
            bubble_sort( internalMemory, originalTape, internalMemorySize );
            if ( internalMemory[0] < 1000 ) {
                fprintf( outTape, "%d ", internalMemory[0] ); //Escreve no arquivo o menor valor
                indexTape[originalTape[0]]++;//Incrementa a qtd de vezes que a fita foi 'escolhida'
                index = originalTape[0];
                //Caso a fita tenha escrito até o seu 'limite', pega uma outra fita para completar
                if ( indexTape[originalTape[0]] == internalMemorySize ) {
                    if ( indexTape[0] < internalMemorySize ) {
                        inTape = tape[0];
                        index = 0;
                    } else if ( indexTape[1] < internalMemorySize ){
                        inTape = tape[1];
                        index = 1;
                    } else if ( indexTape[2] < internalMemorySize  ){
                        inTape = tape[2];
                        index = 2;
                    } else 
                        internalMemory[0] = 1000;
                //Preenche a memória interna com a fita da qual foi retirada a 
                } else switch ( originalTape[0] ) {
                        case 0:
                            inTape = tape[0];
                        break;
                        case 1:
                            inTape = tape[1];
                        break;
                        case 2:
                            inTape = tape[2];
                        break;
                    }
                if ( !feof(inTape) )
                    fscanf( inTape, "%d ", &internalMemory[0] );//Armazena na última posição do vetor
                else
                    internalMemory[0] = 1000;
                originalTape[0] = index;
            }
        } while( indexTape[0] < internalMemorySize && indexTape[1] < internalMemorySize && indexTape[2] < internalMemorySize );
        for ( index = 1; index < internalMemorySize; index++ )
            if ( internalMemory[index] < 1000 )
                fprintf( outTape, "%d ", internalMemory[index] );
    }
}

/*void IBVC_Part3(int internalMemorySize, FILE *tape1, FILE *tape4, FILE *tape5, FILE *tape6) {
    int internalMemory[internalMemorySize], index;
    fseek(tape1, 0, SEEK_SET);
    fseek(tape4, 0, SEEK_SET);
    fseek(tape5, 0, SEEK_SET);
    fseek(tape6, 0, SEEK_SET);
    for(index = 0; index < internalMemorySize; index++)
        internalMemory[index] = 1000;
    while(!feof(tape4) || !feof(tape5) || !feof(tape6)) {
        if(!feof(tape4))
            fscanf(tape4, "%d ", &internalMemory[0]);
        else
            internalMemory[0] = 1000;
        if(!feof(tape5))
            fscanf(tape5, "%d ", &internalMemory[1]);
        else
            internalMemory[1] = 1000;
        if(!feof(tape6))
            fscanf(tape6, "%d ", &internalMemory[2]);
        else
            internalMemory[2] = 1000;
        if(internalMemory[0] <= internalMemory[1]) {
            if(internalMemory[0] <= internalMemory[2]) {
                fprintf(tape1, "%d ", internalMemory[0]);
                if(!feof(tape4))
                    fscanf(tape4, "%d ", &internalMemory[0]);
                else
                    internalMemory[0] = 1000;
            } else {
                fprintf(tape1, "%d ", internalMemory[2]);
                if(!feof(tape6))
                    fscanf(tape6, "%d ", &internalMemory[2]);
                else
                    internalMemory[2] = 1000;
            }
        } else {
            if(internalMemory[1] <= internalMemory[2]) {
                fprintf(tape1, "%d ", internalMemory[1]);
                if(!feof(tape5))
                    fscanf(tape5, "%d ", &internalMemory[1]);
                else
                    internalMemory[1] = 1000;
            } else {
                fprintf(tape1, "%d ", internalMemory[2]);
                if(!feof(tape6))
                    fscanf(tape6, "%d ", &internalMemory[2]);
                else
                    internalMemory[2] = 1000;
            }
        }
    }
}*/

//Imprime o conteúdo das fitas magnéticas
void PrintTape(FILE *tape, int tapenumber) {
    int auxNumber;
    fseek(tape, 0, SEEK_SET);
    printf("Fita numero %d: ", tapenumber);
    while(!feof(tape)) {
        fscanf(tape, "%d ", &auxNumber);
        printf("%d ", auxNumber);
    }
    printf("\n");
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
    getchar();

    FILE *archive = fopen(fileName, "r");
    //Se a abertura do arquivo foi realizada com sucesso
    if(archive != NULL) {
        //Declaração das fitas magnéticas
        FILE *tape[6];
        tape[0] = fopen("tape01.txt", "w+");
        tape[1] = fopen("tape02.txt", "w+");
        tape[2] = fopen("tape03.txt", "w+");
        tape[3] = fopen("tape04.txt", "w+");
        tape[4] = fopen("tape05.txt", "w+");
        tape[5] = fopen("tape06.txt", "w+");
        
        //Primeira parte da ordena��o externa
        IBVC_Part1( internalMemorySize, archive, tape );
        printf("\nRealizada a passagem do arquivo para as fitas 1, 2 e 3: \n");
        //Imprime as fitas apos a primeira parte da ordenacao
        PrintTape( tape[0], 1);
        PrintTape( tape[1], 2);
        PrintTape( tape[2], 3);
        printf("\nPressione ENTER para continuar");
        getchar();
        
        //Segunda parte da ordena��o externa
        IBVC_Part2(internalMemorySize, tape );
        printf("\nRealizada a passagem das fitas 1, 2 e 3 para as fitas 4, 5 e 6: \n");
        //Imprime as fitas apos a segunda parte
        PrintTape( tape[3], 4);
        PrintTape( tape[4], 5);
        PrintTape( tape[5], 6);
        printf("\nPressione ENTER para continuar");
        getchar();
        
        //Terceira e �ltima parte da ordena��o externa, o arquivo estara ordenado na tape01
        IBVC_Part2(internalMemorySize, tape );
        printf("\nOrdenação finalizada: \n");
        //Imprime as fitas apos o fim da ordencacao, como dito anteriormente, a fita estara com o conteudo ordenado
        PrintTape( tape[0], 1);
        /*PrintTape( tape02, 2);
        PrintTape( tape03, 3);
        PrintTape( tape04, 4);
        PrintTape( tape05, 5);
        PrintTape( tape06, 6);*/
        printf("\nPressione ENTER para continuar");
        getchar();
        //Fecha os arquivos
        for ( int index = 0; index < 6; index++ )
            fclose(tape[index]);
    //A abertura do arquivo não foi realizada com sucesso
    } else 
        printf("\nFalha na Abertura do Arquivo!");
}
