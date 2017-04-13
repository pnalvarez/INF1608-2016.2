#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"fcos.h"

#define TRUE 1

int main(void){

double x;

printf("Digite o valor de x");
scanf("%f", &x);

  if(abs(fcos(x)- cos(x))<=residuo(x)){
     printf("certo\n");
 }
  else
    printf("nao corresponde");

return 0;
}
