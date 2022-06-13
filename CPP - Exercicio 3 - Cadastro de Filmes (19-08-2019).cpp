/*3) uma locadora quer armazenar até 500 filmes com os seguintes dados: codigo de barras, título, gênero, ano, e valor da locação.*/

#include<stdio.h>

typedef struct{
	int codigo;
	char titulo;
	int ano;
	char genero;
	float valor;
}cadastro_t;

int main(){
	cadastro_t T[500];
	int cont=0;
	
	for(cont=1;cont<=500; cont++){
	printf("FILME %d", cont);
	printf("\ninforme o codigo de cadastro: \n");
	scanf("%d", &T[cont].codigo);
	printf("informe a Titulo do filme: \n");
	scanf(" %[^\n]s", &T[cont].titulo);
	printf("informe o genero do filme: \n");
	scanf("%d", &T[cont].genero);
	printf("\ninforme o ano de lancamento: \n");
	scanf("%d", &T[cont].ano);
	printf("\ninforme o valor do filme: \n");
	scanf("%f", &T[cont].valor);
	}
	return 0;
}
