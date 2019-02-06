#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int index, quantidade;
	FILE *arquivo = fopen("arquivo.txt", "w");
	srand(time(NULL));
	scanf("%d", &quantidade);
	for(index = 0; index < quantidade; index++)
		fprintf(arquivo, "%d ", rand()%1000);
	fclose(arquivo);
}
