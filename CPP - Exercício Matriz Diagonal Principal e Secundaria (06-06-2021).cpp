#include <stdio.h>

void diagonal(int M[3][3]){
	int i, j;
	printf("\nDiagonal Principal: ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if(M[i]==M[j]){
				printf("%d ", M[i][j]);
			}
		}
	}
	printf("\nDiagonal Secundaria: ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if(i + j == 2){
				printf("%d ", M[i][j]);
			}
		}
	}
	printf("\nMatriz(Apenas Diagonais):\n "); 
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if((M[i]==M[j]) || (i + j == 2)) {
				printf("%d ", M[i][j]);					
			}
			else{
				printf ("X ");
			}
		}
		printf("\n");
	}
	
	
}
int main(){
	int M[3][3];
	int i, j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
	printf("Valor da Matriz, Linha[%d], Coluna[%d]:", i, j);
	scanf("%d", &M[i][j]);
	}}
	diagonal(M);
	
	return 0;
}
