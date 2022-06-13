/*6 – Escrever uma função para exibir uma string lida na ordem inversa.
OBS: Considerar os espaços em branco.
Exemplo:
String lida: ifrs ads
String inversa: sda srfi*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

void inverso(char palavra[TAM]) {
	int tam, i=0,cont=0,j=0;
	char invertido[TAM];
	
	printf("\nDigite a palavra: ");
	gets(palavra);
	
	tam = strlen(palavra);

 	for(i=tam-1;i>=0;i--){ 
	 	invertido[j] = palavra[i];
	 	j++;
	}
	printf("\nInvertida: %s", invertido);
}
 
 
 int main() {
 	
 	char palavra[TAM], invertido[TAM];
	int i=0,cont=0,j=0;
	
inverso(palavra);


 return(0);}
