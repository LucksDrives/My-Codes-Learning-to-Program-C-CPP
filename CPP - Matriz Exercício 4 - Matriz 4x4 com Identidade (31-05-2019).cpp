#include <stdio.h>

int main(){
	int linha, coluna, j, i;
	int matriz[4] [4];
	
	for(linha=0; linha<4; linha++) {
		for(coluna=0; coluna<4; coluna++) {
		printf("informe um valor[%d][%d] da matriz: ", linha, coluna);
		scanf("%d", &matriz[linha] [coluna]);
		}
	}
	
	printf("matriz:\n \n");
	
	for(linha=0; linha<4; linha++) {
		for(coluna=0; coluna<4; coluna++) {
			printf("%3d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	
	printf("\nmatriz identidade: \n");

	for(i=0; i<4; i++){
		for(j=0; j<4; j++) {
			if(i==j){matriz[i][j] = matriz[i][j] / matriz[i][j];
			}
		else{ matriz[i][j] = matriz[i][j] * 0;
		}
		printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	


return 0;
}
