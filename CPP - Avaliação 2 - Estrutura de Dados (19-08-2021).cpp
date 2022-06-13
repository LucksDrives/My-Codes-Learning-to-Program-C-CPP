/*Desenvolver um programa em CPP que pergunte ao usuário o que ele deseja fazer através do seguinte menu:

0 - Sair
1 - Pilhas
2 - Filas
3 - Árvores
4 - Listas

Se o usuário escolher a opção 1, mostre o menu que executará as seguintes tarefas:

0 - Voltar ao menu principal
1 - Inserir dados na pilha
2 - excluir dados da pilha
3 - Imprimir Pilha
4 - Limpar Pilha

Se o usuário escolher a opção 2, mostre o menu que executará as seguintes tarefas:

0 - Voltar ao menu principal
1 - Inserir dados na fila
2 - excluir dados da fila
3 - Imprimir Fila
4 - Limpar Fila

Se o usuário escolher a opção 3, mostre o menu que executará as seguintes tarefas:

0 - Voltar ao menu principal
1 - Inserir dados na árvore
2 - excluir dados da árvore
3 - Imprimir árvore
4 - Mostrar o nível da árvore
5 - imprimir os elementos da árvores EM ORDEM.
6 - Limpar árvore*/

#include<iostream> /*Incluir Biblioteca "iostream" para Uso das Funções do C++*/
using namespace std; /*Incluído para Uso de Comandos C++, como "Free"*/
#include <stdlib.h> /*Incluir Biblioteca Padrão "stdlib.h" para Uso das Funções do C*/
#include <string.h> /*Incluir Biblioteca Padrão para C*/

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*Criação de Uma Estrutura de Listas Base*/
struct lista{
	int info; /*Declaração da Variável Inteira Auxiliar para Pilha*/
	struct lista *prox; /*Declaração de Ponteiro*/
};

typedef struct lista Lista; /*Definição da Estrutura de Listas*/

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUNÇÕES PARA PILHAS[1]*/

/*Criação da Estrutura da Pilha*/
struct pilha{
	Lista *topo; /*Declaração do Ponteiro Auxiliar de Lista para Pilha*/
};

typedef struct pilha Pilha; /*Definição da Estrutura da Pilha*/

/*Declaração das Funções da Pilha*/
Pilha *cria(void); /*Criar Pilha*/
void push(Pilha *p, int v); /*Função Push, Auxiliar para Pilhas*/
int pop(Pilha *p); /*Função Pop, Auxiliar para Pilhas*/
void liberaPilha(Pilha *p); /*Liberar Valores da Pilha*/
void percorrer(Pilha *p); /*Percorrer Valores da Pilha*/
int tamanhoPilha(Pilha *p); /*Verificar Tamanho da Pilha*/

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUNÇÕES PARA FILAS[2]*/

/*Criar Estrutura de Fila*/
struct Fila{
 int valorF; /*Declaração da Variável Interira "Código"*/
 struct Fila *prox; /*Declaração da Variável Fila para Ponteiro *prox"*/
}; typedef struct Fila Fila; /*Definir o Tipo de Estrutura da Fila*/


/*Função Inserir Item na Fila*/
Fila *inserir(Fila *noF, int valorF){	
	Fila *novo = (Fila*)malloc(sizeof(Fila)); /*Função de Alocação Dinâmica de Memória*/
	novo->valorF = valorF; /*Armazenar Informação do Código na Fila*/
	novo->prox = noF; /*Armazenar Informação do Código na Fila*/
	return novo; /*Retorna o Novo Valor Inserido na Fila*/
}

/*Função Remover Item da Fila*/
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
		return noF; // não achou, retorna a Fila original
	}
	if (anterior == NULL){
		noF = p->prox; // caso 1
	}
	else{
		anterior->prox = p->prox; // caso 2
	}
	free(p); /*Libera o Espaço que os Valores Anteriores Armazenavam, Liberando o Uso da Memória*/
	return noF; /*Retornar Ponteiro*/
}

/*Função Percorrer Fila*/
void percorrer(Fila *noF){
	Fila *p; /*Receber Variável do Ponteiro "no"*/
	
	cout<<"Impressao das Filas\n\n";
	 	
	/*Laço de Repetição para Percorrer os Valores da Fila*/
	for(p = noF; p != NULL; p = p->prox){
			cout<<"Valor = " << p->valorF << "\n";
			cout<<"ponteiro = "<< p << "\n";
			cout<<"prox = " << p->prox << "\n";
	}
}

/*Função Liberar Memória*/
void liberar (Fila *noF){
	Fila *p = noF; /*Receber Variável do Ponteiro "no"*/
	
	/*Laço de Repetição para Setar Null nas Informações Armazenadas no Ponteiro*/
	while (p != NULL){
		Fila *proximo = p->prox;
		free(p); /*Libera o Espaço que os Valores Anteriores Armazenavam, Liberando o Uso da Memória*/
		p = proximo;
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////*/

/*FUNÇÕES PARA ÁRVORES[3]*/

int quantidadeNos = 0; /*Variável Pré Definida para Contabilizar os Nós nas Arvores*/

/*Estrutura de Criação de um Nó Auxiliar para Raiz da Árvore*/
struct no {
	int chave; /*Auxiliar Inteira para o Valor Chave da Árvore*/
	int cont; /*Auxiliar Inteira para o Contador da Árvore*/
	struct no *esq, *dir, *pai; /*Declaração dos Ponteiros*/
};

typedef struct no No; /*Definição da Estrutura*/
 No *auxPai = NULL; /*Declaração do Ponteiro para o Nó como um Valor Nulo*/

/*Declaração das Funções de Árvores Binárias*/
void vaziaArvore(No *raiz);
void insere (int x, No **p); /*Função para Insersão dos Valores na Árvore*/
int contarNos(No *p); /*Função para Contabilizar o Número de Nós da Árvore*/
No *busca(No *arvore, int x); /*Função de Busca para Determinado Valor da Árvore*/
void consultarValor(No* raiz); /*Função para Consultar Valores da Árvore*/
void consultarDetalhes(No* raiz); /*Função para Constultar Detalhes da Árvore*/
void imprime(No *p, int nivel); /*Função para Imprimir os Valores da Árvore*/
void consultaNivel(No *p); /*Função para Consultar o Nível da Árvore*/
void preordem (No *arvore); /*Função preordem, para Bifurcação da Árvore*/
void emordem(No *arvore); /*Função emordem, para Bifurcação da Árvore*/
void posordem(No *arvore); /*Função posordem, para Bifurcação da Árvore*/
No *removeNo(No *raiz, int x); /*Função de Remoção do Nó*/
int menu(); /*Função Menu*/

/*Inicio do Programa - Main*/
int main(){
	int opcao; /*Declaração da Variável Inteira para Definir a Função a Ser Executada*/
	
	/*Declaração dos Auxiliares das Pilhas*/
	int op_pilha, valorP, tamP; /*Declaração dos Valores Inteiros*/
	Pilha *p; /*Declaração do Ponteiro para a Pilha*/
	p = cria(); /*Criação do Ponteiro*/
	Lista *noP = NULL; /*Declaração do Ponteiro de Listas Auxiliar para Pilhas*/
	
	/*Declaração dos Auxiliares das Filas[2]*/
	int op_funcaoF, valorF; /*op_funcao (variável que Recebe e Armazena a Opção Requisitada para Escolha da Função)*/ /*codigo (Variável que Recebe o Código para a Fila)*/
	Fila *noF = NULL; /*no (Ponteiro Auxiliar para Endereçar o Valor Informado)*/
	
	/*Declaração dos Auxiliares das Árvores[3]*/	
	int n,rm,a,b;
	No *raiz, *aux;
	raiz = NULL;
	int opcaoA;
	
/*Abertura do Laço de Repetição Principal do Código*/	
	do{
	cout<<"\n Selecionar Funcao:\n\n"; /*Imprimir Título da Seleção*/
 	cout<<"[0] Sair\n"; /*Sair do Menu e Finalizar a Execução*/
 	cout<<"[1] Pilhas \n"; /*Opção para Executar as Pilhas*/
 	cout<<"[2] Filas \n"; /*Opção para Executar as Filas*/
 	cout<<"[3] Arvores \n"; /*Opção para Executar as Arvores*/
 	cout<<">"; /*Campo de Digitação*/
 	cin>>opcao; /*Armazena o Valor Escolhido na Variável opcao*/ /*Cin Equivale a Scanf*/

/*Executar Função requisitada na Seleção*/ 
  switch(opcao){

/*Para Finalizar o Programa*/  	
case 0: 
 break;	/*Finalizar Laço de Repetição Principal*/

/*///////////////////////////////////////////////////////////////////////////////////////*/	
		
/*Para Executar as PILHAS[1]*/
case 1:

/*Menu de Seleção das Funções*/
 do{
 	cout<<"\n Escolha a Funcao a ser Executada:\n\n"; /*Imprimir Informações do Menu*/
 	cout<<"0 - Voltar\n"; /*Finalizar Laço*/
 	cout<<"1 - Adicionar item na Pilha \n"; /*Adiciona um Item a Pilha*/
 	cout<<"2 - Remover item da Pilha \n"; /*Remove um Item da Pilha*/
 	cout<<"3 - Imprimir Pilha \n"; /*Imprime Valores da Pilha*/
 	cout<<"4 - Tamanho da Pilha \n"; /*Imprime Tamanho da Pilha*/
 	cout<<"5 - Liberar Pilha \n\n"; /*Libera a Pilha*/
 	cout<<">"; /*Campo de Digitação*/
 	cin>>op_pilha; /*Armazena Valor da Opção*/

/*Executar Função requisitada na Seleção*/ 
  switch(op_pilha){
	  case 0: /*Caso Selecione 0*/
	   liberaPilha(p); /*Executa a Função para Liberar a Pilha*/
	   break; /*Finaliza o Laço de Repetição*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe o valor para inserir na pilha: \n"; /*Imprimir o Texto*/
	  	cin>>valorP; /*Armazenar o Valor a ser Inserido na Pilha*/
		push( p, valorP);
		break; /*Finaliza o Laço de Repetição*/
	  
	  case 2: /*Caso Selecione 2*/
	  	int v; /*Declaração de Valor Auxiliar*/
		v = pop(p); /*Igualando V ao Ponteiro*/
		if(v != -1) /*Caso V Diferente de -1*/
			cout<<"\n Foi eliminado o elemento "<< v << " da pilha \n"; /*Imprimir Elemento Eliminado*/
		else /*Caso Não Entre na Condição*/
			cout<<"\n Nao ha elementos a remover! \n"; /*Imprimir Caso Não Haja Elementos para Remover*/
	    break; /*Finaliza o Laço de Repetição*/
	  
	  case 3: /*Caso Selecione 3*/
		percorrer(p); /*Executa a Função para Percorrer a Pilha*/
	    break; /*Finaliza o Laço de Repetição*/
	     
	  case 4: /*Caso Selecione 4*/
	  	tamP = tamanhoPilha(p); /*Variável Auxiliar do Tamanho da Pilha*/
	  	if(tamP>0){ /*Caso Tam = 0*/
			cout<<"\nA pilha tem "<< tamP <<" elementos! \n\n"; /*Imprimir Tamanho da Pilha*/ 		
		}
		else{ /*Caso Não Entre na Condição*/
		 	cout<<"\nA pilha esta vazia! \n\n";	 /*Imprimir Caso Pilha Vazia*/ 		
	    }
		break; /*Finaliza o Laço de Repetição*/

	  case 5: /*Caso Selecione 5*/
	  	liberaPilha(p); /*Executar Função para Liberar a Pilha*/
		p = cria(); /*Criar Ponteiro*/	
		noP = NULL; /*Anulando o Nó*/
		break; /*Finaliza o Laço de Repetição*/

	  default: /*Caso Selecione um Valor Inexistente*/
	   cout<<"Comando invalido\n\n"; /*Caso Selecione uma Função Inválida*/
  }
 }while(op_pilha != 0); /*Executa o Programa Enquanto a Opção 0 Não For Selecionada*/
 break;	/*Finalizar Laço de Repetição Principal*/

/*///////////////////////////////////////////////////////////////////////////////////////*/	 

/*Para Executar as FILAS[2]*/
case 2:
	
/*Menu de Seleção das Funções*/
 do{
 	cout<<"\n Escolha a Funcao a ser Executada:\n\n"; /*Imprimir Título da Seleção*/
 	cout<<"[0] Voltar\n"; /*Sair do Menu e Finalizar a Execução*/
 	cout<<"[1] Inserir Valores na Fila \n"; /*Inserir Novos Valores na Fila*/
 	cout<<"[2] Remover Valores da Fila \n"; /*Remover Valores da Fila*/
 	cout<<"[3] Imprimir Valores da Fila \n"; /*Imprimir Valores da Fila*/
 	cout<<"[4] Liberar Valores da Fila \n\n"; /*Liberar Memória da Fila*/
 	cout<<">"; /*Campo de Digitação*/
 	cin>>op_funcaoF; /*Armazena o Valor Escolhido na Variável op_funcao*/ /*Cin Equivale a Scanf*/

/*Executar Função requisitada na Seleção*/ 
  switch(op_funcaoF){
	  case 0: /*Caso Selecione 0*/
	   liberar(noF); /*Executa a Função Liberar*/
	   break; /*Finaliza o Laço de Repetição*/
	   
	  case 1: /*Caso Selecione 1*/
	  	cout<<"\n Informe os valores para inserir na Fila: "; /*Printar Auxiliar de Informação, Case: 1*/	  	
	  	cin>>valorF; /*Armazena o Valor Escolhido na Variável valor*/ /*Cin Equivale a Scanf*/		
		noF = inserir(noF, valorF); /*Executa a Função Inserir (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
		// onde estão os outros argumentos??? inserir(no, codigo, nome, idade)
		break; /*Finaliza o Laço de Repetição*/
	  
	  case 2: /*Caso Selecione 2*/
	  	cout<<"\n Informe o Valor da Fila para Remover: "; /*Printar Auxiliar de Informação, Case: 2*/ 	
	  	cin>>valorF; /*Armazena o Valor Escolhido na Variável codigo*/ /*Cin Equivale a Scanf*/
		noF = remover(noF, valorF); /*Executa a Função Remover (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
	    break; /*Finaliza o Laço de Repetição*/
	  
	  case 3: /*Caso Selecione 3*/
		percorrer(noF); /*Executa a Função Percorrer (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
	    break; /*Finaliza o Laço de Repetição*/
	   
	  case 4: /*Caso Selecione 4*/
	  	liberar(noF); /*Executa a Função Liberar (Manda o Ponteiro Auxiliar e o Valor Informado pelo Usuário)*/
		noF = NULL; /*Zera os Valores Amazenados no Ponteiro Liberando a Memória*/
		break; /*Finaliza o Laço de Repetição*/
					     
	  default: /*Caso Selecione um Valor Inexistente*/
	   printf("Comando invalido\n\n"); /*Caso Selecione uma Função Inválida*/
   }
 }while(op_funcaoF != 0); /*Executa o Programa Enquanto a Opção 0 Não For Selecionada*/
 
/*///////////////////////////////////////////////////////////////////////////////////////*/	 

/*Para Executar as ÁRVORES[3]*/ 	
case 3:
	
/*Menu de Seleção das Funções*/
do
	{
		/*Executar Função requisitada na Seleção*/ 
		opcaoA = menu();
		switch(opcaoA){
            case 0: /*Caso Valor Informado Seja 0*/               
			exit(0); /*Finalizar Processo*/
            break; /*Finaliza o Laço de Repetição*/

			case 1: /*Caso Valor Informado Seja 1*/ 
			cout<<"Digite -1 para terminar\n"; /*Imprime Informação em Tela*/
			/*Repetição para Informar Valores*/
			do{
				cout<<"Digite um numero: ";
				cin>>n; /*Receber Valor Informado*/
				if(n!=-1){ /*Inicio de Condição*/
					insere(n, &raiz); /*Caso Parâmetro da Condição Seja Atendido*/
				}
			}while (n!=-1);
			break; /*Finaliza o Laço de Repetição*/
			
			case 2: /*Caso Valor Informado Seja 2*/ 
			cout<<"------> Pre-Ordem <------\n"; /*Imprime Informação da Função Sendo Executada em Tela*/
			preordem(raiz); /*Inicia a Função preordem da Árvore*/
			break; /*Finaliza o Laço de Repetição*/
			
			case 3: /*Caso Valor Informado Seja 3*/ 
			cout<<"------> Em-Ordem <------\n"; /*Imprime Informação da Função Sendo Executada em Tela*/
			emordem(raiz); /*Inicia a Função emordem da Árvore*/
			break; /*Finaliza o Laço de Repetição*/
			
			case 4: /*Caso Valor Informado Seja 4*/ 
			cout<<"------> Pos-Ordem <------\n"; /*Imprime Informação da Função Sendo Executada em Tela*/
			posordem(raiz); /*Inicia a Função posordem da Árvore*/
			break; /*Finaliza o Laço de Repetição*/
			
			case 5: /*Caso Valor Informado Seja 5*/ 
			consultarDetalhes(raiz); /*Inicia a Função consultarDetalhes da Árvore*/
			break; /*Finaliza o Laço de Repetição*/

			case 6: /*Caso Valor Informado Seja 6*/ 
			b=contarNos(raiz); /*Inicia a Função contarNos da Árvore*/
			cout<<"  A arvore possui " << b <<" nos!\n"; /*Imprime Informação da Função Sendo Executada em Tela*/
			break; /*Finaliza o Laço de Repetição*/
			
			case 7: /*Caso Valor Informado Seja 7*/ 
			cout<<"ARVORE BINARIA\n"; /*Imprime Informação da Função Sendo Executada em Tela*/
			imprime(raiz,0); /*Inicia a Função para Imprimir Valores da Árvore*/
			break; /*Finaliza o Laço de Repetição*/
			
			case 8: /*Caso Valor Informado Seja 8*/ 
			cout<<"REMOVE NO DA ARVORE BINARIA\n"; /*Imprime Informação da Função Sendo Executada em Tela*/
			cout<<"\nInforme a chave do NO que deseja remover:"; /*Imprime Informação para Remover uma Chave de Nó*/
			cin>>rm; /*Receber Valor Informado*/
			removeNo(raiz,rm); /*Inicia a Função removeNo da Árvore*/
			break; /*Finaliza o Laço de Repetição*/
			
			default: /*Caso Selecione um Valor Inexistente*/
            system("cls"); /*Caso Selecione um Valor Inexistente*/
            cout<<"opcao nao existe! tente novamente";   /*Caso Selecione uma Função Inválida*/          
			break; /*Finaliza o Laço de Repetição*/
		}
	}while(opcaoA!=0); /*Executa o Programa Enquanto a Opção 0 Não For Selecionada*/		
 break;	/*Finalizar Laço de Repetição Principal*/
 
/*///////////////////////////////////////////////////////////////////////////////////////*/ 
 			
default: /*Caso Selecione um Valor Inexistente*/
    cout<<"Comando invalido\n\n"; /*Caso Selecione uma Função Inválida*/
  }
 }while(opcao != 0); /*Executa o Programa Enquanto a Opção 0 Não For Selecionada*/

return 0; /*Finalizar o Programa*/
}

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUNÇÕES PARA PILHAS[1]*/

/*Criação das Pilhas*/
Pilha *cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha)); /*Alocação Dinâmica das Pilhas*/
	p->topo = NULL; /*Declarando o Valor como Nulo*/
	return p;/*Retornar o Valor do Ponteiro*/
}

/*Função Push da Pilhas*/
void push(Pilha *p, int v){
	Lista *novo = (Lista*)malloc(sizeof(Lista)); /*Alocação Dinâmica para Lista do Push*/
	novo->info = v; /*Agregando o valor a V*/
	novo->prox = p->topo; /*Agregando o Valor a P*/
	p->topo = novo; /*Agregando o Valor de P topo a Novo*/
}

/*Função Pop das Pilhas*/
int pop(Pilha *p){
	Lista *t; /*Ponteiro Auxiliar T da Lista para Pilhas*/
	int v; /*Declaração da Variável Inteira V*/
	
	if (p->topo == NULL){ /*Caso o Valor de P Topo seja Nulo*/
		cout<<"Pilha vazia"; /*Imprimir Informação Sobre a Pilha*/
		return -1; /*Retonrar a -1*/
	}
	else{ /*Caso Não Atenda a Condicional Anterior*/
		t = p->topo; /*Igualando Valores*/
		v = t->info; /*Igualando Valores*/
		p->topo = t->prox; /*Igualando Valores*/
		free(t); /*Libera a Memória*/
		return v; /*Retorna o Valor de V*/		
	}
}

/*Função para Liberar as Pilhas*/
void liberaPilha(Pilha *p){
	Lista *aux = p->topo; /*Ponteiro Auxiliar do Tipo Lista para Reconhecer o Ponteiro da Pilha*/
	while(aux != NULL){ /*Condicional para Liberar as Informações da Pilha*/
		Lista *aux2 = aux->prox; /*Declaração de Auxiliares em Lista para Pilhas*/
		free(aux); /*Liberar Memória*/
		aux = aux2; /*Igualando Auxiliares*/
	}
	free(p); /*Liberar Memória*/
}

/*Função para Percorrer os Valores da Pilha*/
void percorrer(Pilha *p){
	Lista *aux; /*Declaração do Ponteiro Auxiliar das Listas*/
	int tam = 0; /*Declaração da Variável Auxiliar Inteira*/
	if(p->topo!=NULL){ /*Caso a Pilha Tenha Valores*/
	
		for(aux = p->topo; aux!= NULL; aux = aux->prox){ /*Repetição para Percorrer a Pilha*/
				cout<<"info = " << aux->info << "\n"; /*Imprimir o Valor*/
		}
	}
	else{ /*Caso Não Atenda a Condicional Anterior*/
		cout<<"\n\n A pilha esta vazia!\n\n"; /*Imrpimir Informação Caso Não Atenda a Condicional Anterior*/
	}
}

/*Função para Ver o Tamanho das Pilhas*/
int tamanhoPilha(Pilha *p){
	Lista *aux; /*Ponteiro Auxiliar no Formato Lista*/
	int tam = 0; /*Declaração da Variável Inteira Tam*/
	for(aux = p->topo; aux!= NULL; aux = aux->prox){ /*Repetição para Cálculo do Tamanho das Pilhas*/
		tam++; /*Varíavel que Contabiliza as Pilhas*/
	}
	return tam;	/*Retorno do Valor do Tamanho das Pilhas*/
}

/*///////////////////////////////////////////////////////////////////////////////////////*/ 

/*FUNÇÕES PARA ÁRVORES[3]*/

/*Função VaziaArvore*/
void vaziaArvore(No *raiz){
	if (raiz == NULL){ /*Inicio de Condição*/
		cout<<"   A arvore esta vazia\n\n"; /*Imprimir Texto de Informação em Tela*/
	}
	else { /*Caso Condição Anterior Não Seja Atendida*/
		cout<<"   A arvore nao esta vazia\n\n"; /*Imprimir Texto de Informação em Tela*/
	}
}

/*Função de Insersão*/
void insere (int x, No **p){

	if (*p==NULL){ /*Inicio de Condição*/
		*p=(No *)malloc(sizeof(No)); /*Alocação de Memória Dinâmica para a Árvore*/
		(*p)->chave=x;
		(*p)->dir=NULL;
		(*p)->esq=NULL;
		(*p)->pai = auxPai;
		(*p)->cont=0;
		(*p)->cont++;
	}
	else{ /*Caso Condição Anterior Não Seja Atendida*/
		if (x<(*p)->chave){ /*Inicio de Condição*/
			if((*p)->esq == NULL) /*Condicional caso Nulo*/
				auxPai = *p;
			insere(x, &(*p)->esq);
		}
		if(x>(*p)->chave){ /*Inicio de Condição*/
			if((*p)->dir == NULL) /*Condicional caso Nulo*/
				auxPai = *p;
			insere(x, &(*p)->dir);
		}
		if(x == (*p)->chave){ /*Inicio de Condição*/
			if((*p)->dir == NULL) /*Condicional caso Nulo*/
				auxPai = *p; /*Igualando Auxiliar ao Ponteiro*/
			insere(x, &(*p)->dir); /*Agregando valor a Insersão na Árvore*/
		}
	}
}

/*Função para Contabilizar os Nós*/
int contarNos(No *p){
	if(p == NULL) /*Inicio de Condição*/
		return 0; /*Retornar o valor 0*/
	else /*Caso Condição Anterior Não Seja Atendida*/
		return 1 + contarNos(p->esq) + contarNos(p->dir); /*Retornar Nós Contados*/
}

/*Função para Buscar os Nós*/
No *busca(No *arvore, int x){
	if (arvore == NULL) /*Inicio de Condição*/
		return NULL; /*Retornar Valor Nulo*/
	if (x == arvore->chave) /*Inicio de Condição*/
		return arvore; /*Retornar Árvore*/
	if (x < arvore->chave) /*Inicio de Condição*/
		return busca(arvore->esq, x); /*Retornar Busca da Árvore*/
	else /*Caso Condição Anterior Não Seja Atendida*/
		return busca(arvore->dir, x); /*Retornar Busca*/
}

/*Função para Consultar um Valor*/
void consultarValor(No* raiz){
	int num; /*Declaração de Auxiliar Inteira*/
	No* aux; /*Declaração de Ponteiro Auxiliar para o Nó*/
	cout<<"Digite o numero procurado: "; /*Imprimir Texto de Informação em Tela*/
	cin>>num; /*Escaner do Número Procurado*/

	aux = busca(raiz, num); /*Auxiliar para a Busca do Valor na Raiz*/
	if (aux == NULL) /*Inicio de Condição*/
		cout<<"Nao encontrado!\n"; /*Imprimir Texto de Informação em Tela*/
	else{ /*Caso Condição Anterior Não Seja Atendida*/	
		cout<<"Encontrado!\n"; /*Imprimir Texto de Informação em Tela*/
		cout<<"O numero "<<num<<" foi repetido "<<aux->cont<<" vezes\n"; /*Imprimir Texto de Informação em Tela*/
	}
}

/*Função para Consultar Detalhes da Árvore*/
void consultarDetalhes(No *raiz){
	int num; /*Declaração de Auxiliar Inteira*/
	No* aux; /*Declaração de Ponteiro Auxiliar para o Nó*/
	cout<<"Digite o numero procurado: "; /*Imprimir Texto de Informação em Tela*/
	cin>>num; /*Escaner do Número Procurado*/
	aux = busca(raiz, num); /*Auxiliar para a Busca do Valor na Raiz*/
	if (aux == NULL) /*Inicio de Condição*/
		cout<<"Valor Nao encontrado!\n"; /*Imprimir Texto de Informação em Tela*/
	else{ /*Caso Condição Anterior Não Seja Atendida*/
		cout<<"Valor Encontrado!\n"; /*Imprimir Texto de Informação em Tela*/
		if(aux->pai == NULL){ /*Inicio de Condição*/
			cout<<"O No que contem o valor "<<num <<" e a raiz da arvore.\n"; /*Imprimir Texto de Informação em Tela*/
			if(aux->esq != NULL) /*Inicio de Condição*/
				cout<<"Valor contido no No filho a esquerda: "<< aux->esq->chave<<"\n"; /*Imprimir Texto de Informação em Tela*/
			if(aux->dir != NULL) /*Inicio de Condição*/
				cout<<"Valor contido no No filho a direito: "<< aux->dir->chave<<"\n"; /*Imprimir Texto de Informação em Tela*/
		}
		if((aux->esq == NULL)&&(aux->dir == NULL)&&(aux->pai != NULL)){ /*Inicio de Condição*/
			cout<<"O No que contem o valor e uma folha da arvore: "<< num<<"\n"; /*Imprimir Texto de Informação em Tela*/
			cout<<"Valor contido no No pai: "<< aux->pai->chave<<"\n"; /*Imprimir Texto de Informação em Tela*/
		}
		if(((aux->esq != NULL)||(aux->dir != NULL))&&(aux->pai != NULL)){ /*Inicio de Condição*/
			cout<<"O No que contem o valor " <<num<<" e um no interno a arvore.\n"; /*Imprimir Texto de Informação em Tela*/
			cout<<"Valor contido no No pai: "<< aux->pai->chave<<"\n"; /*Imprimir Texto de Informação em Tela*/
			if(aux->esq != NULL) /*Inicio de Condição*/
				cout<<"Valor contido no No filho a esquerda: "<< aux->esq->chave<<"\n"; /*Imprimir Texto de Informação em Tela*/
			if(aux->dir != NULL) /*Inicio de Condição*/
				cout<<"Valor contido no No filho a direito: "<< aux->dir->chave<<"\n"; /*Imprimir Texto de Informação em Tela*/
		}
	}
}

/*Função para Imprimir Valores da Árvore*/
void imprime(No *p, int nivel){
	int i; /*Declaração de Auxiliar Inteira*/
	if(p == NULL) /*Inicio de Condição*/
		return; /*Retornar ao Menu*/
	imprime(p->dir, nivel+1); /*Imprimir Níveis*/
	for(i=0;i<nivel;i++) /*Estrutura de Repetição para Passar os Níveis*/
		cout<<"      ";
	cout<<p->chave<<"\n\n"; /*Imprimir Texto de Informação em Tela*/
	imprime(p->esq,nivel+1); /*Imprimir Níveis*/
}

/*Função para Consultar Nível da Árvore*/
void consultaNivel(No *p){
	int i, nivel; /*Declaração de Auxiliar Inteira*/
	if(p == NULL) /*Inicio de Condição*/
		return; /*Retornar Nulo*/
	imprime(p->dir, nivel+1); /*Imprimir Informação em Tela*/
	for(i=0;i<nivel;i++) /*Inicio do Laço de Repetição*/
		cout<<"      "; /*Impressão em Branco*/
	cout<<"\n\n"<<p->chave; /*Imprimir Texto de Informação em Tela*/
	imprime(p->esq,nivel+1); /*Imprimir Informação em Tela*/
}

/*Função preordem*/
void preordem (No *arvore){
	if(arvore != NULL){ /*Inicio de Condição*/
		cout<<"\n "<<arvore->chave; /*Imprimir Texto de Informação em Tela*/
		preordem(arvore->esq); /*Executar Impressão na Ordem Requisitada*/
		preordem(arvore->dir); /*Executar Impressão na Ordem Requisitada*/
	}
}

/*Função emordem*/
void emordem(No *arvore){
	if(arvore != NULL){ /*Inicio de Condição*/
		emordem(arvore->esq); /*Executar Impressão na Ordem Requisitada*/
		cout<<"\n "<<arvore->chave; /*Imprimir Texto de Informação em Tela*/
		emordem(arvore->dir); /*Executar Impressão na Ordem Requisitada*/
	}
}

/*Função posordem*/
void posordem(No *arvore){
	if(arvore != NULL){ /*Inicio de Condição*/
		posordem(arvore->esq); /*Executar Impressão na Ordem Requisitada*/
		posordem(arvore->dir); /*Executar Impressão na Ordem Requisitada*/
		cout<<"\n "<<arvore->chave; /*Imprimir Texto de Informação em Tela*/
	}
}

/*Função para Remover um Nó*/
No *removeNo(No *raiz, int x){
 if (raiz == NULL) /*Inicio de Condição*/
    return NULL; /*Retornar um Valor Nulo*/
 else if (raiz->chave > x) /*Caso Condição Anterior Não Seja Atendida*/
    raiz->esq = removeNo(raiz->esq, x); /*Remover Valores da Raiz*/
 else if (raiz->chave < x) /*Caso Condição Anterior Não Seja Atendida*/
    raiz->dir = removeNo(raiz->dir, x); /*Remover Valores da Raiz*/
 else { /*Caso Condição Anterior Não Seja Atendida*/

    if (raiz->esq == NULL && raiz->dir == NULL) { /*Inicio de Condição*/
       free (raiz); /*Liberar Memória*/
       raiz = NULL;
    }

    else if (raiz->esq == NULL) { /*Caso Condição Anterior Não Seja Atendida*/
       No *t = raiz;
       raiz = raiz->dir;
       free (t); /*Liberar Memória*/
    }

    else if (raiz->dir == NULL) { /*Caso Condição Anterior Não Seja Atendida*/
       No *t = raiz;
       raiz = raiz->esq;
       free (t); /*Liberar Memória*/
    }

    else { /*Caso Condição Anterior Não Seja Atendida*/
       No *f = raiz->esq; /*Declaração de Ponteiro Auxiliar*/
       while (f->dir != NULL) { /*Enquanto Valor for Diferente de Nulo essa Função é Executada*/
          f = f->dir;
       }
       raiz->chave = f->chave;
       f->chave = x;
       raiz->esq = removeNo(raiz->esq, x);
    }
 }
return raiz; /*Retornar Raiz*/
}

/*Função para Imprimir Menu de Opções*/
int menu()
{
	int op; /*Variável Inteira para Receber o Valor de Escolha do Menu*/
	cout<<"\nEscolha a Funcao a ser Executada:\n\n"; /*Imprimir Título do Menu*/
	cout<<"[0] Voltar\n"; /*Voltar ao Menu Anterior*/
	cout<<"[1] Inserir valor\n"; /*Inserir Valores na Árvore*/
	cout<<"[2] Imprimir pre ordem\n"; /*Imprimir a Árvore em Pre Ordem*/
	cout<<"[3] Imprimir in-ordem\n"; /*Imprimir a Árvore em in-Ordem*/
	cout<<"[4] Imprimir pos ordem\n"; /*Imprimir a Árvore em Pós Ordem*/
	cout<<"[5] Consulta detalhada\n"; /*Consultar Detalhes da Árvore*/
	cout<<"[6] Quantidades de nos da arvore\n"; /*Consultar a Quantidade de Nós na Árvore*/
	cout<<"[7] Imprimir arvore\n"; /*Imprimir Valores da Árvore*/
	cout<<"[8] Remover no da arvore\n"; /*Remover Valores da Árvore*/
	cout<<">"; /*Receber Valor Informado no Menu*/
	cin>>op; /*Escaner de Recepção do Valor*/
	return op; /*Retornar Valor Inserido no Menu*/
}

