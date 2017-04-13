#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "met_iter.h"

 double norma2(double* v, int n){

     int i;
     double soma=0;

     for(i=0;i<n;i++){
        soma+=v[i]*v[i];
}
   return sqrt(soma);
}


int Jacobi (int n, double** A, double* b, double* x, double tol){

       int parar=1;
       int ni=0;
       int i,j;
	     int soma;
       double* y=(double*)malloc(n*sizeof(double));
       double* dif=(double*)malloc(n*sizeof(double));
       double norma;

     while(parar==1){
       
       for(i=0;i<n;i++){
	          soma=0;
          for(j=0;j<n;j++){
            if(i!=j)
               soma+=A[i][j]*x[j];
     
           
        }
            y[i]=(b[i]-soma)/A[i][i];
      }
      for(i=0;i<n;i++)
        dif[i]=fabs(y[i]-x[i]);
        norma=norma2(dif,n);

     if(norma<tol)
        parar=0;
      else{
        for(i=0;i<n;i++)
           x[i]=y[i];
      
     }
     
     ni++;
   }
     return ni;
}

  

int GaussSeidel(int n, double** A, double* b,double* x,double tol){

    int parar=1;
    int ni=0;
    int i,j;
    int soma;
    double* y=(double*)malloc(n*sizeof(double));

    for(i=0;i<n;i++)
      y[i]=0;

    while(parar==1){
       for(i=0;i<n;i++){
        soma=0;

        for(j=0;j<i;j++)
          soma+=A[i][j]*y[j];
        for(j=i+1;j<n;j++)
          soma+=A[i][j]*x[j];
        y[i]=(b[i]-soma)/A[i][i];
       }
        if(fabs(norma2(y,n)-norma2(x,n))<tol)
          parar=0;

          for(i=0;i<n;i++)
            x[i]=y[i];
        ni++;
    }
      return ni;
}

int SOR(int n, double**A , double*b , double * x, double tol, double w)
{
  int i, j, it = 0;
  double norma;
  double y[n], dif[n];
  double soma;
  int parar=1;

  for(i = 0; i < n; i++)
  {
    y[i] = 0;
  }

  while(parar==1)
  {
    it++;
    for(i = 0; i < n;i++)
    {
      soma = 0;
      for(j = 0; j < i; j++)
      {
        soma += A[i][j] * y[j];
      }
      for(j = i + 1; j < n; j++)
      {
        soma += A[i][j] * x[j];
      }

      y[i] = (b[i] - soma) / A[i][i];
    }

    for(i = 0; i < n ; i++)
    {
      y[i] = (1 - w) * x[i] + w * y[i];
    }

    for(i = 0; i < n; i++)
    {
      dif[i] = fabs(x[i] - y[i]);
    }

    norma = norma2(dif,n);

    if (norma<tol)
      parar=0;
    else{
      for(i = 0; i < n;i++)
        x[i] = y[i];
    }
  }
  return it;
}
