/*Quest�o 1 (1,5): Fa�a uma fun��o que recebe um
char (d�gito), referente a um n�mero, e retorne o
valor equivalente ao seu inteiro. Na tabela ascii, o
d�gito '0' equivale ao n�mero 48 (decimal). A
fun��o deve testar se o valor recebido est� entre
'0' (48) e '9' (57), caso contr�rio esta retorna -1.
Exemplo de chamada da fun��o:
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

