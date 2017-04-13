#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "raiz2.h"

double det(double matriz[3][3]){

  return (matriz[0][0]*matriz[1][1]*matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0]) + (matriz[0][2]*matriz[1][0]*matriz[2][1])
          - ((matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]) + (matriz[0][2]*matriz[1][1]*matriz[2][0]));
}

int NR (double x0, int p, double (*f) (double x),double (*fl) (double x), double* r){

   int k=1;
   double x1,tol=0.5*pow(10,-p);

   while(k<=100){

     x1=x0-f(x0)/fl(x0);
     
      if(fabs(x1-x0)<tol||fabs(x1-x0)/fabs(x1)<tol||fabs(f(x1))<tol){
        
       *r=x1;
       return k;
  }

       k++;
       x0=x1;
   }
  return -1;
}
 /*int IQI (double x0, double x1, double x2, int p, double (*f) (double x), double* r){

  int k=1;
  double xl,tol=0.5*pow(10,-p),A[3][3],Ac[3][3];

   while(k<=100){
     
   A[3][3]= {f(x0)*f(x0),f(x0),1},{f(x1)*f(x1),f(x1),1},{f(X2)*f(x2),f(x2),1}};
   Ac[3][3]= {{{f(x0)*f(x0),f(x0),x0},{f(x1)*f(x1),f(x1),x1},{f(X2)*f(x2),f(x2),x2}};

   if(fabs())
       
   }
 }*/
