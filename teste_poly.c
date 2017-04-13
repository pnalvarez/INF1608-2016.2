#include <stdio.h>
#include <math.h>
#include "poly.h"

int fat(int n) 
{ 
	int r = 1; 
	for (int i=2; i<=n; i++) 
	r *= i; 
	return r; 
} 
int main(){
	int i;
	int a = 0;
	int b = M_PI/2;
	int n = 6;
	Sample * s =  Chebyshev (n,  a, b,cos);
	double *den;
	double *coef;
	double res;
	double erro;
	double x;
	printf("Amostras por chebyshev: \n");
	for(i = 0; i < 6; i++)
	{
		printf("X[%d]: %g Y[%d]: %g\n", i, s->x[i], i, s->y[i]);
	}

	x = 0;

	while(x <= M_PI/2)
	{

		coef = NewtonCompute(s);

		res = NewtonEval(s, coef, x);

		erro = (pow((b - a) / 2, n) / pow(2,n-1 )) * (pow(cos(x), n) / fat(n));
		
		if((res - cos(x)) <= erro)
		{
			printf("Resultado Newtown atende a precisao necessaria para x = %f\n", x);
		}else
		{
			printf("Resultado Newtown nao atende a precisao necessaria para x = %f\n", x);
		}

		x+= 0.3;
	}
	

	

