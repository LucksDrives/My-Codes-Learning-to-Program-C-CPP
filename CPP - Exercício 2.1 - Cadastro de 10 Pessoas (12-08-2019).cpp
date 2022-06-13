/*2.1 Faça um programa que lê 10 pessoas e mostra na tela.*/

#include<stdio.h>
#include<math.h>

typedef struct{
	char nome[20];
	int	idade;
	char endereco[20];
} Pessoa_P;

int main(){
	Pessoa_P P[10];
	int cont;
	
	for(cont=0; cont<10; cont++){
		printf("Nome[%d]: ", cont);
		scanf(" %[^\n]s", P[cont].nome);
		printf("idade[%d]: ", cont);
		scanf("%d", &P[cont].idade);
		printf("Endereco[%d]: ", cont);
		scanf(" %[^\n]s", P[cont].endereco);
	}
	printf("\n_PESSOAS CADASTRADAS_");
	for(cont=0; cont<10; cont++){
    printf("\nNome: %s\n \nIdade: %d\n \nEndereco:%s\n", P[cont].nome, P[cont].idade, P[cont].endereco);}
	
	return 0;}	
