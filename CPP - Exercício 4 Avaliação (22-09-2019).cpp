/*Quest�o 4 (4,0): Considere um registro que
representa um ponto no plano cartesiano como
segue:
typedef struct {
double x;
double y;
} PtoXY;
(a) Fa�a um programa (somente a main) que
declara duas vari�veis deste registro, atribui
valores para x e y de cada vari�vel e ao fnal
mostre os pontos na tela.
(b) Considerando a fun��o que calcula a dist�ncia
entre dois pontos abaixo:
double distancia(PtoXY a, PtoXY b) {
double xab = b.x - a.x;
double yab = b.y - a.y;
return sqrt((xab*xab)+(yab*yab));
}
Adicione ao programa anterior (em (a)) uma
impress�o na tela informando a dist�ncia entre os
pontos utlizando esta fun��o.*/

#include<stdio.h>

typedef struct {
double x;
double y;
} PtoXY;

double distancia(PtoXY a, PtoXY b) {	
double xab = b.x - a.x;
double yab = b.y - a.y;
return sqrt((xab*xab)+(yab*yab));
}

int main(){
	PtoXY Pontos[2];
	int i;
	double D;
	
	for(i=0; i<2; i++){
	printf("Ponto X: ");
	scanf("%lf", &Pontos[i].x);
	printf("Ponto Y: ");
	scanf("%lf", &Pontos[i].y);
	printf(" Ponto X:%lf Ponto Y: %lf", Pontos.x[i], Pontos.y[i]);
	}
	D=distancia(x,y);
	printf("%lf", )
}
