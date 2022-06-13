/*4) Considere a struct abaixo:
typedef struct{
 int id;
 char dado[8];
} pctCAN;
Complete a funcao que preenche uma estrutura do tipo pctCAN com dados do usuario:*/

#include<stdio.h>

typedef struct{
 int id;
 int dado[8];
} pctCAN;

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
