/*1 - Faça uma função que recebe 3 números inteiros, denominados val, min e max. A função deve retornar 1 se o numero está dentro do intervalo fechado entre min e max, caso contrário retorna 0.*/

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

