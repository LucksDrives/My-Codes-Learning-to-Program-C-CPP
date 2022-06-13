/*Quest�o 3 (3,0): O programa abaixo armazena os
tempos de volta para um conjunto de carros em
uma dada corrida de autom�veis. Complete, onde
especifcado, as fun��es de preencher (ler do
usu�rio) e imprimir (mostrar na tela) as estruturas
usadas no programa.*/

#include <stdio.h>
#define NVOLTAS 71
#define NCARROS 3

typedef struct {
	int numero;
	double tvolta[NVOLTAS];
} carro_t;

void imprimecarro(carro_t c){
	printf("\nNumero: %d",c.numero);
	printf("\nVolta: %lf",c.tvolta);	
}
carro_t preenchecarro(carro_t c){
	printf("Numero: ");
	scanf("%d", &c.numero);
	printf("Volta: ");
	scanf("%lf", &c.tvolta);
	return(c);
}

int main(){
carro_t Carro[NCARROS];
int i;

for(i=0;i<NCARROS;i++){
	Carro[i]=preenchecarro(Carro[i]);
}
for(i=0;i<NCARROS;i++){
	imprimecarro(Carro[i]);
}
return 0;
}
