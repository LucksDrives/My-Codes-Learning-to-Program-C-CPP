/*1 – Faça um algoritmo para ler um vetor de 5 posições. Ler um número e verificar
se esse número se encontra no vetor. Se o número existir no vetor, informe em
qual posição (ou posições). Caso contrário, exibir uma mensagem informando
que o número não foi encontrado. */

#include <stdio.h>
#define TAM 5

int main() {
	int vetor[TAM], numero,cont=0, valorV;
		
	for(cont=0; cont<TAM; cont++) {
		printf("valores do vetor: ");
		scanf("%d", &vetor[cont]);
	}
		printf("informe um numero: ");
		scanf("%d", &numero);
	for(cont=0; cont<TAM; cont++) {
		if (numero == vetor[cont]) {
		printf("\nO numero encontra-se no vetor: %d", numero);
		printf("\nPosicao: %d",cont);
		}
		
	}
return 0;	
}
