#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "gauss.h"
#include "mmq.h"

double* mmq(int m, int n, double** A, double* b){

   double** T = mat_cria(n,m);
   double** C = mat_cria(n,n);
   double* xb = (double*)malloc(n*sizeof(double));
   double* bt = (double*)malloc(n*sizeof(double));

   mat_transposta(m,n,A,T); //obtem a transposta
   mat_multm(n,m,n,T,A,C); //obtem a matriz C = At x A
   mat_multv(n,m,T,b,bt);//obtem o novo b

   //Agora resolver o sistema C(xb)=bt

   gauss(n,C,bt,xb);

   mat_libera(n,T);
   mat_libera(n,C);
   free(bt);

   return xb;
	
}

double norma2 (int m, int n, double** A, double* b, double* x){

	double* v=(double*)malloc(m*sizeof(double));
	double* res=(double*)malloc(m*sizeof(double));
	double err=0;
	int i;
    
	mat_multv(m, n, A, x, v);

     for(i=0;i<m;i++)
     	res[i]=b[i]-v[i];

     for(i=0;i<m;i++)
     	err+=pow(res[i],2);

     err=sqrt(err);

     free(v);
     free(res);

    return err;
}