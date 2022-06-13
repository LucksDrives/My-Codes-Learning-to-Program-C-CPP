/*1-faça uma função que retorna a média de um vetor recebido por parâmetro*/
#include<stdio.h>

double Media(int vet[]) {
	int i, soma;
	double media;
	for(i=0; i<5; i++){
		soma+=vet[i];
	}
	media=soma/5;
}
