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

int HasContent ( FILE *archieve ) {
    int auxContent = 1000;
    if ( !feof(archieve) )
        fscanf( archieve, "%d ", &auxContent );
    return auxContent;
}

void IBVC_Part1( int internalMemorySize, FILE *archive, FILE *tape[] ) {
    int internalMemory[internalMemorySize], index, indexOrdering, indexBlock = 0;
    FILE *outTape;
    for(index = 0; index < internalMemorySize; index++)
        internalMemory[index] = 1000;
    while(!feof(archive)) {
        if ( indexBlock > 2 || (internalMemorySize == 2 && indexBlock > 1))
            indexBlock = 0;
        outTape = tape[ indexBlock ];
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

int NormalizeIndex(int index) {
    while(index >= 3)
        index -= 3;
    return index;
}

int IndexLowestNumber(int *internalMemory, int internalMemorySize) {
    int index, indexLowestNumber = 0;
    for(index = 1; index < internalMemorySize; index++)
        if(internalMemory[index] < internalMemory[indexLowestNumber])
            indexLowestNumber = index;
    return indexLowestNumber;
}

int EmptyMemory(int *internalMemory, int internalMemorySize) {
    int index = -1, isEmpty = 1;
    while(++index < internalMemorySize && isEmpty)
        if(internalMemory[index] < 1000)
            isEmpty = 0;
    return isEmpty;
}

void IBVC_Part2( int internalMemorySize, FILE *tape[6] ) {
    int index, internalMemory[internalMemorySize], indexTape[3], indexBlock = 0, indexLowestNumber, normalizedIndex, stop = 1;
    FILE *outTape;
    //Volta ao início dos arquivos
    for ( index = 0; index < 3; index++ )
        fseek(tape[ index ], 0, SEEK_SET);
    //Preenchimento da memória interna com valor 'impossivel'
    for(index = 0; index < internalMemorySize; index++)
        internalMemory[index] = 1000;
    indexTape[0] = indexTape[1] = indexTape[2] = -1;
    //Enquanto alguma fita ainda tiver conteúdo, realiza o laço
    while(!feof(tape[0]) || !feof(tape[1]) || stop) {
        indexBlock++;
        //Seleção da fita a ser escrita na 'passada'
        if ( indexBlock < 4 ) 
            outTape = tape[ (indexBlock + 2) ];
        else {
            printf("\nLimite de fitas atingido!!!\nA ordenação não pode ser completa, encerrando o programa...\n");
            exit(0);
        }
        index = -1;
        while(++index < internalMemorySize) {
            fscanf(tape[NormalizeIndex(index)], "%d ", &internalMemory[index]);
            indexTape[NormalizeIndex(index)]++;
        }
        do {
            indexLowestNumber = IndexLowestNumber(internalMemory, internalMemorySize);
            normalizedIndex = NormalizeIndex(indexLowestNumber);
            fprintf(outTape, "%d ", internalMemory[indexLowestNumber]);
            if(!feof(tape[normalizedIndex]) && indexTape[normalizedIndex] < (internalMemorySize * indexBlock - 1)) {
                fscanf(tape[normalizedIndex], "%d ", &internalMemory[indexLowestNumber]);
                indexTape[normalizedIndex]++;
            } else
                internalMemory[indexLowestNumber] = 1000;
        } while(!EmptyMemory(internalMemory, internalMemorySize));
        if(internalMemorySize < 3)
            stop = 0;
        else
            stop = !feof(tape[2]);
    }
}

void IBVC_Part3( int internalMemorySize, FILE *tape[] ) {
    int internalMemory[internalMemorySize];
    int indexTape[3], tapeIndex, index, indexLowestNumber, normalizedIndex, tapeCount = 0;
    FILE *outTape, *inTape;
    //Volta ao início dos arquivos
    for ( index = 0; index < 6; index++ )
        rewind( tape[index] );
    //Preenchimento da memória interna com valor 'impossivel'
    for(index = 0; index < internalMemorySize; index++)
        internalMemory[index] = 1000;
    indexTape[0] = indexTape[1] = indexTape[2] = -1;
    //Enquanto alguma fita ainda tiver conteúdo, realiza o laço
    while( !feof(tape[3]) || !feof(tape[4]) || !feof(tape[5]) ) {
        indexTape[0]++;
        indexTape[1]++;
        indexTape[2]++;
        //Preenche a memória interna
        for ( index = 0, tapeIndex = 0; index < internalMemorySize && tapeCount < 3; tapeIndex++, index++ ) {
            internalMemory[index] = HasContent( tape[ NormalizeIndex(tapeIndex) + 3 ] );
            if ( internalMemory[index] == 1000 ) { //Se o conteudo é = 0, refaz a leitura para a próxima leitura
                index--;
                tapeCount++;
            } else
                tapeCount = 0;            
        }
        do {
            indexLowestNumber = IndexLowestNumber(internalMemory, internalMemorySize);
            normalizedIndex = NormalizeIndex(indexLowestNumber) + 3;
            fprintf( tape[0], "%d ", internalMemory[indexLowestNumber]);
            if( !feof(tape[normalizedIndex]) ) {
                fscanf(tape[normalizedIndex], "%d ", &internalMemory[indexLowestNumber]);
                indexTape[normalizedIndex - 3]++;
            } else
                internalMemory[indexLowestNumber] = 1000;
        } while(!EmptyMemory(internalMemory, internalMemorySize));
    }
}

//Imprime o conteúdo das fitas magnéticas
void PrintTape(FILE *tape, int tapenumber) {
    int auxNumber = 1000;
    fseek(tape, 0, SEEK_SET);
    printf("Fita numero %d: ", tapenumber);
    while( !feof(tape) ) {
        fscanf(tape, "%d ", &auxNumber);
        if ( auxNumber != 1000 )
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
        
        //Segunda parte da ordenação externa
        IBVC_Part2(internalMemorySize, tape );
        printf("\nRealizada a passagem das fitas 1, 2 e 3 para as fitas 4, 5 e 6: \n");
        //Imprime as fitas apos a segunda parte
        PrintTape( tape[3], 4);
        PrintTape( tape[4], 5);
        PrintTape( tape[5], 6);
        printf("\nPressione ENTER para continuar");
        getchar();
        
        //Terceira e última parte da ordenação externa, o arquivo estara ordenado na tape01
        IBVC_Part3(internalMemorySize, tape );
        printf("\nOrdenação finalizada: \n");
        //Imprime as fitas apos o fim da ordencacao, como dito anteriormente, a fita estara com o conteudo ordenado
        PrintTape( tape[0], 1);
        printf("\nPressione ENTER para continuar");
        getchar();
        //Fecha os arquivos
        for ( int index = 0; index < 6; index++ )
            fclose(tape[index]);
    //A abertura do arquivo não foi realizada com sucesso
    } else 
        printf("\nFalha na Abertura do Arquivo!");
}
