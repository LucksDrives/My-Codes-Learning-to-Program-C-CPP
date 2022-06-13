/*5 - Faça uma função que recebe um valor de tempo expresso em segundos e mostra na tela esse tempo em horas, minutos e segundos (ex. HH:mm:ss).*/

#include<stdio.h>

int conversor(int segundos){
	int cont, horas, minutos, auxmim=0;
	minutos=segundos/60;
	horas=minutos/60;
	printf("\nHoras: %d", horas);
	printf("\nMinutos: %d", minutos);
	printf("\nSegundos: %d", segundos);
	
	if(minutos>=cont) {
	auxmim=minutos-60;
	}
	for(cont=1;cont<=24; cont++){
	if(horas==cont) {
		minutos-=60*cont;
	}}

	printf("\n%d:%d:%d", horas, minutos, auxmim);	
}

int main(){
	int segundos;
	
	printf("informe os segundos: ");
	scanf("%d", &segundos);
	
	conversor(segundos);	
	return 0;
}

