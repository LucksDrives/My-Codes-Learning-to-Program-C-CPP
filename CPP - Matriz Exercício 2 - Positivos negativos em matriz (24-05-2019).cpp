#include <stdio.h>

int main(){
	int linha, coluna, positivos=0, negativos=0;
	int matriz[3] [3];
	
	for(linha=0; linha<3; linha++) {
		for(coluna=0; coluna<3; coluna++) {
		printf("informe um valor[%d][%d] da matriz: ", linha, coluna);
		scanf("%d", &matriz[linha] [coluna]);
			if(matriz[linha][coluna] > 0) { positivos++;
			}
			if(matriz[linha][coluna] < 0){ negativos++;
			}
		}
	}
	printf("matriz:\n \n");
	
	for(linha=0; linha<3; linha++) {
		for(coluna=0; coluna<3; coluna++) {
			printf("%3d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\nNumero positivos: %d", positivos);
	printf("\nNumeros negativos: %d", negativos);
return 0;
}
