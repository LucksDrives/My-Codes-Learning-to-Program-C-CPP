#include <stdio.h>

int main(){
	float somapar=0, somaimpar=0;
	int matriz[4] [4], linha, coluna, par=0, impar=0;
	
	for(linha=0; linha<4; linha++) {
		for(coluna=0; coluna<4; coluna++) {
			printf("informe um valor[%d][%d] da matriz: ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
			if(matriz[linha][coluna] %2==0) {
				somapar+= matriz[linha][coluna]; 
				par++;
			else {
				somaimpar+= matriz[linha][coluna];
				impar++;
			}
			
			}
		}
	}
	printf("matriz:\n \n");
	
	for(linha=0; linha<4; linha++) {
		for(coluna=0; coluna<4; coluna++) {
			printf("%3d", matriz[linha][coluna]);
		}
		printf("\n");
	}
	printf("\npares: %d", par);
	printf("\nimpares: %d", impar);
	printf("soma par: %d", somapar);
	printf("soma par: %d", somaimpar);
return 0;
}
