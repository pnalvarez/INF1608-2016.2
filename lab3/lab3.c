#include "raiz2.h"

double f(double x){

  return cos(x)-pow(x,3)+x;
}

double fl(double x){

    return -sin(x)-3*pow(x,2)+1;
}

int main(void){

  double r;
  int t=NR(1.5,6,f,fl,&r);
  printf("%d tentativas e %f\n",t,r);

  return 0;
}
