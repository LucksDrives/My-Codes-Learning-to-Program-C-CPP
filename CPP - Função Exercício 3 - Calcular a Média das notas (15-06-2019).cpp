/*3 � Desenvolver uma fun��o para calcular a m�dia de 10 notas. O valor da m�dia
deve ser retornado para a fun��o principal (main).*/

#include<stdio.h>
#define TAM 10



float Media (float vetor[TAM]) {
	int cont;
	float media, soma=0;
	
for(cont=0;cont<TAM; cont++) {
	soma += vetor[cont];	
}
	media = soma / TAM;
	return (media);
}


int main() {
	
int cont=0;
float media, vetor[TAM], soma=0;

for(cont=0;cont<TAM; cont++) {
		printf("\nInforme a Nota [%d]: ", cont);
		scanf("%f", &vetor[cont]);
}

media = Media (vetor);
printf("Media das Notas: %f", media);

return 0;}
