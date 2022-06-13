/*2-faça uma função que retorna o maior número de um vetor recebido por parâmetro*/

#include<stdio.h>
int MaiorNum(int vet[]){
	int i, aux;
	aux=vet[0]
	for(i=0;i<5;i++){
		if(aux>vet[i]) {
			aux=vetor[i];
		}	
	}
	return(aux);
}
