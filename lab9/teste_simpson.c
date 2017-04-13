#include <stdio.h>
#include <math.h>
#include "simpson.h"

#define TOL 0.5*pow(10,-7)

double f1(double x){

   return x/sqrt(x*x+9);
}

double f2(double x){

   return exp(-x*x/2);
}

double f3(double x){

   return exp(-x*x);
}

int main(){

   double As1,As2,As3;

   As1=AdaptiveSimpson(0,1,f1,TOL);
   As2=(1/sqrt(2*M_PI))*AdaptiveSimpson(-1,1,f2,TOL);
   As3=(2/sqrt(M_PI))*AdaptiveSimpson(0,3,f3,TOL);

   printf("%.7g\n%.7g\n%.7g\n",As1,As2,As3);

   return 0;
}
     
