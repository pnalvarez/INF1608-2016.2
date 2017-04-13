#include <stdio.h>
#include <stdlib.h>
#include "mmq.h"

int main(void){

 double** A=mat_cria(5,3);
 double** B=mat_cria(5,4);
 double** A2=mat_cria(8,2);
 double v_aux1[15]={3,-1,2,4,1,0,-3,2,1,1,1,5,-2,0,3};
 double v_aux2[20]={4,2,3,0,-2,3,-1,1,1,3,-4,2,1,0,1,-1,3,1,3,-2};
 double b[5]={10,10,-5,15,0};
 double b2[5]={10,2,0,5};
 double c[]= {8.0,12.3,15.5,16.8,17.1,15.8,15.2,14.0};
 double* xt = (double*)malloc(3*sizeof(double));
 double* xv = (double*)malloc(4*sizeof(double));
 double* x2 = (double*)malloc(2*sizeof(double));
 double* b3 = (double*)malloc(8*sizeof(double));
 double err[2],res2,t=0.0;
 int i,j;

 for(i=0;i<5;i++){
   for(j=0;j<3;j++)
   	 A[i][j]=v_aux1[3*i+j];
   }

   for(i=0;i<5;i++){
   	 for(j=0;j<4;j++)
   	 	 B[i][j]=v_aux2[4*i+j];
   }
     
    xt = mmq(5,3,A,b);
    xv = mmq(5,4,B,b2);
    err[0] = norma2(5,3,A,b,xt);
    err[1] = norma2(5,4,B,b2,xv);

    for(i=0;i<3;i++)
       printf("%f ",xt[i]);
    
    printf("\n\n");

    for(i=0;i<4;i++)
    	printf("%f ",xv[i]);

    printf("\n\n");

    for(i=0;i<2;i++)
    	printf("%f ",err[i]);

    mat_libera(5,A);
    mat_libera(5,B);
    free(xt);
    free(xv);

    //questao 4

    for(i = 0 ; i < 8 ; i++)
		b3[i] = log(c[i]) - log(i + 1);

	for(i = 0; i < 8; i++)
	{
		A2[i][0] = 1;
		A2[i][1] = i + 1;
	}

	x2 = mmq(8, 2, A2, b);
    
    res2 = 	norma2(8,2,B,b3,x2);

    x2[0] = exp(x2[0]);

    printf("%f %f \n %f \n",x2[0],x2[1],res2);

   for(t=0.0;t<=16.0;t+=0.1)
   	printf("t %f,c %f\n", t,(x2[0]*t*exp(x2[1]*t)));

	return 0;
 
}