#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void){

	double** M= mat_cria(2,3);
	double** T=mat_cria(3,2);
	double** M2=mat_cria(2,2);

	double* v=(double*)malloc(3*sizeof(double));
	double* w=(double*)malloc(2*sizeof(double));

	int i,j;

	for(i=0;i<3;i++)
    	v[i]=1.0;

	mat_preenche(2,3,M);
	mat_imprime(2,3,M);

    printf("\n");
    mat_transposta(2,3,M,T);

    mat_imprime(3,2,T);

    mat_multv(2,3,M,v,w);

    for(i=0;i<2;i++)
    	printf("%f ", w[i]);

    mat_multm(2,3,2,M,T,M2);

    printf("\n");

    mat_imprime(2,2,M2);

	mat_libera(2,M);
    mat_libera(3,M);

}