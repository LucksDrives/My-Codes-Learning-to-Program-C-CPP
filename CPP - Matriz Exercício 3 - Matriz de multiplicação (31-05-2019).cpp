#include <stdio.h>

int main(){
	int linha, coluna, valor;
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
		printf("informe um valor para multiplicar: ");
		scanf("%d", &valor);
		
		for(linha=0; linha<3; linha++) {
		for(coluna=0; coluna<3; coluna++) {
			matriz [linha] [coluna] = valor * matriz[linha] [coluna];
		}
	}
			for(linha=0; linha<3; linha++) {
			
		for(coluna=0; coluna<3; coluna++) {
			printf("%3d", matriz[linha][coluna]);
		}
	
		printf("\n");
}
return 0;
}
