/*INFORMAÇÕES GERAIS:

Nomes: Lucas Asquidamini e Maicon Vidi;
Temática: Sistema de Gerenciamento de Estoque de um Mercado;


DEVE CONTER NO TRABALHO:
	-A definição do tipo de item que o cadastro utiliza é definido pelos autores, devendo usar registros (estruturas - structs) para representar esses dados.
	-A quantidade máxima de itens do cadastro é 100.
	-O item, descrito por um registro, deve conter, no mínimo, cinco membros.
	-Inserir, Mostrar todos, Procurar (busca) e Remover.
	-Deve ser possível buscar por, no mínimo, dois membros do registro.
	-Ao iniciar o sistema, o cadastro deve ser vazio. Deve ser implementado o controle de itens e quantidades cadastradas.
	-Não será permitido o uso de variáveis globais.*/

#include<stdio.h>
#include <stdlib.h>/*Biblioteca de Cores Padrões*/
#include<string.h>

/*REGISTROS*/

/*1-Prazo de Validade do Produto*/
typedef struct{
	int dia;
	int mes;
	int ano;
}data_t;

/*2-Dados do Produto*/
typedef struct{
	data_t validade;
	char Nome_produto[20];
	int codigo_produto;
	double preco_unidade;
	int qnt_estoque;
}estoque;



/*FUNÇÕES*/

/*0.5-Validar Data*/
int ValidacaoData(estoque V[100], int i){
	int Validade=0;
	
			while(Validade==0){
				printf("\nInsira a Validade do Produto:");
				printf("\nDia: ");
					scanf(" %d", &V[i].validade.dia);
				printf("\nMes: ");
					scanf(" %d", &V[i].validade.mes);
				printf("\nAno: ");
					scanf(" %d", &V[i].validade.ano);
					/*SISTEMA DE VALIDAÇÃO*/
					if((V[i].validade.mes==1) || (V[i].validade.mes==3) || (V[i].validade.mes==5) || (V[i].validade.mes==7) || (V[i].validade.mes==8) || (V[i].validade.mes==10) || (V[i].validade.mes==12)){
						if((V[i].validade.dia<1) || (V[i].validade.dia>31)){
						printf("\n[ERRO]Data invalida");
						printf("\n");
						}
						else if((V[i].validade.ano<2019) || (V[i].validade.ano>2020)){
						printf("\n[ERRO]Data invalida");
						printf("\n");
						}
						else{
							Validade++;
						}
					}					
					else if(V[i].validade.mes==2){
						if((V[i].validade.dia<1) || (V[i].validade.dia>29)){
						printf("\n[ERRO]Data invalida");
						printf("\n");
						}
						else if((V[i].validade.ano<2019) || (V[i].validade.ano>2020)){
						printf("\n[ERRO]Data invalida");
						printf("\n");
						}
						else{
							Validade++;
						}
					}
					else if((V[i].validade.mes==4) || (V[i].validade.mes==6) || (V[i].validade.mes==9) || (V[i].validade.mes==11)){
						if((V[i].validade.dia<1) || (V[i].validade.dia>30)){
						printf("\n[ERRO]Data invalida");
						}
						else if((V[i].validade.ano<2019) || (V[i].validade.ano>2020)){
						printf("\n[ERRO]Data invalida");
						}
						else{
							Validade++;
						}
					}
					/*CASO DATA INVALIDA*/
					else if((V[i].validade.mes>12) || (V[i].validade.mes<1)){
						printf("\n[ERRO]Data invalida");
					}
				}
				return(i);
}
/*1-Registrar um Produto*/
int RegistrarProduto(estoque V[100], int Registrados){
	int i, Aux=0, condicao=0, Quant, Validade=0;
	
	system("color 02");
	printf("\n");
	/*VARIAVEIS AUX, QUANT, SÃO FEITOS PARA RESTRINGIR O NUMERO DE REGISTROS SALVOS NO VETOR, ASSIM BARRANDO QUANDO OS REGISTRADORES SE EXCEDEREM AO LIMITE DE REGISTROS*/
		Aux=Registrados;
		/*TODOS WHILES FORAM DEFINIDOS PARA IMPEDIR QUE O USUARIO EXECUTE OPERAÇÕES INCORRETAS E FORÇA-OS A REPETIR*/
		while(condicao==0){
			printf("\n--REGISTRAR PRODUTO--");
			printf("\nQuantos Produtos Deseja Registrar[Min 1][Max 100]: ");
				scanf("%d", &Quant);
		if((Quant <1) || (Quant>100-Registrados)){ 
			printf("\nINVALIDO, insira novamente:\n");
		}
		else{
			condicao++;
		}
	}
	/*SISTEMA PARA SALVAR DADOS DO PRODUTO INFORMADOS PELO USUÁRIO*/
	/*AUX REFERE-SE AO MODELO INICIAL DOS REGISTROS PARA QUE ASSIM QUE INCREMENTADOS A CADA OPERAÇÃO NÃO ALTEREM A EXECUÇÃO DA REPETIÇÃO*/
	Quant+=Aux;
		for(i=Aux;i<Quant;i++){
			printf("\n");
			printf("--PRODUTO[%d]--", i);
			printf("\nInsira o Nome do Produto: ");
				scanf(" %[^\n]s", V[i].Nome_produto);
			printf("\nInsira o Codigo do Produto: ");
				scanf(" %d", &V[i].codigo_produto);
			ValidacaoData(V,i);	/*Validação de datas*/			
			printf("\nInsira a Quantidade em Estoque: ");
				scanf(" %d", &V[i].qnt_estoque);
			printf("\nInsira o Valor por Unidade do Produto: ");
				scanf("%lf", &V[i].preco_unidade);
		Registrados++;
	}
	return(Registrados);
}

/*2-Pesquisar um Produto*/
estoque PesquisarProduto(estoque V[100]){
	int i, condicao=0, C;
	char A[20];
	
	system("color 06");
	printf("\n");
	/*SISTEMA DE PESQUISA*/
		while(condicao==0){
			printf("\n--PESQUISAR PRODUTO--");
			printf("\n");
			printf("\nPesquisar por:");
			printf("\n [1]Nome;");
			printf("\n [2]Codigo;");
			printf("\n [3]Cancelar/Voltar;");
			printf("\nEscolha: ");
				scanf(" %d",&C);
	/*SISTEMA DE ESCOLHA DE FORMA PARA PESQUISAR*/
	/*PESQUISA POR NOME*/	
		if(C==1){
			printf("\nInsira o Nome do Produto: ");
				scanf(" %[^\n]s", A);
				for(i=0; i<100; i++){
					if(strcmp(V[i].Nome_produto,A)==0){
						printf("\n");
						printf("\nNome: %s", V[i].Nome_produto);
						printf("\nCodigo: %d", V[i].codigo_produto);
						printf("\nValidade: %d/%d/%d", V[i].validade.dia, V[i].validade.mes, V[i].validade.ano);
						printf("\nQuantidade: %d", V[i].qnt_estoque);
						printf("\nPreco: %.2lf", V[i].preco_unidade);
						break;
					}
					else if(i==99){
						printf("\n--[ERRO]Nome Invalido--\n");
					}
				}
			}	
		/*PESQUISA POR CÓDIGO*/	
		else if(C==2){	
			printf("\nInsira o Codigo do Produto: ");
				scanf(" %d", &C);
				for(i=0; i<100; i++){
					if(V[i].codigo_produto==C){			
						printf("\n");
						printf("\nNome: %s", V[i].Nome_produto);
						printf("\nCodigo: %d", V[i].codigo_produto);
						printf("\nValidade: %d/%d/%d", V[i].validade.dia, V[i].validade.mes, V[i].validade.ano);
						printf("\nQuantidade: %d", V[i].qnt_estoque);
						printf("\nPreco: %.2lf", V[i].preco_unidade);
						break;
					}
					else if(i==99){
						printf("\n--[ERRO]Codigo Invalido--\n");
					}						
				}
			}
		/*SAIR MANUALMENTE DA FUNÇÃO PARA A MAIN*/
		else if(C==3){
			condicao++;			
		}	
		else if((C>3) || (C<1)){
			printf("\nOpcao Invalida\n");
		}	
	}
	printf("\n");
}

/*3-Remover um Produto*/
estoque RemoverProduto(estoque V[100], int Registrados){
	int i, C, condicao=0; 
	char A[20];

	/*SISTEMA PARA REMOVER UM PRODUTO*/
	printf("\n");
	system("color 04");
		while(condicao==0){
			printf("\n--REMOVER PRODUTO--");
			printf("\n");
			printf("\nRemover por:");
			printf("\n [1]Nome;");
			printf("\n [2]Codigo;");
			printf("\n [3]Cancelar/Voltar;");
			printf("\nEscolha: ");
				scanf(" %d",&C);
		/*SISTEMA DE ESCOLHA PARA METODO DE REMOÇÃO*/
		/*REMOVER PRODUTO ATRAVÉS DE NOMES*/
		if(C==1){
			printf("\nInsira o Nome do Produto: ");
				scanf(" %[^\n]s", A);
				for(i=0; i<100; i++){
					if(strcmp(V[i].Nome_produto,A)==0){
						V[i].Nome_produto[i]= ' ';
						V[i].codigo_produto=' ';
						V[i].validade.dia=' ';
						V[i].validade.mes=' ';
						V[i].validade.ano=' ';
						V[i].qnt_estoque=' ';
						V[i].preco_unidade=' ';	
						printf("\n--PRODUTO REMOVIDO--\n");	
						Registrados--;					
						break;
					}
					else if(i==99){
						printf("\n--[ERRO]Nome Invalido--\n");
					}
				}
			}	
		/*REMOVER PRODUTO ATRAVÉS DE CÓDIGO*/
		else if(C==2){	
			printf("\nInsira o Codigo do Produto: ");
				scanf(" %d", &C);
				for(i=0; i<100; i++){
					if(V[i].codigo_produto==C){			
						V[i].Nome_produto[i]= ' ';
						V[i].codigo_produto=' ';
						V[i].validade.dia=' ';
						V[i].validade.mes=' ';
						V[i].validade.ano=' ';
						V[i].qnt_estoque=' ';
						V[i].preco_unidade=' ';	
						printf("\n--PRODUTO REMOVIDO--\n");	
						Registrados--;					
						break;
					}
					else if(i==99){
						printf("\n--[ERRO]Codigo Invalido--\n");
					}						
				}
			}
		/*SISTEMA PARA VOLTAR MANUALMENTE PARA O SISTEMA APÓS EXECUTAR AS OPERAÇÕES DESEJADAS*/
		else if(C==3){
			condicao++;			
		}	
		else if((C>3) || (C<1)){
			printf("\nOpcao Invalida\n");
		}	
	}
	printf("\n");
}

/*4-Mostrar todos os Produtos*/
estoque MostrarTodos(estoque V[100], int Registrados){
	int i;

	/*SISTEMA PARA MOSTRAR TODOS OS PRODUTOS*/
	printf("\n");
	printf("\n--MOSTRAR TODOS PRODUTO--");
	printf("\n");
		for(i=0; i<Registrados; i++){
			printf("\nPRODUTO[%d]", i);
			/*RESTRINGIR AMOSTRA DE PRODUTOS REMOVIDOS DO VETOR*/
			if(V[i].codigo_produto==' '){
				printf(" ");
			}
			else{
				printf("\nNome: %s", V[i].Nome_produto);
				printf("\nCodigo: %d", V[i].codigo_produto);
				printf("\nValidade: %d/%d/%d", V[i].validade.dia, V[i].validade.mes, V[i].validade.ano);
				printf("\nQuantidade: %d", V[i].qnt_estoque);
				printf("\nPreco: %.2lf", V[i].preco_unidade);
				printf("\n\n");
			}	
	}
}

/*MAIN*/

int main() {
	int Escolha, condicao=0, Registrados=0;
	estoque V[100];
	
	while (condicao == 0) {
			
		/*MENU DE OPERAÇÕES*/		
		system("color 03");
		printf("\n");
		printf("\n|-MENU DE OPERACAO-|\n");
		printf("\n");
		printf("[1] Registrar um Produto: \n");
		printf("[2] Pesquisar um Produto : \n");
		printf("[3] Remover um Produto: \n");
		printf("[4] Mostrar Todos Produtos: \n");
		printf("\n");
		printf("Escolha Uma Operacao: ");
			scanf("%d", &Escolha);
		
		/*SISTEMA DE ESCOLHA DE OPERAÇÕES*/	
    		if(Escolha == 1){
    			/*IF- FEITO PARA RESTRINGIR O NUMERO DE CADASTROS*/
				if(Registrados==100){
					printf("--Você já Excedeu o Limite de Cadastros, Remova Cadastros para Adivionar Novos--");
				}
				else{	
					printf("\n");
					printf("--PRODUTOS REGISTRADOS: %d--", Registrados);
					Registrados=RegistrarProduto(V, Registrados);	
				}
			}
			else if(Escolha == 2){	
				/*IF- FEITO PARA RESTRINGIR O USO SEM PRODUTO REGISTRADO*/
				if(Registrados>0){
					PesquisarProduto(V);
				}
				else{
					printf("\n[ERRO]Impossivel Pesquisar:");
					printf("\n--Nenhum Produto Registrado--");
				}
			}
			else if(Escolha == 3){	
				if(Registrados>0){
					RemoverProduto(V, Registrados);	
				}
				else{
					printf("\n[ERRO]Impossivel Remover:");
					printf("\n--Nenhum Produto Registrado--");
				}						
			}
			else if(Escolha == 4){	
				if(Registrados>0){
					MostrarTodos(V, Registrados);
				}
				else{
					printf("\n[ERRO]Impossivel Mostrar:");
					printf("\n--Nenhum Produto Registrado--");
				}						
			}			
			else{
				/*SISTEMA PARA RECONHECER OPERAÇÕES INVÁLIDAS*/
				printf("\n--[ERRO]OPERACAO INVALIDA--");
				printf("\n");
			}
		}
		return 0;
	}
		
	


