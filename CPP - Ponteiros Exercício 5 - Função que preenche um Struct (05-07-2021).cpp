/*4) Crie uma lista com a seguinte estrutura:

Código
Nome
Salário

Implemente as funções: Inserir, remover, listar e liberar memória.*/

#include<stdio.h>

typedef struct lista{
 int codigo;
 char nome;
 float salario;
} typedef struct lista Lista;

void preenche_pctCAN(pctCAN *pct){
	int i;
		printf("Valor do id: \n");
		scanf("%d", &(*pct).id);
		/*Mostra*/
		printf("id=%d\n",(*pct).id);
	for(i=0; i<8; i++){
		printf("Valor do dado: \n");
		scanf("%d", &(*pct).dado);
		/*Mostra*/
		printf("dado=%d\n",(*pct).dado[i]);
	}
}

int main(){
	pctCAN pct;
	preenche_pctCAN(&pct);	
	return 0;
	}
