#include<stdio.h>
#define TAM 10

int Escrever(int cont, int vetor[TAM]){
	for(cont=0;cont<TAM; cont++) {
	printf("\nInforme o valor do vetor [%d]: ", cont);
	scanf("%d", &vetor[cont]);}
	return (vetor[TAM]);}


int Mostrar (int cont, int vetor[TAM]) {
	for(cont=0; cont<TAM; cont++) {
	printf("\nNumero do vetor [%d]: %d", cont, vetor[cont]);}
	return 0;}


int main() {
	
int cont=0, vetor[TAM];

Escrever(cont, vetor);
Mostrar (cont, vetor);

return 0;}
