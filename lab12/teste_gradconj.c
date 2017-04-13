#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriz.h"

int main(){


	double** mat1 = mat_cria(3,3);
	double** mat2 = mat_cria(3,3);

	double b1[3] = {0,2,3};
	double b2[3] = {3,-3,4};

	double x1[3] = {0,0,0};
	double x2[3] = {0,0,0};

	double vaux1[9]={1,-1,0,-1,2,1,0,1,2};
	double vaux2[9]={1,-1,0,-1,2,1,0,1,5};
    
    int i,j;

    for(i=0;i<3;i++){
    	for(j=0;j<3;j++){
    		mat1[i][j]=vaux1[3*i+j];
    	    mat2[i][j]=vaux2[3*i+j];
    	}
    }
	

	//print_matriz(3,mat1);
	Cholesky(3,mat1);
	Cholesky(3,mat2);

	ConjugateGradient(3,mat1,b1,x1);

	for(int i=0;i<3;i++)
		printf("%f ", x1);

	//print_matriz(3,mat2);

	ConjugateGradient(3,mat2,b2,x2);

	for(int i=0;i<3;i++)
		printf("%f ", x2);

	return 0;
}