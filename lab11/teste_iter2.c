#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "met_iter.h"
#include "matriz.h"

int main(){

     double** A=mat_cria(2,2);
	double* b=(double*)malloc(2*sizeof(double));
	double* x=(double*)malloc(2*sizeof(double));
	double* x2=(double*)malloc(2*sizeof(double));
	double* x3=(double*)malloc(2*sizeof(double));
	double tol=pow(10,-7);
	double vaux[4]={3,1,1,2};

	int i,j;
	int iteracoes1,iteracoes2,iteracoes3;

	for(i=0;i<2;i++){
		x[i]=0;
		for(j=0;j<2;j++)
			A[i][j]=vaux[2*i+j];
	}

	b[0]=5; b[1]=5;

    iteracoes1=Jacobi(2,A,b,x,tol);
    iteracoes2=GaussSeidel(2,A,b,x2,tol);
    iteracoes3=SOR(2,A,b,x3,tol,1.0);

    printf("%f %f %d\n",x[0],x[1],iteracoes1);
    printf("%f %f %d\n",x2[0],x2[1],iteracoes2);
    printf("%f %f %d\n",x3[0],x3[1],iteracoes3);

	return 0;
}