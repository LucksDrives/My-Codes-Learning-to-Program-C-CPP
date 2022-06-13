/*Desenvolver um programa em CPP que pergunte ao usu�rio o que ele deseja fazer atrav�s do seguinte menu:

0 - Sair
1 - Pilhas
2 - Filas
3 - �rvores
4 - Listas

Se o usu�rio escolher a op��o 1, mostre o menu que executar� as seguintes tarefas:

0 - Voltar ao menu principal
1 - Inserir dados na pilha
2 - excluir dados da pilha
3 - Imprimir Pilha
4 - Limpar Pilha

Se o usu�rio escolher a op��o 2, mostre o menu que executar� as seguintes tarefas:

0 - Voltar ao menu principal
1 - Inserir dados na fila
2 - excluir dados da fila
3 - Imprimir Fila
4 - Limpar Fila

Se o usu�rio escolher a op��o 3, mostre o menu que executar� as seguintes tarefas:

0 - Voltar ao menu principal
1 - Inserir dados na �rvore
2 - excluir dados da �rvore
3 - Imprimir �rvore
4 - Mostrar o n�vel da �rvore
5 - imprimir os elementos da �rvores EM ORDEM.
6 - Limpar �rvore*/

#include<iostream> /*Incluir Biblioteca "iostream" para Uso das Fun��es do C++*/
using namespace std; /*Inclu�do para Uso de Comandos C++, como "Free"*/
#include <stdlib.h> /*Incluir Biblioteca Padr�o "stdlib.h" para Uso das Fun��es do C*/
#include <string.h> /*Incluir Biblioteca Padr�o para C*/

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*Cria��o de Uma Estrutura de Listas Base*/
struct lista{
	int info; /*Declara��o da Vari�vel Inteira Auxiliar para Pilha*/
	struct lista *prox; /*Declara��o de Ponteiro*/
};

typedef struct lista Lista; /*Defini��o da Estrutura de Listas*/

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUN��ES PARA PILHAS[1]*/

/*Cria��o da Estrutura da Pilha*/
struct pilha{
	Lista *topo; /*Declara��o do Ponteiro Auxiliar de Lista para Pilha*/
};

typedef struct pilha Pilha; /*Defini��o da Estrutura da Pilha*/

/*Declara��o das Fun��es da Pilha*/
Pilha *cria(void); /*Criar Pilha*/
void push(Pilha *p, int v); /*Fun��o Push, Auxiliar para Pilhas*/
int pop(Pilha *p); /*Fun��o Pop, Auxiliar para Pilhas*/
void liberaPilha(Pilha *p); /*Liberar Valores da Pilha*/
void percorrer(Pilha *p); /*Percorrer Valores da Pilha*/
int tamanhoPilha(Pilha *p); /*Verificar Tamanho da Pilha*/

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUN��ES PARA FILAS[2]*/

/*Criar Estrutura de Fila*/
struct Fila{
 int valorF; /*Declara��o da Vari�vel Interira "C�digo"*/
 struct Fila *prox; /*Declara��o da Vari�vel Fila para Ponteiro *prox"*/
}; typedef struct Fila Fila; /*Definir o Tipo de Estrutura da Fila*/


/*Fun��o Inserir Item na Fila*/
Fila *inserir(Fila *noF, int valorF){	
	Fila *novo = (Fila*)malloc(sizeof(Fila)); /*Fun��o de Aloca��o Din�mica de Mem�ria*/
	novo->valorF = valorF; /*Armazenar Informa��o do C�digo na Fila*/
	novo->prox = noF; /*Armazenar Informa��o do C�digo na Fila*/
	return novo; /*Retorna o Novo Valor Inserido na Fila*/
}

/*Fun��o Remover Item da Fila*/
Fila *remover(Fila *noF, int valor){
	Fila *anterior = NULL; //Ponteiro para o elemento anterior
	Fila *p = noF; //Ponteiro para percorrer a Fila
	
	/*procura o elemento na Fila, guardando o elemento anterior*/
	while( p != NULL && p->valorF != valor){
		anterior = p;
		p= p->prox;
	}
	// Verifica se achou o elemento
	if (p == NULL){
		return noF; // n�o achou, retorna a Fila original
	}
	if (anterior == NULL){
		noF = p->prox; // caso 1
	}
	else{
		anterior->prox = p->prox; // caso 2
	}
	free(p); /*Libera o Espa�o que os Valores Anteriores Armazenavam, Liberando o Uso da Mem�ria*/
	return noF; /*Retornar Ponteiro*/
}

/*Fun��o Percorrer Fila*/
void percorrer(Fila *noF){
	Fila *p; /*Receber Vari�vel do Ponteiro "no"*/
	
	cout<<"Impressao das Filas\n\n";
	 	
	/*La�o de Repeti��o para Percorrer os Valores da Fila*/
	for(p = noF; p != NULL; p = p->prox){
			cout<<"Valor = " << p->valorF << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
	}
}

/*Fun��o Liberar Mem�ria*/
void liberar (Fila *noF){
	Fila *p = noF; /*Receber Vari�vel do Ponteiro "no"*/
	
	/*La�o de Repeti��o para Setar Null nas Informa��es Armazenadas no Ponteiro*/
	while (p != NULL){
		Fila *proximo = p->prox;
		free(p); /*Libera o Espa�o que os Valores Anteriores Armazenavam, Liberando o Uso da Mem�ria*/
		p = proximo;
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////*/

/*FUN��ES PARA �RVORES[3]*/

int quantidadeNos = 0; /*Vari�vel Pr� Definida para Contabilizar os N�s nas Arvores*/

/*Estrutura de Cria��o de um N� Auxiliar para Raiz da �rvore*/
struct no {
	int chave; /*Auxiliar Inteira para o Valor Chave da �rvore*/
	int cont; /*Auxiliar Inteira para o Contador da �rvore*/
	struct no *esq, *dir, *pai; /*Declara��o dos Ponteiros*/
};

typedef struct no No; /*Defini��o da Estrutura*/
 No *auxPai = NULL; /*Declara��o do Ponteiro para o N� como um Valor Nulo*/

/*Declara��o das Fun��es de �rvores Bin�rias*/
void vaziaArvore(No *raiz);
void insere (int x, No **p); /*Fun��o para Insers�o dos Valores na �rvore*/
int contarNos(No *p); /*Fun��o para Contabilizar o N�mero de N�s da �rvore*/
No *busca(No *arvore, int x); /*Fun��o de Busca para Determinado Valor da �rvore*/
void consultarValor(No* raiz); /*Fun��o para Consultar Valores da �rvore*/
void consultarDetalhes(No* raiz); /*Fun��o para Constultar Detalhes da �rvore*/
void imprime(No *p, int nivel); /*Fun��o para Imprimir os Valores da �rvore*/
void consultaNivel(No *p); /*Fun��o para Consultar o N�vel da �rvore*/
void preordem (No *arvore); /*Fun��o preordem, para Bifurca��o da �rvore*/
void emordem(No *arvore); /*Fun��o emordem, para Bifurca��o da �rvore*/
void posordem(No *arvore); /*Fun��o posordem, para Bifurca��o da �rvore*/
No *removeNo(No *raiz, int x); /*Fun��o de Remo��o do N�*/
int menu(); /*Fun��o Menu*/

/*Inicio do Programa - Main*/
int main(){
	int opcao; /*Declara��o da Vari�vel Inteira para Definir a Fun��o a Ser Executada*/
	
	/*Declara��o dos Auxiliares das Pilhas*/
	int op_pilha, valorP, tamP; /*Declara��o dos Valores Inteiros*/
	Pilha *p; /*Declara��o do Ponteiro para a Pilha*/
	p = cria(); /*Cria��o do Ponteiro*/
	Lista *noP = NULL; /*Declara��o do Ponteiro de Listas Auxiliar para Pilhas*/
	
	/*Declara��o dos Auxiliares das Filas[2]*/
	int op_funcaoF, valorF; /*op_funcao (vari�vel que Recebe e Armazena a Op��o Requisitada para Escolha da Fun��o)*/ /*codigo (Vari�vel que Recebe o C�digo para a Fila)*/
	Fila *noF = NULL; /*no (Ponteiro Auxiliar para Endere�ar o Valor Informado)*/
	
	/*Declara��o dos Auxiliares das �rvores[3]*/	
	int n,rm,a,b;
	No *raiz, *aux;
	raiz = NULL;
	int opcaoA;
	
/*Abertura do La�o de Repeti��o Principal do C�digo*/	
	do{
	cout<<"\n Selecionar Funcao:\n\n"; /*Imprimir T�tulo da Sele��o*/
 	cout<<"[0] Sair\n"; /*Sair do Menu e Finalizar a Execu��o*/
 	cout<<"[1] Pilhas \n"; /*Op��o para Executar as Pilhas*/
 	cout<<"[2] Filas \n"; /*Op��o para Executar as Filas*/
 	cout<<"[3] Arvores \n"; /*Op��o para Executar as Arvores*/
 	cout<<">"; /*Campo de Digita��o*/
 	cin>>opcao; /*Armazena o Valor Escolhido na Vari�vel opcao*/ /*Cin Equivale a Scanf*/

/*Executar Fun��o requisitada na Sele��o*/ 
  switch(opcao){

/*Para Finalizar o Programa*/  	
case 0: 
 break;	/*Finalizar La�o de Repeti��o Principal*/

/*///////////////////////////////////////////////////////////////////////////////////////*/	
		
/*Para Executar as PILHAS[1]*/
case 1:

/*Menu de Sele��o das Fun��es*/
 do{
 	cout<<"\n Escolha a Funcao a ser Executada:\n\n"; /*Imprimir Informa��es do Menu*/
 	cout<<"0 - Voltar\n"; /*Finalizar La�o*/
 	cout<<"1 - Adicionar item na Pilha \n"; /*Adiciona um Item a Pilha*/
 	cout<<"2 - Remover item da Pilha \n"; /*Remove um Item da Pilha*/
 	cout<<"3 - Imprimir Pilha \n"; /*Imprime Valores da Pilha*/
 	cout<<"4 - Tamanho da Pilha \n"; /*Imprime Tamanho da Pilha*/
 	cout<<"5 - Liberar Pilha \n\n"; /*Libera a Pilha*/
 	cout<<">"; /*Campo de Digita��o*/
 	cin>>op_pilha; /*Armazena Valor da Op��o*/

/*Executar Fun��o requisitada na Sele��o*/ 
  switch(op_pilha){
	  case 0: /*Caso Selecione 0*/
	   liberaPilha(p); /*Executa a Fun��o para Liberar a Pilha*/
	   break; /*Finaliza o La�o de Repeti��o*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe o valor para inserir na pilha: \n"; /*Imprimir o Texto*/
	  	cin>>valorP; /*Armazenar o Valor a ser Inserido na Pilha*/
		push( p, valorP);
		break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 2: /*Caso Selecione 2*/
	  	int v; /*Declara��o de Valor Auxiliar*/
		v = pop(p); /*Igualando V ao Ponteiro*/
		if(v != -1) /*Caso V Diferente de -1*/
			cout<<"\n Foi eliminado o elemento "<< v << " da pilha \n"; /*Imprimir Elemento Eliminado*/
		else /*Caso N�o Entre na Condi��o*/
			cout<<"\n Nao ha elementos a remover! \n"; /*Imprimir Caso N�o Haja Elementos para Remover*/
	    break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 3: /*Caso Selecione 3*/
		percorrer(p); /*Executa a Fun��o para Percorrer a Pilha*/
	    break; /*Finaliza o La�o de Repeti��o*/
	     
	  case 4: /*Caso Selecione 4*/
	  	tamP = tamanhoPilha(p); /*Vari�vel Auxiliar do Tamanho da Pilha*/
	  	if(tamP>0){ /*Caso Tam = 0*/
			cout<<"\nA pilha tem "<< tamP <<" elementos! \n\n"; /*Imprimir Tamanho da Pilha*/ 		
		}
		else{ /*Caso N�o Entre na Condi��o*/
		 	cout<<"\nA pilha esta vazia! \n\n";	 /*Imprimir Caso Pilha Vazia*/ 		
	    }
		break; /*Finaliza o La�o de Repeti��o*/

	  case 5: /*Caso Selecione 5*/
	  	liberaPilha(p); /*Executar Fun��o para Liberar a Pilha*/
		p = cria(); /*Criar Ponteiro*/	
		noP = NULL; /*Anulando o N�*/
		break; /*Finaliza o La�o de Repeti��o*/

	  default: /*Caso Selecione um Valor Inexistente*/
	   cout<<"Comando invalido\n\n"; /*Caso Selecione uma Fun��o Inv�lida*/
  }
 }while(op_pilha != 0); /*Executa o Programa Enquanto a Op��o 0 N�o For Selecionada*/
 break;	/*Finalizar La�o de Repeti��o Principal*/

/*///////////////////////////////////////////////////////////////////////////////////////*/	 

/*Para Executar as FILAS[2]*/
case 2:
	
/*Menu de Sele��o das Fun��es*/
 do{
 	cout<<"\n Escolha a Funcao a ser Executada:\n\n"; /*Imprimir T�tulo da Sele��o*/
 	cout<<"[0] Voltar\n"; /*Sair do Menu e Finalizar a Execu��o*/
 	cout<<"[1] Inserir Valores na Fila \n"; /*Inserir Novos Valores na Fila*/
 	cout<<"[2] Remover Valores da Fila \n"; /*Remover Valores da Fila*/
 	cout<<"[3] Imprimir Valores da Fila \n"; /*Imprimir Valores da Fila*/
 	cout<<"[4] Liberar Valores da Fila \n\n"; /*Liberar Mem�ria da Fila*/
 	cout<<">"; /*Campo de Digita��o*/
 	cin>>op_funcaoF; /*Armazena o Valor Escolhido na Vari�vel op_funcao*/ /*Cin Equivale a Scanf*/

/*Executar Fun��o requisitada na Sele��o*/ 
  switch(op_funcaoF){
	  case 0: /*Caso Selecione 0*/
	   liberar(noF); /*Executa a Fun��o Liberar*/
	   break; /*Finaliza o La�o de Repeti��o*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe os valores para inserir na Fila: "; /*Printar Auxiliar de Informa��o, Case: 1*/	  	
	  	cin>>valorF; /*Armazena o Valor Escolhido na Vari�vel valor*/ /*Cin Equivale a Scanf*/		
		noF = inserir(noF, valorF); /*Executa a Fun��o Inserir (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
		// onde est�o os outros argumentos??? inserir(no, codigo, nome, idade)
		break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 2: /*Caso Selecione 2*/
	  	cout<<"\n Informe o Valor da Fila para Remover: "; /*Printar Auxiliar de Informa��o, Case: 2*/ 	
	  	cin>>valorF; /*Armazena o Valor Escolhido na Vari�vel codigo*/ /*Cin Equivale a Scanf*/
		noF = remover(noF, valorF); /*Executa a Fun��o Remover (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
	    break; /*Finaliza o La�o de Repeti��o*/
	  
	  case 3: /*Caso Selecione 3*/
		percorrer(noF); /*Executa a Fun��o Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
	    break; /*Finaliza o La�o de Repeti��o*/
	   
	  case 4: /*Caso Selecione 4*/
	  	liberar(noF); /*Executa a Fun��o Liberar (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usu�rio)*/
		noF = NULL; /*Zera os Valores Amazenados no Ponteiro Liberando a Mem�ria*/
		break; /*Finaliza o La�o de Repeti��o*/
					     
	  default: /*Caso Selecione um Valor Inexistente*/
	   printf("Comando invalido\n\n"); /*Caso Selecione uma Fun��o Inv�lida*/
   }
 }while(op_funcaoF != 0); /*Executa o Programa Enquanto a Op��o 0 N�o For Selecionada*/
 
/*///////////////////////////////////////////////////////////////////////////////////////*/	 

/*Para Executar as �RVORES[3]*/ 	
case 3:
	
/*Menu de Sele��o das Fun��es*/
do
	{
		/*Executar Fun��o requisitada na Sele��o*/ 
		opcaoA = menu();
		switch(opcaoA){
            case 0: /*Caso Valor Informado Seja 0*/               
			exit(0); /*Finalizar Processo*/
            break; /*Finaliza o La�o de Repeti��o*/

			case 1: /*Caso Valor Informado Seja 1*/ 
			cout<<"Digite -1 para terminar\n"; /*Imprime Informa��o em Tela*/
			/*Repeti��o para Informar Valores*/
			do{
				cout<<"Digite um numero: ";
				cin>>n; /*Receber Valor Informado*/
				if(n!=-1){ /*Inicio de Condi��o*/
					insere(n, &raiz); /*Caso Par�metro da Condi��o Seja Atendido*/
				}
			}while (n!=-1);
			break; /*Finaliza o La�o de Repeti��o*/
			
			case 2: /*Caso Valor Informado Seja 2*/ 
			cout<<"------> Pre-Ordem <------\n"; /*Imprime Informa��o da Fun��o Sendo Executada em Tela*/
			preordem(raiz); /*Inicia a Fun��o preordem da �rvore*/
			break; /*Finaliza o La�o de Repeti��o*/
			
			case 3: /*Caso Valor Informado Seja 3*/ 
			cout<<"------> Em-Ordem <------\n"; /*Imprime Informa��o da Fun��o Sendo Executada em Tela*/
			emordem(raiz); /*Inicia a Fun��o emordem da �rvore*/
			break; /*Finaliza o La�o de Repeti��o*/
			
			case 4: /*Caso Valor Informado Seja 4*/ 
			cout<<"------> Pos-Ordem <------\n"; /*Imprime Informa��o da Fun��o Sendo Executada em Tela*/
			posordem(raiz); /*Inicia a Fun��o posordem da �rvore*/
			break; /*Finaliza o La�o de Repeti��o*/
			
			case 5: /*Caso Valor Informado Seja 5*/ 
			consultarDetalhes(raiz); /*Inicia a Fun��o consultarDetalhes da �rvore*/
			break; /*Finaliza o La�o de Repeti��o*/

			case 6: /*Caso Valor Informado Seja 6*/ 
			b=contarNos(raiz); /*Inicia a Fun��o contarNos da �rvore*/
			cout<<"  A arvore possui " << b <<" nos!\n"; /*Imprime Informa��o da Fun��o Sendo Executada em Tela*/
			break; /*Finaliza o La�o de Repeti��o*/
			
			case 7: /*Caso Valor Informado Seja 7*/ 
			cout<<"ARVORE BINARIA\n"; /*Imprime Informa��o da Fun��o Sendo Executada em Tela*/
			imprime(raiz,0); /*Inicia a Fun��o para Imprimir Valores da �rvore*/
			break; /*Finaliza o La�o de Repeti��o*/
			
			case 8: /*Caso Valor Informado Seja 8*/ 
			cout<<"REMOVE NO DA ARVORE BINARIA\n"; /*Imprime Informa��o da Fun��o Sendo Executada em Tela*/
			cout<<"\nInforme a chave do NO que deseja remover:"; /*Imprime Informa��o para Remover uma Chave de N�*/
			cin>>rm; /*Receber Valor Informado*/
			removeNo(raiz,rm); /*Inicia a Fun��o removeNo da �rvore*/
			break; /*Finaliza o La�o de Repeti��o*/
			
			default: /*Caso Selecione um Valor Inexistente*/
            system("cls"); /*Caso Selecione um Valor Inexistente*/
            cout<<"opcao nao existe! tente novamente";   /*Caso Selecione uma Fun��o Inv�lida*/          
			break; /*Finaliza o La�o de Repeti��o*/
		}
	}while(opcaoA!=0); /*Executa o Programa Enquanto a Op��o 0 N�o For Selecionada*/		
 break;	/*Finalizar La�o de Repeti��o Principal*/
 
/*///////////////////////////////////////////////////////////////////////////////////////*/ 
 			
default: /*Caso Selecione um Valor Inexistente*/
    cout<<"Comando invalido\n\n"; /*Caso Selecione uma Fun��o Inv�lida*/
  }
 }while(opcao != 0); /*Executa o Programa Enquanto a Op��o 0 N�o For Selecionada*/

return 0; /*Finalizar o Programa*/
}

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUN��ES PARA PILHAS[1]*/

/*Cria��o das Pilhas*/
Pilha *cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha)); /*Aloca��o Din�mica das Pilhas*/
	p->topo = NULL; /*Declarando o Valor como Nulo*/
	return p;/*Retornar o Valor do Ponteiro*/
}

/*Fun��o Push da Pilhas*/
void push(Pilha *p, int v){
	Lista *novo = (Lista*)malloc(sizeof(Lista)); /*Aloca��o Din�mica para Lista do Push*/
	novo->info = v; /*Agregando o valor a V*/
	novo->prox = p->topo; /*Agregando o Valor a P*/
	p->topo = novo; /*Agregando o Valor de P topo a Novo*/
}

/*Fun��o Pop das Pilhas*/
int pop(Pilha *p){
	Lista *t; /*Ponteiro Auxiliar T da Lista para Pilhas*/
	int v; /*Declara��o da Vari�vel Inteira V*/
	
	if (p->topo == NULL){ /*Caso o Valor de P Topo seja Nulo*/
		cout<<"Pilha vazia"; /*Imprimir Informa��o Sobre a Pilha*/
		return -1; /*Retonrar a -1*/
	}
	else{ /*Caso N�o Atenda a Condicional Anterior*/
		t = p->topo; /*Igualando Valores*/
		v = t->info; /*Igualando Valores*/
		p->topo = t->prox; /*Igualando Valores*/
		free(t); /*Libera a Mem�ria*/
		return v; /*Retorna o Valor de V*/		
	}
}

/*Fun��o para Liberar as Pilhas*/
void liberaPilha(Pilha *p){
	Lista *aux = p->topo; /*Ponteiro Auxiliar do Tipo Lista para Reconhecer o Ponteiro da Pilha*/
	while(aux != NULL){ /*Condicional para Liberar as Informa��es da Pilha*/
		Lista *aux2 = aux->prox; /*Declara��o de Auxiliares em Lista para Pilhas*/
		free(aux); /*Liberar Mem�ria*/
		aux = aux2; /*Igualando Auxiliares*/
	}
	free(p); /*Liberar Mem�ria*/
}

/*Fun��o para Percorrer os Valores da Pilha*/
void percorrer(Pilha *p){
	Lista *aux; /*Declara��o do Ponteiro Auxiliar das Listas*/
	int tam = 0; /*Declara��o da Vari�vel Auxiliar Inteira*/
	if(p->topo!=NULL){ /*Caso a Pilha Tenha Valores*/
	
		for(aux = p->topo; aux!= NULL; aux = aux->prox){ /*Repeti��o para Percorrer a Pilha*/
				cout<<"info = " << aux->info << "\n"; /*Imprimir o Valor*/
		}
	}
	else{ /*Caso N�o Atenda a Condicional Anterior*/
		cout<<"\n\n A pilha esta vazia!\n\n"; /*Imrpimir Informa��o Caso N�o Atenda a Condicional Anterior*/
	}
}

/*Fun��o para Ver o Tamanho das Pilhas*/
int tamanhoPilha(Pilha *p){
	Lista *aux; /*Ponteiro Auxiliar no Formato Lista*/
	int tam = 0; /*Declara��o da Vari�vel Inteira Tam*/
	for(aux = p->topo; aux!= NULL; aux = aux->prox){ /*Repeti��o para C�lculo do Tamanho das Pilhas*/
		tam++; /*Var�avel que Contabiliza as Pilhas*/
	}
	return tam;	/*Retorno do Valor do Tamanho das Pilhas*/
}

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUN��ES PARA �RVORES[3]*/

/*Fun��o VaziaArvore*/
void vaziaArvore(No *raiz){
	if (raiz == NULL){ /*Inicio de Condi��o*/
		cout<<"   A arvore esta vazia\n\n"; /*Imprimir Texto de Informa��o em Tela*/
	}
	else { /*Caso Condi��o Anterior N�o Seja Atendida*/
		cout<<"   A arvore nao esta vazia\n\n"; /*Imprimir Texto de Informa��o em Tela*/
	}
}

/*Fun��o de Insers�o*/
void insere (int x, No **p){

	if (*p==NULL){ /*Inicio de Condi��o*/
		*p=(No *)malloc(sizeof(No)); /*Aloca��o de Mem�ria Din�mica para a �rvore*/
		(*p)->chave=x;
		(*p)->dir=NULL;
		(*p)->esq=NULL;
		(*p)->pai = auxPai;
		(*p)->cont=0;
		(*p)->cont++;
	}
	else{ /*Caso Condi��o Anterior N�o Seja Atendida*/
		if (x<(*p)->chave){ /*Inicio de Condi��o*/
			if((*p)->esq == NULL) /*Condicional caso Nulo*/
				auxPai = *p;
			insere(x, &(*p)->esq);
		}
		if(x>(*p)->chave){ /*Inicio de Condi��o*/
			if((*p)->dir == NULL) /*Condicional caso Nulo*/
				auxPai = *p;
			insere(x, &(*p)->dir);
		}
		if(x == (*p)->chave){ /*Inicio de Condi��o*/
			if((*p)->dir == NULL) /*Condicional caso Nulo*/
				auxPai = *p; /*Igualando Auxiliar ao Ponteiro*/
			insere(x, &(*p)->dir); /*Agregando valor a Insers�o na �rvore*/
		}
	}
}

/*Fun��o para Contabilizar os N�s*/
int contarNos(No *p){
	if(p == NULL) /*Inicio de Condi��o*/
		return 0; /*Retornar o valor 0*/
	else /*Caso Condi��o Anterior N�o Seja Atendida*/
		return 1 + contarNos(p->esq) + contarNos(p->dir); /*Retornar N�s Contados*/
}

/*Fun��o para Buscar os N�s*/
No *busca(No *arvore, int x){
	if (arvore == NULL) /*Inicio de Condi��o*/
		return NULL; /*Retornar Valor Nulo*/
	if (x == arvore->chave) /*Inicio de Condi��o*/
		return arvore; /*Retornar �rvore*/
	if (x < arvore->chave) /*Inicio de Condi��o*/
		return busca(arvore->esq, x); /*Retornar Busca da �rvore*/
	else /*Caso Condi��o Anterior N�o Seja Atendida*/
		return busca(arvore->dir, x); /*Retornar Busca*/
}

/*Fun��o para Consultar um Valor*/
void consultarValor(No* raiz){
	int num; /*Declara��o de Auxiliar Inteira*/
	No* aux; /*Declara��o de Ponteiro Auxiliar para o N�*/
	cout<<"Digite o numero procurado: "; /*Imprimir Texto de Informa��o em Tela*/
	cin>>num; /*Escaner do N�mero Procurado*/

	aux = busca(raiz, num); /*Auxiliar para a Busca do Valor na Raiz*/
	if (aux == NULL) /*Inicio de Condi��o*/
		cout<<"Nao encontrado!\n"; /*Imprimir Texto de Informa��o em Tela*/
	else{ /*Caso Condi��o Anterior N�o Seja Atendida*/	
		cout<<"Encontrado!\n"; /*Imprimir Texto de Informa��o em Tela*/
		cout<<"O numero "<<num<<" foi repetido "<<aux->cont<<" vezes\n"; /*Imprimir Texto de Informa��o em Tela*/
	}
}

/*Fun��o para Consultar Detalhes da �rvore*/
void consultarDetalhes(No *raiz){
	int num; /*Declara��o de Auxiliar Inteira*/
	No* aux; /*Declara��o de Ponteiro Auxiliar para o N�*/
	cout<<"Digite o numero procurado: "; /*Imprimir Texto de Informa��o em Tela*/
	cin>>num; /*Escaner do N�mero Procurado*/
	aux = busca(raiz, num); /*Auxiliar para a Busca do Valor na Raiz*/
	if (aux == NULL) /*Inicio de Condi��o*/
		cout<<"Valor Nao encontrado!\n"; /*Imprimir Texto de Informa��o em Tela*/
	else{ /*Caso Condi��o Anterior N�o Seja Atendida*/
		cout<<"Valor Encontrado!\n"; /*Imprimir Texto de Informa��o em Tela*/
		if(aux->pai == NULL){ /*Inicio de Condi��o*/
			cout<<"O No que contem o valor "<<num <<" e a raiz da arvore.\n"; /*Imprimir Texto de Informa��o em Tela*/
			if(aux->esq != NULL) /*Inicio de Condi��o*/
				cout<<"Valor contido no No filho a esquerda: "<< aux->esq->chave<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
			if(aux->dir != NULL) /*Inicio de Condi��o*/
				cout<<"Valor contido no No filho a direito: "<< aux->dir->chave<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
		}
		if((aux->esq == NULL)&&(aux->dir == NULL)&&(aux->pai != NULL)){ /*Inicio de Condi��o*/
			cout<<"O No que contem o valor e uma folha da arvore: "<< num<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
			cout<<"Valor contido no No pai: "<< aux->pai->chave<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
		}
		if(((aux->esq != NULL)||(aux->dir != NULL))&&(aux->pai != NULL)){ /*Inicio de Condi��o*/
			cout<<"O No que contem o valor " <<num<<" e um no interno a arvore.\n"; /*Imprimir Texto de Informa��o em Tela*/
			cout<<"Valor contido no No pai: "<< aux->pai->chave<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
			if(aux->esq != NULL) /*Inicio de Condi��o*/
				cout<<"Valor contido no No filho a esquerda: "<< aux->esq->chave<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
			if(aux->dir != NULL) /*Inicio de Condi��o*/
				cout<<"Valor contido no No filho a direito: "<< aux->dir->chave<<"\n"; /*Imprimir Texto de Informa��o em Tela*/
		}
	}
}

/*Fun��o para Imprimir Valores da �rvore*/
void imprime(No *p, int nivel){
	int i; /*Declara��o de Auxiliar Inteira*/
	if(p == NULL) /*Inicio de Condi��o*/
		return; /*Retornar ao Menu*/
	imprime(p->dir, nivel+1); /*Imprimir N�veis*/
	for(i=0;i<nivel;i++) /*Estrutura de Repeti��o para Passar os N�veis*/
		cout<<"      ";
	cout<<p->chave<<"\n\n"; /*Imprimir Texto de Informa��o em Tela*/
	imprime(p->esq,nivel+1); /*Imprimir N�veis*/
}

/*Fun��o para Consultar N�vel da �rvore*/
void consultaNivel(No *p){
	int i, nivel; /*Declara��o de Auxiliar Inteira*/
	if(p == NULL) /*Inicio de Condi��o*/
		return; /*Retornar Nulo*/
	imprime(p->dir, nivel+1); /*Imprimir Informa��o em Tela*/
	for(i=0;i<nivel;i++) /*Inicio do La�o de Repeti��o*/
		cout<<"      "; /*Impress�o em Branco*/
	cout<<"\n\n"<<p->chave; /*Imprimir Texto de Informa��o em Tela*/
	imprime(p->esq,nivel+1); /*Imprimir Informa��o em Tela*/
}

/*Fun��o preordem*/
void preordem (No *arvore){
	if(arvore != NULL){ /*Inicio de Condi��o*/
		cout<<"\n "<<arvore->chave; /*Imprimir Texto de Informa��o em Tela*/
		preordem(arvore->esq); /*Executar Impress�o na Ordem Requisitada*/
		preordem(arvore->dir); /*Executar Impress�o na Ordem Requisitada*/
	}
}

/*Fun��o emordem*/
void emordem(No *arvore){
	if(arvore != NULL){ /*Inicio de Condi��o*/
		emordem(arvore->esq); /*Executar Impress�o na Ordem Requisitada*/
		cout<<"\n "<<arvore->chave; /*Imprimir Texto de Informa��o em Tela*/
		emordem(arvore->dir); /*Executar Impress�o na Ordem Requisitada*/
	}
}

/*Fun��o posordem*/
void posordem(No *arvore){
	if(arvore != NULL){ /*Inicio de Condi��o*/
		posordem(arvore->esq); /*Executar Impress�o na Ordem Requisitada*/
		posordem(arvore->dir); /*Executar Impress�o na Ordem Requisitada*/
		cout<<"\n "<<arvore->chave; /*Imprimir Texto de Informa��o em Tela*/
	}
}

/*Fun��o para Remover um N�*/
No *removeNo(No *raiz, int x){
 if (raiz == NULL) /*Inicio de Condi��o*/
    return NULL; /*Retornar um Valor Nulo*/
 else if (raiz->chave > x) /*Caso Condi��o Anterior N�o Seja Atendida*/
    raiz->esq = removeNo(raiz->esq, x); /*Remover Valores da Raiz*/
 else if (raiz->chave < x) /*Caso Condi��o Anterior N�o Seja Atendida*/
    raiz->dir = removeNo(raiz->dir, x); /*Remover Valores da Raiz*/
 else { /*Caso Condi��o Anterior N�o Seja Atendida*/

    if (raiz->esq == NULL && raiz->dir == NULL) { /*Inicio de Condi��o*/
       free (raiz); /*Liberar Mem�ria*/
       raiz = NULL;
    }

    else if (raiz->esq == NULL) { /*Caso Condi��o Anterior N�o Seja Atendida*/
       No *t = raiz;
       raiz = raiz->dir;
       free (t); /*Liberar Mem�ria*/
    }

    else if (raiz->dir == NULL) { /*Caso Condi��o Anterior N�o Seja Atendida*/
       No *t = raiz;
       raiz = raiz->esq;
       free (t); /*Liberar Mem�ria*/
    }

    else { /*Caso Condi��o Anterior N�o Seja Atendida*/
       No *f = raiz->esq; /*Declara��o de Ponteiro Auxiliar*/
       while (f->dir != NULL) { /*Enquanto Valor for Diferente de Nulo essa Fun��o � Executada*/
          f = f->dir;
       }
       raiz->chave = f->chave;
       f->chave = x;
       raiz->esq = removeNo(raiz->esq, x);
    }
 }
return raiz; /*Retornar Raiz*/
}

/*Fun��o para Imprimir Menu de Op��es*/
int menu()
{
	int op; /*Vari�vel Inteira para Receber o Valor de Escolha do Menu*/
	cout<<"\nEscolha a Funcao a ser Executada:\n\n"; /*Imprimir T�tulo do Menu*/
	cout<<"[0] Voltar\n"; /*Voltar ao Menu Anterior*/
	cout<<"[1] Inserir valor\n"; /*Inserir Valores na �rvore*/
	cout<<"[2] Imprimir pre ordem\n"; /*Imprimir a �rvore em Pre Ordem*/
	cout<<"[3] Imprimir in-ordem\n"; /*Imprimir a �rvore em in-Ordem*/
	cout<<"[4] Imprimir pos ordem\n"; /*Imprimir a �rvore em P�s Ordem*/
	cout<<"[5] Consulta detalhada\n"; /*Consultar Detalhes da �rvore*/
	cout<<"[6] Quantidades de nos da arvore\n"; /*Consultar a Quantidade de N�s na �rvore*/
	cout<<"[7] Imprimir arvore\n"; /*Imprimir Valores da �rvore*/
	cout<<"[8] Remover no da arvore\n"; /*Remover Valores da �rvore*/
	cout<<">"; /*Receber Valor Informado no Menu*/
	cin>>op; /*Escaner de Recep��o do Valor*/
	return op; /*Retornar Valor Inserido no Menu*/
}

