#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int i;
	FILE *arquivo = fopen("arquivo.txt", "w");
	srand(time(NULL));
	for(i = 0; i < 50; i++)
		fprintf(arquivo, "%d ", rand()%1000);
	fclose(arquivo);
}
