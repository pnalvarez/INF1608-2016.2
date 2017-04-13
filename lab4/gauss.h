#include <stdio.h>

void gauss (int n, double** A, double* b, double* x);
double** mat_cria(int m, int n);
void mat_multv(int m, int n, double** mat, double* v, double* w);
double* vet_cria(int m);
double new_abs(double val);