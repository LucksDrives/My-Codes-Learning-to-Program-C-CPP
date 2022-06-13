/*
-Faça um programa que armazena os dados de uma turma composta por N alunos.

-Cada aluno tem um nome e duas notas.

-O programa deve ser em forma de menu com as opções de incluir aluno, listar todos (nome e média), listar por ordem de média.

Utilize o seguinte programa e estruturas como base:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

typedef struct{
	char *nome;
	double n1, n2;
	double media;
} aluno_t;

typedef struct{
	char *disciplina;
	aluno_t *alunos; //vetor de alunos
} turma_t;

aluno_t armazena(void){
	aluno_t aux;
	aux.nome=malloc(sizeof(char)* 30);
		printf("\nNome:");
		scanf(" %[^\n]s", aux.nome);
		printf("\nNota 1:");
		scanf("%lf", &aux.n1);
		printf("\nNota 2:");
		scanf("%lf", &aux.n2);		
		aux.media=(aux.n1+aux.n2)/2;
	return (aux);
}

aluno_t mostrar(aluno_t vetor[], int tam){
	int i=0;
	for(i=0;i<tam;i++){
		printf("\n\n");
		printf("\nALUNO[%d]", i);
		printf("\nNome: %s", vetor[i].nome);
		printf("\nNota 1: %.2lf", vetor[i].n1);
		printf("\nNota 2: %.2lf", vetor[i].n2);
		printf("\nMedia: %.2lf", vetor[i].media);
		printf("\n \n");
	}
}

aluno_t ordenar(aluno_t vetor[], int tam){
	int i=0, j=0;
	aluno_t aux;
	for(i=0; i<tam; i++){
		for(j=i+1; j<tam; j++){
			if(vetor[i].media<vetor[j].media){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}
	}
	for(i=0;i<tam;i++){
		printf("\n\n");
		printf("\nALUNO[%d]", i);
		printf("\nNome: %s", vetor[i].nome);
		printf("\nNota 1: %.2lf", vetor[i].n1);
		printf("\nNota 2: %.2lf", vetor[i].n2);
		printf("\nMedia: %.2lf", vetor[i].media);
		printf("\n \n");
	}
}

int main(void){
	int op=0, i=0;
	turma_t algo; //algoritmos
	algo.disciplina = strdup("algoritmos");
	algo.alunos=malloc(sizeof(aluno_t) * TAM);
	do{
		printf("1 - cadastrar\n2 - listar todos\n3 - listar ordenado\n0-sair\nop:");
		scanf("%d",&op);
		switch(op){
			case 1:
				algo.alunos[i]=armazena(); /*CADASTRAR*/
				i++;
				printf("\n\n");
				break;	
			case 2:
				mostrar(algo.alunos, i);
				printf("\n\n");			/**SPRINTAR*/	
				break;	
			case 3:
				printf("\n\n");		
				printf("turma:%s\n",algo.disciplina);
				printf("implementar\n");			/*ORDENADO*/
				ordenar(algo.alunos, i);
				break;
			default: 
				printf("op invalida\n");
				break;	
		}
		printf("\n");
	}while(op!=0);

	return 0;
}
