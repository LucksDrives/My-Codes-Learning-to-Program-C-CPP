/*Desevolver um programa que calcula a média de N notas, informadas pelo usuário.
Ao final, as notas individuais devem ser salvas em um arquivo texto.
Se, ao iniciar, já existir o arquivo, o programa deve ler as notas do arquivo e calcular a média.
O vetor de notas usado para o cálculo deve ser alocado dinamicamente.
Dica: usar a primeira posição do arquivo texto para armazenar a quantidade de linhas.
Dica: usar a função atof para converter de texto para double.
Dica: testar a existência do arquivo conforme link*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(){
	int TAM=0, i;
	double *vetA, soma=0, media=0;
	char linha[50];
	FILE *p;
	vetA=malloc(sizeof(double)*TAM);
	
	if(access("Text.txt", F_OK)!= -1){
	/*Caso Exista um Arquivo*/
	printf("\n--ARQUIVO ENCONTRADO--\n");
	system("color 9F");
		/*Ler Arquivo*/
		p=fopen("Text.txt","r");
		if(p==NULL){
			printf("Erro na abertura do Arquivo");
		}
		while(fgets(linha, sizeof(linha),p)!=NULL){
			printf("\nValor[%d]: %s",i+1,linha);
			vetA[i]= atof (linha);	
			soma+=vetA[i];	
			i++;
		}
		fclose(p);
		media=soma/i;
		printf("\nMedia das Notas: %.2lf", media);								
		return 0;
	}

	else{
	/*Caso não Exista um Arquivo*/
	printf("\n--ARQUIVO INEXISTENTE--\n");
	system("color 4F");
		/*Criar Arquivo*/
		printf("\nCrie o Arquivo");
		printf("\nQuantidade de Valores a Armazenar:");
		scanf("%d", &TAM);
		p=fopen("Text.txt","w");
		if(p==NULL){
			printf("Erro na abertura do Arquivo");
		}
		for(i=0;i<TAM;i++){
			printf("\nINSIRA O VALOR DE [%d]:", i+1);
			scanf("%lf", &vetA[i]);
			fprintf(p,"%.2lf\n", vetA[i]);
			soma+=vetA[i];
		}
		fclose(p);
		media=soma/TAM;
		printf("\nMedia das Notas: %.2lf", media);
		return 0;
	}
	return 0;
}
