/*2) O que as linhas abaixo fazem?
int i=99,j;
int *p;
p=&i;
j=(*p)+100;*/

int i=99,j; /*Declara variáveis*/
int *p; /*Declara Ponteiro*/
p=&i; /*Atribui a posição de I a P*/
j=(*p)+100; /*J recebe o valor que P aponta(I=99), e soma 100 ao mesmo, Logo J vale 100+i(99)= 199*/
