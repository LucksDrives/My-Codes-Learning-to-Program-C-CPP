/*Implementar a fila com o c�digo para:

- Criar uma fila
- Implementar a inser��o
- Implementar a remo��o
- Implementar impress�o
- Implementar contador de dados inseridos

Entregar em arquivo.*/

#include<iostream> /*Incluir Biblioteca "iostream" para Uso das Fun��es do C++*/
using namespace std; /*Inclu�do para Uso de Comandos C++, como "Free"*/
#include <stdlib.h> /*Incluir Biblioteca Padr�o "stdlib.h" para Uso das Fun��es do C*/
#include <string.h>

/*Criar Estrutura de Fila*/
struct Fila{
 int codigo; /*Declara��o da Vari�vel Interira "C�digo"*/

 char nome[50];	/*Declara��o da Vari�vel Char "Nome"*/
 //qual o tamanho de nome? char nome[50]

 int idade; /*Declara��o da Vari�vel Flutuante "Idade"*/
 struct Fila *prox; /*Declara��o da Vari�vel Fila para Ponteiro *prox"*/
}; typedef struct Fila Fila; /*Definir o Tipo de Estrutura da Fila*/


/*Fun��o Inserir Item na Fila*/
Fila *inserir(Fila *no, int codigo, char nome[], int idade){	
	Fila *novo = (Fila*)malloc(sizeof(Fila)); /*Fun��o de Aloca��o Din�mica de Mem�ria*/
	novo->codigo = codigo; /*Armazenar Informa��o do C�digo na Fila*/
	novo->prox = no; /*Armazenar Informa��o do C�digo na Fila*/
	strcpy(novo->nome, nome); /*Armazenar Informa��o do Nome na Fila*/
	novo->idade = idade; /*Armazenar Informa��o da Idade na Fila*/
	return novo; /*Retorna o Novo Valor Inserido na Fila*/
}

/*Fun��o Remover Item da Fila*/
Fila *remover(Fila *no, int valor){
	Fila *anterior = NULL; //Ponteiro para o elemento anterior
	Fila *p = no; //Ponteiro para percorrer a Fila
	
	/*procura o elemento na Fila, guardando o elemento anterior*/
	while( p != NULL && p->codigo != valor){
		anterior = p;
		p= p->prox;
	}
	// Verifica se achou o elemento
	if (p == NULL){
		return no; // n�o achou, retorna a Fila original
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

/*Fun��o Percorrer Fila*/
void percorrer(Fila *no){
	Fila *p; /*Receber Vari�vel do Ponteiro "no"*/
	
	cout<<"Impress�o das Filas\n\n";
	 	
	/*La�o de Repeti��o para Percorrer os Valores da Fila*/
	for(p = no; p != NULL; p = p->prox){
			cout<<"codigo = " << p->codigo << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
			cout<<"nome = " << p->nome << "\n";
			cout<<"idade = " << p->idade<< "\n\n";
	}
}

/*Fun��o Liberar Mem�ria*/
void liberar (Fila *no){
	Fila *p = no; /*Receber Vari�vel do Ponteiro "no"*/
	
	/*La�o de Repeti��o para Setar Null nas Informa��es Armazenadas no Ponteiro*/
	while (p != NULL){
		Fila *proximo = p->prox;
		free(p); /*Libera o Espa�o que os Valores Anteriores Armazenavam, Liberando o Uso da Mem�ria*/
		p = proximo;
	}
}

/*Fun��o Mostrar M�dias Fila*/
void medias(Fila *no){
	Fila *p; /*Receber Vari�vel do Ponteiro "no"*/
	float media; /*Vari�vel Float para Receber a M�dia*/
	int soma, aux=0; /*Soma (Vari�vel Inteira para Receber a Soma das Idades)*/ /*aux(Vari�vel Auxiliar)*/
	
	/*La�o de Repeti��o para Percorrer os Valores da Fila*/
	for(p = no; p != NULL; p = p->prox){
		soma += p->idade; /*C�lculo da Soma das Idades*/
		aux++;
	}
	media = soma / aux; /*C�lculo da M�dia das Idades*/
	cout<<"Media das Idades: " << media<< "\n";
}

/*Fun��o Mostrar Idades Maiores que 18*/
void maiordezoito(Fila *no){
	Fila *p; /*Receber Vari�vel do Ponteiro "no"*/
	
	/*La�o de Repeti��o para Percorrer os Valores da Fila*/
	for(p = no; p != NULL; p = p->prox){
		/*Verifica��o dos Valores Maiores que 18*/
		if(p->idade > 18) {
			cout<<"codigo = " << p->codigo << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
			cout<<"nome = " << p->nome << "\n";
			cout<<"idade = " << p->idade<< "\n\n";
		}
		/*Caso N�o Seja Maior que 18*/
		else{
		}
	}
}

/*Inicio do Programa - Main*/
int main(){

/*Declara��o dos Auxiliares*/
int op_funcao, codigo; /*op_funcao (vari�vel que Recebe e Armazena a Op��o Requisitada para Escolha da Fun��o)*/ /*codigo (Vari�vel que Recebe o C�digo para a Fila)*/
char nome[50]; /*Vari�vel que Recebe o Nome para a Fila*/
int idade; /*Vari�vel que Recebe a Idade para a Fila*/
Fila *no = NULL; /*no (Ponteiro Auxiliar para Endere�ar o Valor Informado)*/

/*Menu de Sele��o das Fun��es*/
 do{
 	cout<<"\n Executar Funcoes:\n\n"; /*Imprimir T�tulo da Sele��o*/
 	cout<<"[0] Sair\n"; /*Sair do Menu e Finalizar a Execu��o*/
 	cout<<"[1] Inserir Valores na Fila \n"; /*Inserir Novos Valores na Fila*/
 	cout<<"[2] Remover Valores da Fila \n"; /*Remover Valores da Fila*/
 	cout<<"[3] Imprimir Valores da Fila \n"; /*Imprimir Valores da Fila*/
 	cout<<"[4] Liberar Valores da Fila \n"; /*Liberar Mem�ria da Fila*/
 	cout<<"[5] Imprimir M�dia das Idades da Fila \n"; /*Liberar Mem�ria da Fila*/
 	cout<<"[6] Imprimir Idade Mior que 18 \n"; /*Liberar Mem�ria da Fila*/ 
 	cin>>op_funcao; /*Armazena o Valor Escolhido na Vari�vel op_funcao*/ /*Cin Equivale a Scanf*/

/*Executar Fun��o requisitada na Sele��o*/ 
  switch(op_funcao){
	  case 0: /*Caso Selecione 0*/
	   liberar(no); /*Executa a Fun��o Liberar*/
	   break; /*Finaliza o La�o de Repeti��o*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe os valores para inserir na Fila: "; /*Printar Auxiliar de Informa��o, Case: 1*/
	  	cout<<"\n Informe o codigo: "; /*Printar Auxiliar de Informa��o para C�digo*/	  	
	  	cin>>codigo; /*Armazena o Valor Escolhido na Vari�vel valor*/ /*Cin Equivale a Scanf*/
	  	cout<<"\n Informe o Nome: "; /*Printar Auxiliar de Informa��o para Nome*/	  	
	  	cin>>nome; /*Armazena o Valor Escolhido na Vari�vel nome*/ /*Cin Equivale a Scanf*/
	  	cout<<"\n Informe a Idade: "; /*Printar Auxiliar de Informa��o para Idade*/	  	
	  	cin>>idade; /*Armazena o Valor Escolhido na Vari�vel Idade*/ /*Cin Equivale a Scanf*/
		
		no = inserir(no, codigo, nome, idade); /*Executa a Fun��o Inserir (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
		// onde est�o os outros argumentos??? inserir(no, codigo, nome, idade)
		break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 2: /*Caso Selecione 2*/
	  	cout<<"\n Informe o Codigo do valor da Fila para Remover: "; /*Printar Auxiliar de Informa��o, Case: 2*/ 	
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

	  case 5: /*Caso Selecione 5*/
		medias(no); /*Executa a Fun��o Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
	    break; /*Finaliza o La�o de Repeti��o*/

	  case 6: /*Caso Selecione 6*/
		maiordezoito(no); /*Executa a Fun��o Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
	    break; /*Finaliza o La�o de Repeti��o*/
					     
	  default: /*Caso Selecione um Valor Inexistente*/
	   printf("Comando invalido\n\n"); /*Caso Selecione uma Fun��o Inv�lida*/
   }
 }while(op_funcao != 0); /*Executa o Programa Enquanto a Op��o 0 N�o For Selecionada*/

return 0; /*Finalizar o Programa*/
}
