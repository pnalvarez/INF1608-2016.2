#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

void zera_matriz(double** A, int n){

	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			A[i][j]=0;
	}
}

void Cholesky (int n, double** A){

	int i,j,k;
	double** u,ut,M;
    double soma;

    M=mat_cria(n,n);

    A[k][k] = sqrt(A[k][k]);

		for(i = k + 1; i < n; ++i) 
			ut[k][i] = (1/A[k][k])*A[k][i]; 

		mat_transposta(n,n,ut,u);
		mat_multm(n,n,n,u,ut,M);

		for(i = k + 1; i < n; i++) {
			for (j = k + 1; j < n; j++)
				A[i][j] = A[i][j] - M[i][j];
			}	

	zera_matriz(A,n);
}

void ConjugateGradient (int n, double** A, double* b, double* x){

	double* xk,dk,rk,xk1,dk1,rk1,dn;
	double alpha,beta,n1,n2;
	int i,j,k,parar;
	
	xk=(double*)malloc(n*sizeof(double));
	dk=(double*)malloc(n*sizeof(double));
	rk=(double*)malloc(n*sizeof(double));
	xk1=(double*)malloc(n*sizeof(double));
	dk1=(double*)malloc(n*sizeof(double));
	rk1=(double*)malloc(n*sizeof(double));
	dn=(double*)malloc(n*sizeof(double));

   mat_multv(n,n,A,x,dk);

   for (i = 0; i < n; ++i)
	{
		rk[i] = b[i] - dk[i];
		dk[i] = rk[i];
	}

		for (k = 0; k < n; ++k)
	{
		parar = 1;

		for (i = 0; i < n; ++i)
		{
			if(rk[i] != 0) 
			{
				parar = 0;
			}
		}

		if(parar == 1) 
		{
			for (i = 0; i < n; ++i)
			{
				x[i] = x[i];
			}
			return;
		}

		n1 = 0;

		for (i = 0; i < n; ++i)
		{
			n1 += rk[i] * rk[i];
		}

		mat_multv(n,n,A,dk,dn);

		n2 = 0;

		for (i = 0; i < n; ++i)
		{
			n2 += dk[i] * dn[i];
		}

		alpha = n1/n2;

		for (i = 0; i < n; ++i)
		{
			xk1[i] = x[i] + alpha * dk[i];
			rk1[i] = rk[i] - alpha * dn[i];
		}

		n2 = 0;

		for (i = 0; i < n; ++i)
		{
			n2 += rk1[i] * rk1[i];
		}

		beta = n2/n1;

		for (i = 0; i < n; ++i)
		{
			dk1[i] = rk1[i] + (beta * dk[i]);
		}

		for (i = 0; i < n; ++i)
		{
			dk[i] = dk1[i];
			x[i] = xk1[i];
			rk[i] = rk1[i];
		}
	}

	for (i = 0; i < n; ++i)
	{
		x[i] = x[i];
	}
	free(xk);
	free(dk);
	free(rk);
	free(xk1);
	free(dk1);
	free(rk1);
	free(dn);
} 
	

