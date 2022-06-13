/*1. Faça um programa que lê dois pontos em um plano cartesiano e calcula a distância entre eles.*/

#include<stdio.h>
#include<math.h>

typedef struct{
	int X;
	int Y;	
	int X2;
	int Y2;	
} Pontos_T;

int main(){
	Pontos_T Pl;
    double Distancia=0;
	
	printf("_PONTO 1_\n");
	printf("informe X: \n");
	scanf("%d", &Pl.X);
	printf("informe Y: \n");
	scanf("%d", &Pl.Y);
	
	printf("_PONTO 2_\n");
	printf("informe X: \n");
	scanf("%d", &Pl.X2);
	printf("informe Y: \n");
	scanf("%d", &Pl.Y2);
	
	Distancia= sqrt(pow((Pl.X2-Pl.X),2) + (pow((Pl.Y2-Pl.Y),2)));
	
	printf("Distancia: %lf", Distancia);

	return 0;}	
