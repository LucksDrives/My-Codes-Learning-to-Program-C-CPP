/*1 � Fa�a um algoritmo para ler um vetor de 5 posi��es. Ler um n�mero e verificar
se esse n�mero se encontra no vetor. Se o n�mero existir no vetor, informe em
qual posi��o (ou posi��es). Caso contr�rio, exibir uma mensagem informando
que o n�mero n�o foi encontrado. */

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
