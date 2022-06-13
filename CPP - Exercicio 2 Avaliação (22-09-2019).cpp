/*Questão 2 (1,5): Faça uma função que recebe um
vetor e seu tamanho, por parâmetro, e testa se
esse vetor está em ordem crescente, retornando
1, caso contrário retorna 0.
Exemplo de chamada da função:
int v[3] = {1,2,3};
if(testaVetor(v,3))
printf("v esta' em ordem crescente\n");*/
#include<stdio.h>
int teste(int vet[]){
	int cont=0;
	for(cont=0; cont<3; cont++){
	if((vet[cont] < vet[cont+1]) && (vet[cont +1] < vet[cont+2])){
		printf("crescente");
		return(1);		
	}
	else{
		return(0);
	}
}
int main(){
	int num, vet[3]= {1,2,3};
	num = teste(vet);
	return 0;
}
