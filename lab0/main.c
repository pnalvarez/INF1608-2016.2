#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

int main(void){

	double** A= mat_cria(2,3);
	double** T=mat_cria(3,2);
	double** B=mat_cria(2,2);
	double* v=(double*)malloc(3*sizeof(double));
	double* w=(double*)malloc(2*sizeof(double));

	int i,j;

    for(i=0;i<3;i++)
    	v[i]=1.0;

	for(i=0;i<2;i++){
		for(j=0;j<3;j++)
		A[i][j] = 1.0*(3*i+j);
}

	mat_transposta(2,3,A,T);

    mat_imprime(2,3,A);
    printf("\n");
    mat_imprime(3,2,T);

    mat_multv(2,3,A,v,w);
    printf("\n");

    for(i=0;i<2;i++)
    	printf("%f ",w[i]);

    
    mat_multm(2,3,2,A,T,B);
    mat_imprime(2,2,B);

    mat_libera(3,A);
    mat_libera(2,A);
    mat_libera(2,B);

	return 0;
}