#include<stdio.h>
#include<math.h>
#include"raiz.h"

double bissecao(double a, double b, int p, double (*f) (double x)){
  
  double e=(b-a)/2,c;
  int n=1;

  for(;;){

     c=(a+b)/2;
    
     if(f(c)==0||e<0.5*pow(10.0,-p))
        return c;

     else{
       n++;
       e=(b-a)/pow(2.0,n);
       
         if(f(a)*f(c)<0)
             b=c;
          else
            a=c;
  }
 }
}

double pontofixo (double x0, double epsilon, double (*f) (double x)){

double x1;

 for(;;){

  if(f(x0)==0 || fabs(f(x0))<epsilon)
    return x0;

  x1=f(x0);

  if(fabs(f(x1))<epsilon||fabs(x1-x0)<epsilon)
    return x1;

  x0=x1;

 }

}
     

  
