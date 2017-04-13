#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "matriz.h"

double new_abs(double val){
  if(val > 0)
    return val;
  else
    return -val;

}
double* vet_cria(int m){
  double* vet;

  vet = (double*)malloc(m*sizeof(double));
  return vet;
}


void mat_multv(int m, int n, double** mat, double* v, double* w){
  int i, j;
  double sum = 0;
  int index = 0;

  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
      sum += (mat[i][j] * v[j]);
    }
    w[index] = sum;
    index++;
    sum = 0;
  }
}

void gauss (int n, double** A, double* b, double* x){
  int i, j, k, pivot = 0, lin, col, etapa = 1;
  double* y = (double*)malloc(n*sizeof(double));
  
  double singular, fact, temp, valPivot;
  valPivot = A[0][0];

  for(j = 0; j < n - 1; j++){                          


    if(etapa != 1){
      //encontra pivot
      pivot = j;
      for(lin = j+1; lin < n; lin++){
        if(A[pivot][j] < A[lin][j]){
          pivot = lin;
        }
      }

      //realiza troca das linhas 
      if(pivot != j){
        for(col = 0; col < n; col++){
          temp = A[pivot][col];
          A[pivot][col] = A[j][col];
          A[j][col] = temp;
          temp = b[pivot];
          b[pivot] = b[j];
          b[j] = temp;
        }
      }
    }

    //elimina coluna j 
    for(i = j + 1; i < n; i++){
      fact = A[i][j]/A[j][j]; 
      for(k = j; k < n; k++){
        if(k <= j){
          A[i][k] = fact;
        }
        else
          A[i][k] = A[i][k] - A[j][k]*fact;
      }
      b[i] = b[i] - b[j]*fact;
    }
    etapa++;
  }

  mat_multv(n, n, A, b, y);

  //SubstituiÁıes Sucessivas

  for(i = n - 1; i >= 0; i--){
    singular = 0;
    for( j = i + 1; j < n; j++){
      singular += A[i][j] * x[j];
    }
    x[i] = (b[i] - singular)/A[i][i];
  }
}