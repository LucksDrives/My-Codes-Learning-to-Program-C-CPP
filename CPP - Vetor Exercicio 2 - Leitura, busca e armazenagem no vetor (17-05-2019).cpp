/*2 – Escreva um programa para armazenar uma string. Ler um caractere e buscar
na string se o caractere existe. Caso existir, informar o índice que o caractere
está armazenado, e o número de vezes que aparece na string. */

#include <stdio.h>
#define TAM 20
#include<string.h>

int main() {
	char palavra[TAM], caractere;
	int cont=0;
		
	printf("escreva algo: ");
	gets(palavra);
	
	printf("informe um caractere: ");
	scanf("%c", &caractere);
	
	for(cont=0; cont<TAM; cont++) {
		if (caractere == palavra[cont]) {
			printf("\nO caractere encontra-se na palavra: ");
			printf("\nPosicao: %d",cont);
		}
		
	}
return 0;	
}
