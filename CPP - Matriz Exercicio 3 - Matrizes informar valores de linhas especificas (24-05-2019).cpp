#include <stdio.h>

int main(){
	int linha, coluna;
	int matriz[3] [5];
	
	for(linha=0; linha<3; linha++) {
		for(coluna=0; coluna<5; coluna++) {
		printf("informe um valor[%d][%d] da matriz: ", linha, coluna);
		scanf("%d", &matriz[linha] [coluna]);
		}
	}
	printf("matriz:\n \n");
	
	for(linha=0; linha<3; linha++) {
		for(coluna=0; coluna<3; coluna++) {
			printf("%3d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\n primeiro valor da primeira linha: %d", matriz[0][0]);
	printf("\n terceiro valor da segunda linha: %d", matriz[1][2]);
	printf("\n quinto valor da terceira linha: %d", matriz[2][4]);
	
return 0;
}
