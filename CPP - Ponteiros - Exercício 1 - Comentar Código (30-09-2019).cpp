/*1) Qual o valor de y no final do programa?
Coloque um comentario em cada comando de atribui��o explicando o que ele faz eo valor da vari�vel � esquerda do '=' ap�s a execu��o;
#include <stdio.h>
int main(){
int y, *p, x;
y=0;
p=&y;
x=(*p);
x=4;
(*p)++;
x--;
(*p)+=x;
printf("y=%d\n",y);
return 0;*/

#include <stdio.h>
int main(){
int y, *p, x; /*Declara as vari�veis, entre elas, est� "P" que � um ponteiro*/
y=0; /*Atribui 0 a Y*/
p=&y; /*Armazena a posi��o de Y em P, Logo P vale 0*/
x=(*p); /*X recebe o valor da vari�vel P, Logo X vale 0*/
x=4; /*Atribui 4 a X, Logo X vale 4*/
(*p)++; /*Acrescenta 1 ao valor de P, Logo P vale 1*/
x--; /*Subtrai 1 de X, Logo X vale 3*/
(*p)+=x; /*A posi��o salva em P soma e iguala com X, Logo X(3)+P(y(1)= 4(Armazenado na posi��o de Y)*/
printf("y=%d\n",y); /*Imprime o valor final de Y*/
return 0;/*Encerra o programa*/
}
