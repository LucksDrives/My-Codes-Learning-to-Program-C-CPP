/*2 – Faça uma função para verificar se os elementos de um vetor de 5 posições
são positivos, negativos ou nulos. O vetor deve ser lido na função principal.*/

#include<stdio.h>
#define TAM 5

int Escrever(int cont, int vetor[TAM]){
	for(cont=0;cont<TAM; cont++) {
		printf("\nInforme o valor do vetor [%d]: ", cont);
		scanf("%d", &vetor[cont]);}
	return (vetor[TAM]);}


int PNN (int cont,int vetor[TAM]) {
	for(cont=0; cont<TAM; cont++) {
		if(vetor[cont] < 0) {
			printf("\n Numero (%d) da posicao [%d] eh Negativo", vetor[cont], cont);}
		if(vetor[cont] > 0) {
			printf("\n Numero (%d) da posicao [%d] eh Positivo", vetor[cont], cont);}
		if(vetor[cont] == 0) {
			printf("\n Numero (%d) da posicao [%d] eh Nulo", vetor[cont], cont);}
		} 
	}


int main() {
	
int cont=0, vetor[TAM];

Escrever(cont, vetor);
PNN (cont, vetor);

return 0;}
