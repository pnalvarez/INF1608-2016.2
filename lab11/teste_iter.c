#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "met_iter.h"
#include "matriz.h"

int main(){

	double** A=mat_cria(6,6);
	double* b=(double*)malloc(6*sizeof(double));
	double* x=(double*)malloc(6*sizeof(double));
	double* x2=(double*)malloc(6*sizeof(double));
	double* x3=(double*)malloc(6*sizeof(double));
	double tol=pow(10,-7);
    double vaux[36]={3, -1 , 0, 0, 0, 0.5, -1 , 3, -1 , 0, 0.5, 0,0, -1 , 3, -1 , 0, 0, 0, 0, -1 , 3, -1 , 0, 0, 0.5, 0, -1 , 3, -1 , 0.5, 0, 0, 0, -1 , 3};

	int i,j,iteracoes1,iteracoes2,iteracoes3;

	for(i=0;i<6;i++){
		x[i]=0;
		for(j=0;j<6;j++)
			A[i][j]=vaux[6*i+j];
	}

	b[0]=2.5;
	b[1]=1.5;
	b[2]=1.0;
	b[3]=1.0;
	b[4]=1.5;
	b[5]=2.5;

   iteracoes1=Jacobi(6,A,b,x,tol);
   iteracoes2=GaussSeidel(6,A,b,x2,tol);
   iteracoes3=SOR(6,A,b,x3,tol,1.0);

   for(i=0;i<6;i++){
   	 printf("%g ", x[i]);
   }

   	printf("\n%d",iteracoes1);

   	 for(i=0;i<6;i++){
   	 printf("%g ", x2[i]);
   }

   	printf("\n%d",iteracoes2);

   	 for(i=0;i<6;i++){
   	 printf("%g ", x3[i]);
   }

   	printf("\n%d",iteracoes3);

   	return 0;
   }
/*3 −1 0 0 0 0.5
−1 3 −1 0 0.5 0
0 −1 3 −1 0 0
0 0 −1 3 −1 0
0 0.5 0 −1 3 −1
0.5 0 0 0 −1 3*/