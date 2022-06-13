/*1) Faça um programa que leia um texto do usuário e armazene em um arquivo.
2) Faça um programa que conte quantas linhas um arquivo possui.
2.1) Modifique o programa para contar quantos caracteres o arquivo possui.
2.2) Modifique o programa para contar quantos caracteres o arquivo possui, ignorando espaço, tabulação e nova linha (' ', '\t', '\n').
3) Faça um programa que lê as notas de 10 alunos e gere um arquivo com um relatório, contendo os nomes, notas e a média aritmética (usando 2 casas decimais).
4) Faça um programa que leia um arquivo texto e gere um arquivo 'criptografado'.
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
