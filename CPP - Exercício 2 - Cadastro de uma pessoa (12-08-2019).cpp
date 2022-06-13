/*2. Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e armazene os dados em uma estrutura.*/

#include<stdio.h>
#include<math.h>

typedef struct{
	char nome[20];
	int	idade;
	char endereco[20];
} Pessoa_P;

int main(){
	Pessoa_P P;
	
	printf("Nome: ");
	scanf("%[^\n]s", P.nome);
	printf("idade: ");
	scanf("%d", &P.idade);
	printf("Endereco: ");
	scanf(" %[^\n]s", P.endereco);
    
    printf("\nNome: %s\n \nIdade: %d\n \nEndereço:%s\n", P.nome, P.idade, P.endereco);
	
	return 0;}	
