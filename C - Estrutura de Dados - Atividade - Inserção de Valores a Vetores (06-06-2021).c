    /*1) Faça um programa em C++ que peça ao usuário para informar 10 valores em um vetor de 10 posições. O algoritmo deve mostrar ao usuário os 10 números digitados em linhas separadas.*/
    #include <stdio.h>
    #define TAM 10
	
	int main(void) {
	int vet[TAM];
    int cont=1;
    
    for(cont=1;cont<=TAM;cont++){
		printf("Insira os Valores do Vetor[%d]: ", cont);
		scanf("%d", &vet[cont]);
	}
	
	cont=1;
	
    for(cont=1;cont<=TAM;cont++){
		printf("\nVetor[%d]: %d", cont, vet[cont]);
	}
	return 0;
    }	
	
	/*2) Faça um programa em C++ que peça ao usuário para informar os valores em uma matriz de 3x3 e imprima na tela os valores disposto como uma matriz. Estruturas.*/
	#include <stdio.h>

	void diagonal(int M[3][3]){
	int i, j;
	printf("\nDiagonal Principal: ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if(M[i]==M[j]){
				printf("%d ", M[i][j]);
			}
		}
	}
	printf("\nDiagonal Secundaria: ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if(i + j == 2){
				printf("%d ", M[i][j]);
			}
		}
	}
	printf("\nMatriz(Apenas Diagonais):\n "); 
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
			if((M[i]==M[j]) || (i + j == 2)) {
				printf("%d ", M[i][j]);					
			}
			else{
				printf ("X ");
			}
		}
		printf("\n");
	  }
	}
	int main(){
	int M[3][3];
	int i, j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++) {
	printf("Valor da Matriz, Linha[%d], Coluna[%d]:", i, j);
	scanf("%d", &M[i][j]);
	}}
	diagonal(M);
	
	return 0;
	}

    /*4) Faça um programa em C++ que declare dois ponteiros, um inteiro e um real, peça ao usuário para informar um número inteiro e um número real. O programa deve mostrar: 
- o valor por ele digitado para a variável inteira
- mostrar o endereço da variável inteira
- o valor por ele digitado para a variável real
- mostrar o endereço da variável real*/
	#include <stdio.h>
	
	int main(void) {
	int *p1; 
	float *p2;
	
		printf("Insira o Valor do Ponteiro[1]: ");
		scanf("%d", *p1);	
		
		printf("Insira o Valor do Ponteiro[2]: ");
		scanf("%f", *p2);	
		
		printf("Endereço do Valor Inteiro %d: %p", *p1, &p1);
		
		printf("Endereço do Valor Real %f: %p", *p2, &p2);
	
	return 0;
	}
	
	/*5) Faça o exercício proposto em CPP e verifique as saídas.*/
	#include <stdio.h>
	
	int main(void) {
		int *p;
		int a = 231;
		int b = 7680;
		
		printf ("p vaçe %p\n", &a);
		printf ("p vaçe %p\n", &b);	
		printf ("p vaçe %p\n", &p);	
		
		printf ("p vaçe %p\n", p);	
		
		p = &a;
		
		printf ("p vaçe %p\n", p);	
		printf ("p vaçe %p\n", *p);	
		
		*p = 500;
		printf ("b vale %d\n, b");
			
	return 0;
	}
	

