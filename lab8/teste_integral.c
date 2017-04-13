#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"

#define Emaq pow(2,-52)

double f(double x){

    return cos(x)-2*sin(x);
}

double fl(double x){

   return -sin(x)-2*cos(x);
}

double g1(double x){

	return x/sqrt(x*x+9);
}

double g2(double x){

	return x*x*log(x);
}

double g3(double x){

	return x*x*sin(x);
}

int main(void){

     int i;
     double h;

     printf("h	  f´(0)	    Erro\n");

      for(i=1;i<13;i++){

        h=pow(10,-i);
	printf("%g   %g   %g\n",h,derivada(f,h,0),derivada(f,h,0)-fl(0));
 }
  /*o valor de h na tabela que minimiza o erro h = */

	printf("\n\nQuestao 5\n");

	printf("integral 1\n:");

	printf("S(n=16) = %g, S(n=32) = %g, M(n=16) = %g, M(n=32) = %g\n",simpson(g1,0,4,16),simpson(g1,0,4,32),pontomedio(g1,0,4,16),pontomedio(g1,0,4,32));
	printf("integral 2\n");
	printf("S(n=16) = %g, S(n=32) = %g, M(n=16) = %g, M(n=32) = %g\n",simpson(g2,1,3,16),simpson(g2,1,3,32),pontomedio(g2,1,3,16),pontomedio(g2,1,3,32));
	printf("integral 3\n");
	printf("S(n=16) = %g, S(n=32) = %g, M(n=16) = %g, M(n=32) = %g\n",simpson(g3,0, 3.1415926535,16),simpson(g3,0,3.1415926535,32),pontomedio(g3,0,3.1415926535,16),pontomedio(g3,0,3.1415926535,32));


     return 0;
}
