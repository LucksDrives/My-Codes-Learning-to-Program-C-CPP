/*4) faca um programa que armazena os dados de 20 alunos de uma turma. Os dados do aluno sao: nome, matricula e 3 notas.
4.1) calcule a media de cada aluno - media aritmetica das tres notas - e apresente em formato de tabela na tela.
4.2) mostre a media da turma*/

#include<stdio.h>

typedef struct{
	int nota1;
	int nota2;
	int nota3;
}notas;

typedef struct{
	notas nota;
	char nome;
	int matricula;
	double media;
}cadastro;

int main(){
	cadastro T[20];
	int cont=0;
	double media;

	for(cont=1;cont<=20; cont++){
	printf("\nALUNO %d", cont);
	printf("\ninforme o nome do aluno: \n");
	scanf(" %[^\n]s", &T[cont].nome);
	printf("informe o numero da matricula: \n");
	scanf("%d", &T[cont].matricula);
	printf("infome as notas do aluno(nota 1): \n");
	scanf("%d", &T[cont].nota.nota1);
	printf("infome as notas do aluno(nota 2): \n");
	scanf("%d", &T[cont].nota.nota2);
	printf("infome as notas do aluno(nota 3): \n");
	scanf("%d", &T[cont].nota.nota3);
	T[cont].media=(T[cont].nota.nota1+T[cont].nota.nota2+T[cont].nota.nota3)/3;
	}
	return 0;
}
