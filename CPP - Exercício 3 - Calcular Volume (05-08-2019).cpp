
/*3 - Faça uma função que recebe o raio de uma esfera e retorna o calculo do seu volume (v = 4/3 * Pi * R^3).*/

#include<stdio.h>

double Fun (double raio) {
	double volume;
	double pi=3.14;
	
	volume=(4/3)*pi*(raio*raio*raio);
	
	return(volume);
}

int main(){
	double VolumeReturn, raio;
	
	printf("informe o raio: ");
	scanf("%lf", &raio);
	
	VolumeReturn= Fun(raio);
	printf("volume: %.2lf", VolumeReturn);
	return 0;
}
