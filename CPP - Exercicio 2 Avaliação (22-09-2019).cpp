/*Quest�o 2 (1,5): Fa�a uma fun��o que recebe um
vetor e seu tamanho, por par�metro, e testa se
esse vetor est� em ordem crescente, retornando
1, caso contr�rio retorna 0.
Exemplo de chamada da fun��o:
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
