/*4) Faça um programa que leia um arquivo texto e gere um arquivo 'criptografado'.
Para isso, some a cada caracter. Nao some nos caracteres nova linha ('\n').*/

#include<stdio.h>
#include<string.h>

int main(){
	FILE *p;
	char linha[100];
	int cont=0, aux=0, aux2=0, aux3=0, i;
	
	p=fopen("Minecraft.txt","w+");
	if(p==NULL){
		printf("Erro na abertura do Arquivo");
		return -1;
	}
	printf("INSIRA O TEXTO:\n");
	scanf(" %[^\n]s", linha);
	
	fprintf(p,"\nTEXTO: %s", linha);
	
	fseek(p, 0, SEEK_SET);/*POSICIONAR O PONTEIRO NO INICIO DO CÓDIGO*/
	
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
