/*1.1 Apresente na tela em qual quadrante se encontra cada ponto.*/

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
	
	printf("\nDistancia: %lf", Distancia);

/*quadrante*/
if((Pl.X<0) && (Pl.Y<0)){
	printf("\nPonto 1 Quadrante 3");
}
else if((Pl.X>0) && (Pl.Y>0)){
	printf("\nPonto 1 Quadrante 1");
}
else if((Pl.X>0) && (Pl.Y<0)){
	printf("\nPonto 1 Quadrante 4");
}
else if((Pl.X<0) && (Pl.Y>0)){
	printf("\nPonto 1 Quadrante 2");
}
if((Pl.X2<0) && (Pl.Y2<0)){
	printf("\nPonto 2 Quadrante 3");
}
else if((Pl.X2>0) && (Pl.Y2>0)){
	printf("\nPonto 2 Quadrante 1");
}
else if((Pl.X2>0) && (Pl.Y2<0)){
	printf("\nPonto 2 Quadrante 4");
}
else if((Pl.X2<0) && (Pl.Y2>0)){
	printf("\nPonto 2 Quadrante 2");
}
	return 0;}	
