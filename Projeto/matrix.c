
# include "matrix.h"
# include <stdlib.h>

double** mat_cria (int m, int n) // CORRETA
{
	double **A;
	int ind;
	
	A = (double**)malloc(m*sizeof(double*));
	
	for (ind = 0; ind < m; ind++)
	{
		*(A + ind) = (double*)malloc(n*sizeof(double));
	}
	
	return A;
}

void mat_libera (int m, double** A) // CORRETA
{
	int i, j;
	
	for(i = 0; i < m; i++)
	{
		free(*(A + i));
	}
	
	free(A);
}

void mat_transposta (int m, int n, double** A, double** T) // CORRETA
{
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			T[i][j] = A[j][i];

		}
	}
}

void mat_multv (int m, int n, double** A, double* v, double* w)
{
	int i, j;
	
	for (j = 0; j < m; j++) w[j] = 0;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			w[j] += v[i] * A[j][i];
		}
	}
}

void mat_multm (int m, int n, int q, double** A, double** B, double** C)
{
	int i, j, k;
	
	// zerando a matriz de resultado:
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < q; j++)
		{
			C[i][j] = 0.0;
		}
	}
	
	// realizando a multiplicacao:
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < q; j++)
		{
			for (k = 0; k < n; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


































