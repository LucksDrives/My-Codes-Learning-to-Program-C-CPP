#include <stdio.h>

int main(){
	int linha, coluna;
	int matriz[3] [3];
	
	for(linha=0; linha<3; linha++) {
		for(coluna=0; coluna<3; coluna++) {
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
return 0;
}
