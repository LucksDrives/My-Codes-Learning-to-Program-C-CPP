/*3) O que as linhas abaixo fazem?
int a=5, b=12, c;
int *p;
int *q;
p = &a;
q = &b;
c = (*p) + (*q);*/

int a=5, b=12, c; /*Declara as variáveis*/
int *p; /*Declara o primeiro ponteiro*/
int *q; /*Declara o segundo ponteiro*/
p = &a; /*Ponteiro P recebe posição de A*/
q = &b; /*Ponteiro Q recebe posição de B*/
c = (*p) + (*q); /*Armazena em C a soma do valor a que P aponta com o valor a que Q aponta, Logo P(a=5)+Q(b=12)= 17/
