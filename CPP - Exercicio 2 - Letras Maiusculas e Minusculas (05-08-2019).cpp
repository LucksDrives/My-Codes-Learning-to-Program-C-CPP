/*EXERCÍCIOS*/

#include<stdio.h>

/*2 - Escreva as funções toUpper e toLower que recebem um caractere e retornam seu equivalente maísculo e minúsculo, respectivamente.
2.1 - Modifique a função para manter o caractere, caso já esteja no formato desejado.
2.2 - Confira se é uma letra válida antes de converter (se não for, retorna a o mesmo caractere).*/

char toUpper (char caractere) {
	char cont;
			if(caractere>65){
				cont= caractere-32;
				return(cont);
			}}
char toLower(char caractere) {
	char cont1;
			if(caractere<97){
				cont1= caractere+32; 
				return(cont1);
	}
}

int main(){
	char caractere, aux, aux1;
	
	printf("caractere:");
	scanf("%c", &caractere);
	
	if((caractere>97) && (caractere<122)) {
	aux= toUpper(caractere);
	printf("%c", aux);
	return 0;
	}
	
	if((caractere>65) && (caractere<90)) {
	aux1= toLower(caractere);
	printf("%c",aux1);
	return 0;
	}
	else{
		printf("invalido");
	}
	return 0;
}
