/*4 – Escreva uma função para verificar se um determinado valor se encontra em
um vetor de 5 elementos.*/

#include<stdio.h>
#define TAM 5


int Valores(int vetor[TAM]) {
	int cont=0;
	for(cont=0;cont<TAM; cont++) {
		printf("\nInforme o valor do vetor [%d]: ", cont);
		scanf("%d", &vetor[cont]);}
		return vetor[TAM];
		}
		
		
void Numero(int vetor[TAM], int numero) {
	int cont=0;
	printf("\nInforme um Numero: ");
	scanf("%d", &numero);
	for(cont=0; cont<TAM; cont++) {
	if(numero == vetor[cont]) {
		printf("\n%d Encontra-se no Vetor [%d]", numero, cont);	
		}
	else {
		printf("\n%d Nao encontra-se no Vetor [%d]", numero, cont);
		}}}



int main() {
	
int numero, vetor[TAM];

Valores(vetor);
Numero(vetor, numero);


return 0;}
