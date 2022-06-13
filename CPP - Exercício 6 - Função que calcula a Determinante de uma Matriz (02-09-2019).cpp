/*6-faça uma função que calcula o determinante de uma matriz 2x2*/
#include<stdio.h>
int DetMatriz(int Mat[][], int tam, int tam2){
	int i, j, Det;
	Det=Mat[0][0]*Mat[1][1] - Mat[0][1]*Mat[1][0];
	return(Det);
}

