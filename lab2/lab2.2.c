#include<stdio.h>
#include<math.h>
#include"raiz.h"

double f(double m){
 
   return (9.8/15)*m*(1-exp(-135/m))-35;
}

int main(void){

  printf("%f\n",bissecao(0,200,6,f));

  return 0;
}
