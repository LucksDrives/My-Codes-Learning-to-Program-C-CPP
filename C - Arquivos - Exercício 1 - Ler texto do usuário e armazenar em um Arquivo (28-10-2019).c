/*1) Fa�a um programa que leia um texto do usu�rio e armazene em um arquivo.
2) Fa�a um programa que conte quantas linhas um arquivo possui.
2.1) Modifique o programa para contar quantos caracteres o arquivo possui.
2.2) Modifique o programa para contar quantos caracteres o arquivo possui, ignorando espa�o, tabula��o e nova linha (' ', '\t', '\n').
3) Fa�a um programa que l� as notas de 10 alunos e gere um arquivo com um relat�rio, contendo os nomes, notas e a m�dia aritm�tica (usando 2 casas decimais).
4) Fa�a um programa que leia um arquivo texto e gere um arquivo 'criptografado'.
Para isso, some a cada caracter. Nao some nos caracteres nova linha ('\n').*/

#include<stdio.h>

int main(){
	FILE *p;
	char texto[100];
	
	p=fopen("Text.txt","w+");
	if(p==NULL){
		printf("Erro na abertura do Arquivo");
		return -1;
	}
	printf("INSIRA O TEXTO:\n");
	scanf(" %[^\n]s", texto);
	
	fprintf(p,"\nTEXTO: %s", texto);
	fclose(p);
	return 0;
}
