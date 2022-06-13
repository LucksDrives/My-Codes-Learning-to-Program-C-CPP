/*Faça um programa que armazene as seguintes informações:

Código, nome e idade.

Faça um programa usando LISTAS que:

[X]- insira as informações

[X]- mostre os dados inseridos

[X]- mostre a média das idades armazenadas

[X]- mostre somente as idades acima de 18 anos

[X]- remova informações através do campo código

[X]- libere informações da memória.*/

#include<iostream> /*Incluir Biblioteca "iostream" para Uso das Funções do C++*/
using namespace std; /*Incluído para Uso de Comandos C++, como "Free"*/
#include <stdlib.h> /*Incluir Biblioteca Padrão "stdlib.h" para Uso das Funções do C*/
#include <string.h>

/*Criar Estrutura de Lista*/
struct lista{
 int codigo; /*Declaração da Variável Interira "Código"*/

 char nome[50];	/*Declaração da Variável Char "Nome"*/
 //qual o tamanho de nome? char nome[50]

 int idade; /*Declaração da Variável Flutuante "Idade"*/
 struct lista *prox; /*Declaração da Variável Lista para Ponteiro *prox"*/
}; typedef struct lista Lista; /*Definir o Tipo de Estrutura da Lista*/


/*Função Inserir Item na Lista*/
Lista *inserir(Lista *no, int codigo, char nome[], int idade){	
	Lista *novo = (Lista*)malloc(sizeof(Lista)); /*Função de Alocação Dinâmica de Memória*/
	novo->codigo = codigo; /*Armazenar Informação do Código na Lista*/
	novo->prox = no; /*Armazenar Informação do Código na Lista*/
	strcpy(novo->nome, nome); /*Armazenar Informação do Nome na Lista*/
	novo->idade = idade; /*Armazenar Informação da Idade na Lista*/
	return novo; /*Retorna o Novo Valor Inserido na Lista*/
}

/*Função Remover Item da Lista*/
Lista *remover(Lista *no, int valor){
	Lista *anterior = NULL; //Ponteiro para o elemento anterior
	Lista *p = no; //Ponteiro para percorrer a Lista
	
	/*procura o elemento na Lista, guardando o elemento anterior*/
	while( p != NULL && p->codigo != valor){
		anterior = p;
		p= p->prox;
	}
	// Verifica se achou o elemento
	if (p == NULL){
		return no; // não achou, retorna a Lista original
	}
	if (anterior == NULL){
		no = p->prox; // caso 1
	}
	else{
		anterior->prox = p->prox; // caso 2
	}
	free(p); /*Libera o Espaço que os Valores Anteriores Armazenavam, Liberando o Uso da Memória*/
	return no; /*Retornar Ponteiro*/
}

/*Função Percorrer Lista*/
void percorrer(Lista *no){
	Lista *p; /*Receber Variável do Ponteiro "no"*/
	
	cout<<"Impressão das Listas\n\n";
	 	
	/*Laço de Repetição para Percorrer os Valores da Lista*/
	for(p = no; p != NULL; p = p->prox){
			cout<<"codigo = " << p->codigo << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
			cout<<"nome = " << p->nome << "\n";
			cout<<"idade = " << p->idade<< "\n\n";
	}
}

/*Função Liberar Memória*/
void liberar (Lista *no){
	Lista *p = no; /*Receber Variável do Ponteiro "no"*/
	
	/*Laço de Repetição para Setar Null nas Informações Armazenadas no Ponteiro*/
	while (p != NULL){
		Lista *proximo = p->prox;
		free(p); /*Libera o Espaço que os Valores Anteriores Armazenavam, Liberando o Uso da Memória*/
		p = proximo;
	}
}

/*Função Mostrar Médias Lista*/
void medias(Lista *no){
	Lista *p; /*Receber Variável do Ponteiro "no"*/
	float media; /*Variável Float para Receber a Média*/
	int soma, aux=0; /*Soma (Variável Inteira para Receber a Soma das Idades)*/ /*aux(Variável Auxiliar)*/
	
	/*Laço de Repetição para Percorrer os Valores da Lista*/
	for(p = no; p != NULL; p = p->prox){
		soma += p->idade; /*Cálculo da Soma das Idades*/
		aux++;
	}
	media = soma / aux; /*Cálculo da Média das Idades*/
	cout<<"Media das Idades: " << media<< "\n";
}

/*Função Mostrar Idades Maiores que 18*/
void maiordezoito(Lista *no){
	Lista *p; /*Receber Variável do Ponteiro "no"*/
	
	/*Laço de Repetição para Percorrer os Valores da Lista*/
	for(p = no; p != NULL; p = p->prox){
		/*Verificação dos Valores Maiores que 18*/
		if(p->idade > 18) {
			cout<<"codigo = " << p->codigo << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
			cout<<"nome = " << p->nome << "\n";
			cout<<"idade = " << p->idade<< "\n\n";
		}
		/*Caso Não Seja Maior que 18*/
		else{
		}
	}
}

/*Inicio do Programa - Main*/
int main(){

/*Declaração dos Auxiliares*/
int op_funcao, codigo; /*op_funcao (variável que Recebe e Armazena a Opção Requisitada para Escolha da Função)*/ /*codigo (Variável que Recebe o Código para a Lista)*/
char nome[50]; /*Variável que Recebe o Nome para a Lista*/
int idade; /*Variável que Recebe a Idade para a Lista*/
Lista *no = NULL; /*no (Ponteiro Auxiliar para Endereçar o Valor Informado)*/

/*Menu de Seleção das Funções*/
 do{
 	cout<<"\n Executar Funcoes:\n\n"; /*Imprimir Título da Seleção*/
 	cout<<"[0] Sair\n"; /*Sair do Menu e Finalizar a Execução*/
 	cout<<"[1] Inserir Valores na Lista \n"; /*Inserir Novos Valores na Lista*/
 	cout<<"[2] Remover Valores da Lista \n"; /*Remover Valores da Lista*/
 	cout<<"[3] Imprimir Valores da Lista \n"; /*Imprimir Valores da Lista*/
 	cout<<"[4] Liberar Valores da Lista \n"; /*Liberar Memória da Lista*/
 	cout<<"[5] Imprimir Média das Idades da Lista \n"; /*Liberar Memória da Lista*/
 	cout<<"[6] Imprimir Idade Mior que 18 \n"; /*Liberar Memória da Lista*/ 
 	cin>>op_funcao; /*Armazena o Valor Escolhido na Variável op_funcao*/ /*Cin Equivale a Scanf*/

/*Executar Função requisitada na Seleção*/ 
  switch(op_funcao){
	  case 0: /*Caso Selecione 0*/
	   liberar(no); /*Executa a Função Liberar*/
	   break; /*Finaliza o Laço de Repetição*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe os valores para inserir na lista: "; /*Printar Auxiliar de Informação, Case: 1*/
	  	cout<<"\n Informe o codigo: "; /*Printar Auxiliar de Informação para Código*/	  	
	  	cin>>codigo; /*Armazena o Valor Escolhido na Variável valor*/ /*Cin Equivale a Scanf*/
	  	cout<<"\n Informe o Nome: "; /*Printar Auxiliar de Informação para Nome*/	  	
	  	cin>>nome; /*Armazena o Valor Escolhido na Variável nome*/ /*Cin Equivale a Scanf*/
	  	cout<<"\n Informe a Idade: "; /*Printar Auxiliar de Informação para Idade*/	  	
	  	cin>>idade; /*Armazena o Valor Escolhido na Variável Idade*/ /*Cin Equivale a Scanf*/
		
		no = inserir(no, codigo, nome, idade); /*Executa a Função Inserir (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
		// onde estão os outros argumentos??? inserir(no, codigo, nome, idade)
		break; /*Finaliza o Laço de Repetição*/
	  
	  case 2: /*Caso Selecione 2*/
	  	cout<<"\n Informe o Codigo do valor da Lista para Remover: "; /*Printar Auxiliar de Informação, Case: 2*/ 	
	  	cin>>codigo; /*Armazena o Valor Escolhido na Variável codigo*/ /*Cin Equivale a Scanf*/
		no = remover(no, codigo); /*Executa a Função Remover (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
	    break; /*Finaliza o Laço de Repetição*/
	  
	  case 3: /*Caso Selecione 3*/
		percorrer(no); /*Executa a Função Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
	    break; /*Finaliza o Laço de Repetição*/
	   
	  case 4: /*Caso Selecione 4*/
	  	liberar(no); /*Executa a Função Liberar (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
		no = NULL; /*Zera os Valores Amazenados no Ponteiro Liberando a Memória*/
		break; /*Finaliza o Laço de Repetição*/

	  case 5: /*Caso Selecione 5*/
		medias(no); /*Executa a Função Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
	    break; /*Finaliza o Laço de Repetição*/

	  case 6: /*Caso Selecione 6*/
		maiordezoito(no); /*Executa a Função Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
	    break; /*Finaliza o Laço de Repetição*/
					     
	  default: /*Caso Selecione um Valor Inexistente*/
	   printf("Comando invalido\n\n"); /*Caso Selecione uma Função Inválida*/
   }
 }while(op_funcao != 0); /*Executa o Programa Enquanto a Opção 0 Não For Selecionada*/

return 0; /*Finalizar o Programa*/
}
