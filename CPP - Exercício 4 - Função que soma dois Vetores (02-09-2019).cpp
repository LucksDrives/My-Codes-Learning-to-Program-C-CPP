/*4-fa�a uma fun��o que recebe como par�metro dois vetores de inteiros. o primeiro vetor deve ser modificado para ser a soma dos dois vetores.*/
#include<stdio.h>
int Soma(int vet1[], int vet2[]){
	int i;
	for(i=0; i<5; i++){
		vet1[i]+=vet2[i];
	}
	return(vet1, vet2);
}

