    /*1) Fa�a um programa em C++ que pe�a ao usu�rio para informar 10 valores em um vetor de 10 posi��es. O algoritmo deve mostrar ao usu�rio os 10 n�meros digitados em linhas separadas.*/
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
	
	/*2) Fa�a um programa em C++ que pe�a ao usu�rio para informar os valores em uma matriz de 3x3 e imprima na tela os valores disposto como uma matriz. Estruturas.*/
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

    /*4) Fa�a um programa em C++ que declare dois ponteiros, um inteiro e um real, pe�a ao usu�rio para informar um n�mero inteiro e um n�mero real. O programa deve mostrar: 
- o valor por ele digitado para a vari�vel inteira
- mostrar o endere�o da vari�vel inteira
- o valor por ele digitado para a vari�vel real
- mostrar o endere�o da vari�vel real*/
	#include <stdio.h>
	
	int main(void) {
	int *p1; 
	float *p2;
	
		printf("Insira o Valor do Ponteiro[1]: ");
		scanf("%d", *p1);	
		
		printf("Insira o Valor do Ponteiro[2]: ");
		scanf("%f", *p2);	
		
		printf("Endere�o do Valor Inteiro %d: %p", *p1, &p1);
		
		printf("Endere�o do Valor Real %f: %p", *p2, &p2);
	
	return 0;
	}
	
	/*5) Fa�a o exerc�cio proposto em CPP e verifique as sa�das.*/
	#include <stdio.h>
	
	int main(void) {
		int *p;
		int a = 231;
		int b = 7680;
		
		printf ("p va�e %p\n", &a);
		printf ("p va�e %p\n", &b);	
		printf ("p va�e %p\n", &p);	
		
		printf ("p va�e %p\n", p);	
		
		p = &a;
		
		printf ("p va�e %p\n", p);	
		printf ("p va�e %p\n", *p);	
		
		*p = 500;
		printf ("b vale %d\n, b");
			
	return 0;
	}
	

