/*1 - Fa�a uma fun��o que recebe 3 n�meros inteiros, denominados val, min e max. A fun��o deve retornar 1 se o numero est� dentro do intervalo fechado entre min e max, caso contr�rio retorna 0.*/

#include<stdio.h>

int fun(int val, int mim, int max) {
	
	if((val>=mim) && (val <=max)){
		printf("Esta no Intervalo");
		return 1;
	}
	else{
		printf("Nao esta no Intervalo");
		return 0;
	}
}

int main(){
	int val, mim, max;
	
	printf("valor: ");
	scanf("%d", &val);

	printf("valore minimo: ");
	scanf("%d", &mim);
	
	printf("valore maximo: ");
	scanf("%d", &max);
	
	fun(val, mim, max);
	
	return 0;
}

