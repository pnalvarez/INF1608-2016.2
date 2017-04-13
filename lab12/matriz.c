#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

double** mat_cria(int m, int n){//OK

	double** A= (double**)malloc(m*sizeof(double*));
    int i;

    for(i=0;i<m;i++)
    	*(A+i)=(double*)malloc(n*sizeof(double));

    return A;

}

void mat_libera(int m, double** A){//Nao funciona direito

	int i;

	for(i=0;i<m;i++){
		free(A[i]);
	}
	free(A);
}

void mat_transposta(int m,int n, double** A,double** T){//OK

	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			T[i][j]=A[j][i];
	}
}

void mat_preenche(int m,int n, double** A){

	int i,j;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			A[i][j]= (m*i*1.0+j);
	}
}

void mat_imprime(int m, int n, double** A){//Funcao auxiliar

	int i,j;

	for(i=0;i<m;i++){
		printf("\n");
		for(j=0;j<n;j++)
			printf("%f ",A[i][j]);
	}
}

void mat_multv(int m, int  n,double** A,double* v, double* w){//OK

	int i,j;

    for(i=0;i<m;i++)
    	w[i]=0;

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
          w[i]+=v[j]*A[i][j];
		}
	}
}
void mat_multm (int m, int n, int q, double** A, double** B, double** c){

   int i,j,k;

   for(i=0;i<m;i++){
   	for(j=0;j<q;j++)
   		c[i][j]=0;
   }
    
    for(i=0;i<m;i++){
    	for(j=0;j<q;j++){
    		for(k=0;k<n;k++)
    			c[i][j]+=A[i][k]*B[k][j];
    	}
    }
   
}