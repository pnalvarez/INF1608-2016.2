#include <stdio.h>
#include <math.h>
#include "simpson.h"

 double DoubleSimpson (double a, double b, double (*f) (double x), double* v){


    double h=b-a;
    double c=(a+b)/2;
    double Sab,Sac,Sbc;
   
     Sab = (h/6)*(f(a)+4*f(c)+f(b));
     Sac = ((c-a)/6)*(f(a)+4*f((a+c)/2)+f(c));
     Sbc = ((b-c)/6)*(f(c)+4*f((b+c)/2)+f(b));

    *v=Sac+Sbc;

     return fabs(Sab-Sbc-Sac)/15;

}

 double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol){

    double v;
    double erro=DoubleSimpson(a,b,f,&v);
     
    if(erro<=tol)
      return v;

   
     return AdaptiveSimpson(a,(a+b)/2,f,tol/2)+ AdaptiveSimpson((a+b)/2,b,f,tol/2);
}
