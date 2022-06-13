/*1- Faça um programa que mostra em que posição de memória uma variável está.*/

#include <stdio.h>
int main(){
	int *p, a;
	a=1;
	p=&a;
	
	printf("Posicao: %d", &p);
	return 0;
}
