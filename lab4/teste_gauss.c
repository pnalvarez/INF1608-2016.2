#include <stdio.h>
#include "gauss.h"
#include "matriz.h"

int main(void){
  double** mat;
  double** mat2;
  double* vet;
  double * vet2;
  double* x;
  double* y;
  int i;
  mat = mat_cria(3,3);
  mat2 = mat_cria(6,6);
  vet = vet_cria(3);
  vet2 = vet_cria(6);
  x = vet_cria(3);
  y = vet_cria(6);

  vet[0] = 3;
  vet[1] = 3;
  vet[2] = -6;
  
  vet2[0] = 2.5;
  vet2[1] = 1.5;
  vet2[2] = 1;
  vet2[3] = 1;
  vet2[4] = 1.5;
  vet2[5] = 2.5;


  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[0][2] = -1;
  
  mat[1][0] = 2;
  mat[1][1] = 1;
  mat[1][2] = -2;
  
  mat[2][0] = -3;
  mat[2][1] = 1;
  mat[2][2] = 1;

  mat2[0][0] = 3;
  mat2[0][1] = -1;
  mat2[0][2] = 0;
  mat2[0][3] = 0;
  mat2[0][4] = 0;
  mat2[0][5] = 0.5;

  mat2[1][0] = -1;
  mat2[1][1] = 3;
  mat2[1][2] = -1;
  mat2[1][3] = 0;
  mat2[1][4] = 0.5;
  mat2[1][5] = 0;

  mat2[2][0] = 0;
  mat2[2][1] = -1;
  mat2[2][2] = 3;
  mat2[2][3] = -1;
  mat2[2][4] = 0;
  mat2[2][5] = 0;

  mat2[3][0] = 0;
  mat2[3][1] = 0;
  mat2[3][2] = -1;
  mat2[3][3] = 3;
  mat2[3][4] = -1;
  mat2[3][5] = 0;

  mat2[4][0] = 0;
  mat2[4][1] = 0.5;
  mat2[4][2] = 0;
  mat2[4][3] = -1;
  mat2[4][4] = 3;
  mat2[4][5] = -1;

  mat2[5][0] = 0.5;
  mat2[5][1] = 0;
  mat2[5][2] = 0;
  mat2[5][3] = 0;
  mat2[5][4] = -1;
  mat2[5][5] = 3;
  
  gauss(3, mat, vet, x);
  for(i = 0; i < 3; i++){
    printf("%.1g ", x[i]);
  }
  printf("\n");
  
  gauss(6, mat2, vet2, y);
  for(i = 0; i < 6; i++){
    printf("%.1g ", y[i]);
  }
  printf("\n");
    
  return 0;
}