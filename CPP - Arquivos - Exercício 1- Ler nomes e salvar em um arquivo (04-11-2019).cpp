/*1. Faça um programa que leia o nome e sobrenome de 30 alunos e armazene em um arquivo, de tal forma que o arquivo tenha um aluno por linha.*/
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

aluno_t mostrar(aluno_t vetor[], int tam, FILE *p){
	int i=0;
	for(i=0;i<tam;i++){
		fprintf(p,"\n\n");
		fprintf(p,"\nALUNO[%d]", i);
		fprintf(p,"\nNome: %s", vetor[i].nome);
		fprintf(p,"\nNota 1: %.2lf", vetor[i].n1);
		fprintf(p,"\nNota 2: %.2lf", vetor[i].n2);
		fprintf(p,"\nMedia: %.2lf", vetor[i].media);
		fprintf(p,"\n \n");
	}
}

int main(void){
	int op=0, i=0;
	FILE *p;
	p=fopen("Alunos.txt","w+");
	if(p==NULL){
		printf("Erro na abertura do Arquivo");
		return -1;
	}
	turma_t algo; //algoritmos
	algo.disciplina = strdup("algoritmos");
	algo.alunos=malloc(sizeof(aluno_t) * TAM);
	do{
		printf("1 - cadastrar\n2 - sair\nop:");
		scanf("%d",&op);
		switch(op){
			case 1:
				algo.alunos[i]=armazena(); /*CADASTRAR*/
				i++;
				printf("\n\n");
				mostrar(algo.alunos, i, p);
				break;	
			case 2:
				return 0;	
			default: 
				printf("op invalida\n");
				break;	
		}
		printf("\n");
	}while(op!=0);

	fclose(p);
	return 0;
}
