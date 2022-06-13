/*2.1) Modifique o programa para contar quantos caracteres o arquivo possui.
2.2) Modifique o programa para contar quantos caracteres o arquivo possui, ignorando espaço, tabulação e nova linha (' ', '\t', '\n').
3) Faça um programa que lê as notas de 10 alunos e gere um arquivo com um relatório, contendo os nomes, notas e a média aritmética (usando 2 casas decimais).
4) Faça um programa que leia um arquivo texto e gere um arquivo 'criptografado'.
Para isso, some a cada caracter. Nao some nos caracteres nova linha ('\n').*/

#include<stdio.h>
#include<string.h>

int main(){
	FILE *p;
	char linha[100];
	int cont=0, aux=0, aux2=0, aux3=0, i;
	
	p=fopen("Text.txt","r");
	if(p==NULL){
		printf("Erro na abertura do Arquivo");
		return -1;
	}
	while(fgets(linha, sizeof(linha),p)!=NULL){
	printf("%s", linha);
	cont++;
	aux+=strlen(linha);
	for(i=0; i<aux; i++){
		if((linha[i]==' ')||(linha[i]=='\t')||(linha[i]=='\n')) {
			aux2++;
		}
	}
	}
	aux3=aux-aux2;
	printf("\nQuantidade de Linhas: %d", cont);
	printf("\nQuantidade de Caracteres: %d", aux);
	printf("\nQuantiade de Caracteres Filtrados: %d", aux3);
	fclose(p);
	return 0;
}
