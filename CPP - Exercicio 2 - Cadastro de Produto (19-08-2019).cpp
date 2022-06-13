/*2) um comerciante deseja armazenar os dados de 50 produtos: código, descrição, quantidade*/

#include<stdio.h>
typedef struct{
	int codigo;
	char descricao;
	int quantidade;
}cadastro[50];

int main(){
	cadastro T[50];
	int cont=0;
	
	for(cont=1;cont<=50; cont++){
	printf("Produto %d", cont);
	printf("\ninforme o codigo de cadastro: \n");
	scanf("%d", &T[cont].codigo);
	printf("informe a descrição do produto: \n");
	scanf(" %[^\n]s", &T[cont].descricao);
	printf("quantidade de produtos: \n");
	scanf("%d", &T[cont].quantidade);
	}
	return 0;
}
