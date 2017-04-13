#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integral.h"

double derivada (double (*f) (double x), double h, double x){

   return (f(x+h)-f(x-h))/(2*h);
}

double simpson(double(*f)(double),double a, double b,int n){

   double h=(b-a)/n;
   double pmedio=(b-a)/2;
   double integral=0.0;
   int i;

    for(i=1;i<=n;i++){

        integral+=(h/6)*(f(a)+4*f(pmedio)+f(b));
    }
      return integral;
}

double pontomedio(double (*f)(double),double a,double b,int n){

     double h=(b-a)/n;
     double w=(b-a)/2;
     double integral=0.0;
     int i;

       for(i=1;i<=n;i++){ 
       
          integral+=h*f(w);
        }
 
       return integral;
}
     
     



   






