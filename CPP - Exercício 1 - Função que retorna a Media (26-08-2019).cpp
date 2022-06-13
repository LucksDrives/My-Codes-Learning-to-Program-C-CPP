/*1-faça uma função que retorna a média de um vetor recebido por parâmetro*/

#include <stdio.h>

double media(int vetor[]) {
	int soma, cont=0;
	double media;
	
	for(cont=0; cont<5; cont++){
	soma+=vetor[cont];}
	
	media=soma/5;
	return(media);
}

int main(){
	double mediaV;
	int vetor[5], cont=0;
	
	printf("informe os valores do Vetor:\n");

		for(cont=0; cont<5; cont++){
			printf("vetor[%d]: ", cont);
			scanf("%d", &vetor[cont]);
		}
	mediaV=media(vetor);
	
	printf("media dos valores: %lf", mediaV);

}
