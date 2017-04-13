
#include <stdio.h>
#include "poly.h"

Sample * Chebyshev (int n, double a, double b, double (*f) (double x))
{
	Sample * s;
	int i;
	double f1, f2;
	int beta;
	s = malloc(sizeof(Sample));
	s->n = n;
	s->x = (double *) malloc(sizeof(double )*n);
	s->y = (double *) malloc(sizeof(double )*n);

	f1 = (b - a) / 2;
	f2 = (b + a) / 2;

	for(i = 0; i < n ; i++)
	{
		beta = 2*i + 1;

		s->x[i] = f1 * cos((beta*M_PI) / (2*n)) + f2;
		s->y[i] = f(s->x[i]);

	}   

	return s;

}


double * NewtonCompute(Sample * s)
{
	int i, j,k;
	int n = s->n;
	double * coef = (double *) malloc(sizeof(double) *n);
	double ** y;
	y = (double **) malloc(sizeof(double) * n);

	for(i = 0 ; i < n ; i++)
		y[i] = (double*) malloc(sizeof(double)*n);

	for(i = 0; i < n; i++)
	{
		y[0][i] = s->y[i];
	}

	for(i=1;i<n;i++)
	{
		k=i;
		for(j=0;j<n-i;j++)
		{
			y[i][j]=(y[i-1][j+1]-y[i-1][j])/(s->x[k] - s->x[j]);
			k++;
		}
	}

	for(i = 0; i < n ; i++)
	{
		coef[i] = y[i][0];
	}

	return coef;
}

double NewtonEval(Sample *s, double *coef, double x)
{
	int i, j;
	int n = s->n;
	double res = 0;
	double mult = 1;
	res = coef[0];
	for(i = 1 ; i < n ; i++)
	{
		mult = 1;
		mult *= coef[i];
		for(j = i - 1; j >= 0; j--)
		{
			mult*= (x - s->x[j]);
		}
		res += mult;
	}

	return res;
}