/*1- Fa�a um programa que mostra em que posi��o de mem�ria uma vari�vel est�.*/

#include <stdio.h>
int main(){
	int *p, a;
	a=1;
	p=&a;
	
	printf("Posicao: %d", &p);
	return 0;
}
