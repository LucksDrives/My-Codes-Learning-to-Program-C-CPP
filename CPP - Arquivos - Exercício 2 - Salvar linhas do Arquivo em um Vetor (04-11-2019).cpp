/*2. Faça um programa que leia um vetor de inteiros A de tamanho 20 e guarde seus valores em um arquivo, um por linha. Em seguida, reabra o arquivo e leia os elementos para o vetor B, verificando se os valores foram gravados corretamente.*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int vetA[20], vetB[20], i;
	char linha[20];
	FILE *p;
	p=fopen("Text.txt","w+");
	if(p==NULL){
		printf("Erro na abertura do Arquivo");
		return -1;
	}
	for(i=0;i<20;i++){
		printf("\nINSIRA O VALOR DE [%d]:", i+1);
		scanf("%d", &vetA[i]);
	}
	for(i=0;i<20;i++){
		fprintf(p,"%d\n", vetA[i]);
	}
	fclose(p);
	p=fopen("Text.txt","r");
	if(p==NULL){
		printf("Erro na abertura do Arquivo");
	return -1;
	}
	i=0;
	while(fgets(linha, sizeof(linha),p)!=NULL){
		printf("%s", linha);
		vetB[i]= atoi (linha);		
		i++;
	}
	printf("\nVALORES DO VETOR B\n");
	for(i=0; i<20; i++){
		printf("\n%d",vetB[i]);
	}
	fclose(p);	
	return 0;
}

