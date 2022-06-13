/*Crie uma lista com a seguinte estrutura:

C�digo
Nome
Sal�rio

Implemente as fun��es: Inserir, remover, listar e liberar mem�ria.*/

#include<iostream> /*Incluir Biblioteca "iostream" para Uso das Fun��es do C++*/
using namespace std; /*Inclu�do para Uso de Comandos C++, como "Free"*/
#include <stdlib.h> /*Incluir Biblioteca Padr�o "stdlib.h" para Uso das Fun��es do C*/
#include <string.h>
/*
Voc� manteve a vari�vel info na struct, essa era do exemplo, o que eu pedi foi 
c�digo, nome e sal�rio.Quando voc� cria as fun��es antes do main, n�o deve colocar 
os prot�tipo.�Al�m disso o prot�tipo, caso voc� os use antes do main() e crie as 
fun��es depois do main() devem ser iguais. N�o foi o que voc� fez. Por exemplo a fun��o
Lista *inserir(Lista *l, int i); no prot�tipo tem dois argumentos
Lista *inserir(Lista *no, int codigo, char nome, float salario) e na fun��o voc� colocou 4 argumentos
Ent�o voc� deve decidir, ou usa o prot�tipo e as fun��es depois do main, ou usa as fun��es
antes do main e sem prot�tipo. Isso vale tanto no C quanto no CPP.
Na op��o 1 voc� chamou a fun��o inserir com apenas dois argumentos, onde est�o os demais?
Voc� declarou o nome como char e n�o disse o tamanho

Para remover voc� n�o vai passar o valor, vai passar o c�digo e procurar o c�digo.
N�o existe info. Onde est� info na struct trocar por codigo.



*/
/*Criar Estrutura de Lista*/
struct lista{
 int codigo; /*Declara��o da Vari�vel Interira "C�digo"*/

 char nome[50];	/*Declara��o da Vari�vel Char "Nome"*/
 //qual o tamanho de nome? char nome[50]

 float salario; /*Declara��o da Vari�vel Flutuante "Sal�rio"*/
 struct lista *prox; /*Declara��o da Vari�vel Lista para Ponteiro *prox"*/
}; typedef struct lista Lista; /*Definir o Tipo de Estrutura da Lista*/


/*Fun��o Inserir Item na Lista*/
Lista *inserir(Lista *no, int codigo, char nome[], float salario){	
	Lista *novo = (Lista*)malloc(sizeof(Lista)); /*Fun��o de Aloca��o Din�mica de Mem�ria*/
	novo->codigo = codigo; /*Armazenar Informa��o do C�digo na Lista*/
	novo->prox = no; /*Armazenar Informa��o do C�digo na Lista*/
	strcpy(novo->nome, nome); /*Armazenar Informa��o do Nome na Lista*/
	novo->salario = salario; /*Armazenar Informa��o do Salario na Lista*/
	return novo; /*Retorna o Novo Valor Inserido na Lista*/
}

/*Fun��o Remover Item da Lista*/
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
		return no; // n�o achou, retorna a Lista original
	}
	if (anterior == NULL){
		no = p->prox; // caso 1
	}
	else{
		anterior->prox = p->prox; // caso 2
	}
	free(p); /*Libera o Espa�o que os Valores Anteriores Armazenavam, Liberando o Uso da Mem�ria*/
	return no; /*Retornar Ponteiro*/
}

/*Fun��o Percorrer Lista*/
void percorrer(Lista *no){
	Lista *p; /*Receber Vari�vel do Ponteiro "no"*/
	
	/*La�o de Repeti��o para Percorrer os Valores da Lista*/
	for(p = no; p != NULL; p = p->prox){
			cout<<"codigo = " << p->codigo << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
			cout<<"nome = " << p->nome << "\n";
			cout<<"salario = " << p->salario<< "\n";
	}
}

/*Fun��o Liberar Mem�ria*/
void liberar (Lista *no){
	Lista *p = no; /*Receber Vari�vel do Ponteiro "no"*/
	
	/*La�o de Repeti��o para Setar Null nas Informa��es Armazenadas no Ponteiro*/
	while (p != NULL){
		Lista *proximo = p->prox;
		free(p); /*Libera o Espa�o que os Valores Anteriores Armazenavam, Liberando o Uso da Mem�ria*/
		p = proximo;
	}
}

/*Inicio do Programa - Main*/
int main(){

/*Declara��o dos Auxiliares*/
int op_funcao, codigo; /*op_funcao (vari�vel que Recebe e Armazena a Op��o Requisitada para Escolha da Fun��o)*/ /*codigo (Vari�vel que Recebe o C�digo para a Lista)*/
char nome[50]; /*Vari�vel que Recebe o Nome para a Lista*/
float salario; /*Vari�vel que Recebe o Sal�rio para a Lista*/
Lista *no = NULL; /*no (Ponteiro Auxiliar para Endere�ar o Valor Informado)*/

/*Menu de Sele��o das Fun��es*/
 do{
 	cout<<"\n Executar Funcoes:\n\n"; /*Imprimir T�tulo da Sele��o*/
 	cout<<"[0] Sair\n"; /*Sair do Menu e Finalizar a Execu��o*/
 	cout<<"[1] Inserir Valor na Lista \n"; /*Inserir Novos Valores na Lista*/
 	cout<<"[2] Remover Valor da Lista \n"; /*Remover Valores da Lista*/
 	cout<<"[3] Imprimir Lista \n"; /*Imprimir Valores da Lista*/
 	cout<<"[4] Liberar Lista \n"; /*Liberar Mem�ria da Lista*/
 	cin>>op_funcao; /*Armazena o Valor Escolhido na Vari�vel op_funcao*/ /*Cin Equivale a Scanf*/

/*Executar Fun��o requisitada na Sele��o*/ 
  switch(op_funcao){
	  case 0: /*Caso Selecione 0*/
	   liberar(no); /*Executa a Fun��o Liberar*/
	   break; /*Finaliza o La�o de Repeti��o*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe os valores para inserir na lista: \n"; /*Printar Auxiliar de Informa��o, Case: 1*/
	  	cout<<"\n Informe o codigo: \n"; /*Printar Auxiliar de Informa��o para C�digo*/	  	
	  	cin>>codigo; /*Armazena o Valor Escolhido na Vari�vel valor*/ /*Cin Equivale a Scanf*/
	  	cout<<"\n Informe o Nome: \n"; /*Printar Auxiliar de Informa��o para Nome*/	  	
	  	cin>>nome; /*Armazena o Valor Escolhido na Vari�vel nome*/ /*Cin Equivale a Scanf*/
	  	cout<<"\n Informe o Salario: \n"; /*Printar Auxiliar de Informa��o para Sal�rio*/	  	
	  	cin>>salario; /*Armazena o Valor Escolhido na Vari�vel Sal�rio*/ /*Cin Equivale a Scanf*/
		
		no = inserir(no, codigo, nome, salario); /*Executa a Fun��o Inserir (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
		// onde est�o os outros argumentos??? inserir(no, codigo, nome, salario)
		break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 2: /*Caso Selecione 2*/
	  	cout<<"\n Informe o Codigo do valor da Lista para Remover: \n"; /*Printar Auxiliar de Informa��o, Case: 2*/ 	
	  	cin>>codigo; /*Armazena o Valor Escolhido na Vari�vel codigo*/ /*Cin Equivale a Scanf*/
		no = remover(no, codigo); /*Executa a Fun��o Remover (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
	    break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 3: /*Caso Selecione 3*/
		percorrer(no); /*Executa a Fun��o Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
	    break; /*Finaliza o La�o de Repeti��o*/
	   
	  case 4: /*Caso Selecione 4*/
	  	liberar(no); /*Executa a Fun��o Liberar (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
		no = NULL; /*Zera os Valores Amazenados no Ponteiro Liberando a Mem�ria*/
		break; /*Finaliza o La�o de Repeti��o*/
	     
	  default: /*Caso Selecione um Valor Inexistente*/
	   printf("Comando invalido\n\n"); /*Caso Selecione uma Fun��o Inv�lida*/
   }
 }while(op_funcao != 0); /*Executa o Programa Enquanto a Op��o 0 N�o For Selecionada*/

return 0; /*Finalizar o Programa*/
}
