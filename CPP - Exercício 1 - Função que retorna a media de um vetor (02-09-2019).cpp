/*1-fa�a uma fun��o que retorna a m�dia de um vetor recebido por par�metro*/
#include<stdio.h>

double Media(int vet[]) {
	int i, soma;
	double media;
	for(i=0; i<5; i++){
		soma+=vet[i];
	}
	media=soma/5;
}
