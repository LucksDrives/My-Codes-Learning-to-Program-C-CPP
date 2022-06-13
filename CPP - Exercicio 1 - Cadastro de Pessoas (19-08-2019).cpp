/*1) um sistema de seleção precisa armazenar os dados de 30 candidatos, que são: número da inscrição, nome, data de nascimento, cpf, rg e endereco;
1.1) adicione duas estruturas para representar a data de nascimento e o endereço.*/

#include<stdio.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}data;

typedef struct{
	int numero;
	char nome;
	int cpf;
	int rg;
	char endereco[30];
	data nasc;
}cadastro;


int main(){
	cadastro T[30];
	data D;
	int cont=0;
	
	for(cont=1;cont<=30; cont++){
	printf("USUARIO %d", cont);
	printf("\ninforme seu numero de cadastro: \n");
	scanf("%d", &T[cont].numero);
	printf("informe seu nome: \n");
	scanf(" %[^\n]s", &T[cont].nome);
	
	printf("informe sua data de nascimento: dia: \n");
	scanf("%d",&T[cont].nasc.dia);
	printf("informe sua data de nascimento: mes: \n");
	scanf("%d",&T[cont].nasc.mes);
	printf("informe sua data de nascimento: ano: \n");
	scanf("%d",&T[cont].nasc.ano);
	
	printf("informe seu CPF: \n");
	scanf("%d", &T[cont].cpf);
	printf("informe seu RG: \n");
	scanf("%d", &T[cont].rg);
	printf("informe seu Endereco: \n");
	scanf(" %[^\n]s", &T[cont].endereco);
	}
	return 0;
}
