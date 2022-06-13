#include <stdio.h>

int main(){
	float media, soma=0;
	int matriz[2] [8], linha, coluna;
	
	for(linha=0; linha<2; linha++) {
		for(coluna=0; coluna<8; coluna++) {
			printf("informe um valor[%d][%d] da matriz: ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
			soma += matriz[linha][coluna]; 
		}
	}
	printf("matriz:\n \n");
	
	for(linha=0; linha<2; linha++) {
		for(coluna=0; coluna<8; coluna++) {
			printf("%3d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\nsoma: %f", soma);
	media= soma/16;
	printf("\nmedia: %f", media);
return 0;
}
