/*5-fa�a uma fun��o que ordena crescentemente um vetor recebido por par�metro*/
#include<stdio.h>
void Ordenar(int vet[], int tam){ 
	int i, j, aux;
	for(i=0; i<tam; i++){
		for(j=i+1; j<tam; j++){
			if(vet[i]>vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
}
