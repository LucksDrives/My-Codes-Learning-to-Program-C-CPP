/*Questão 1 (1,5): Faça uma função que recebe um
char (dígito), referente a um número, e retorne o
valor equivalente ao seu inteiro. Na tabela ascii, o
dígito '0' equivale ao número 48 (decimal). A
função deve testar se o valor recebido está entre
'0' (48) e '9' (57), caso contrário esta retorna -1.
Exemplo de chamada da função:
char dig = '0'; //48 em decimal
int num;
num = charToNum(dig); //num deve conter 0*/

#include <stdio.h>
int charToNum(char dig) {
	
	if((dig>=48) && (dig <=57)){
		printf("\nDigito na Tabela ASCII: %d\n", dig);
		printf("\nESTA NO INTERVALO");
	} 	
	else{
	return(-1);
	}
}



int main(){
	
char dig = '0';
int num=0;

num= charToNum(dig);
return(0);
}

