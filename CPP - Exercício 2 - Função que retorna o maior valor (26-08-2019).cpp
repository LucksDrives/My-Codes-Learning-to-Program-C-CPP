/*2- fa�a uma fun��o que retorna o maior n�mero de um vetor recebido por par�metro*/

#include <stdio.h>

int maior(int vetor[]) {
	int cont=0;
	int maior=vetor[1];
		
	for(cont=0; cont<5; cont++){
	if(vetor[cont]>maior){maior=vetor[cont];
	}}
	
	return(maior);
}

int main(){
	int Maior;
	int vetor[5], cont=0;
	
	printf("informe os valores do Vetor:\n");

		for(cont=0; cont<5; cont++){
			printf("vetor[%d]: ", cont);
			scanf("%d", &vetor[cont]);
		}
	Maior=maior(vetor);
	
	printf("Maior valor: %d", Maior);

}
