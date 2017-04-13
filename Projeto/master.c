# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"

double** findJacobi2(double s, double t, double* x, double* y) {  //funcao que determina a J usando o somatorio dos x e y obtidos vezes a funcao de s e t

	//int line, col;

	double dfds = -.25*x[0] * (1 - t) - .25*x[1] * (1 + t) + .25*x[2] * (1 + t) + .25*x[3] * (1 - t);
	double dgds = -.25*y[0] * (1 - t) - .25*y[1] * (1 + t) + .25*y[2] * (1 + t) + .25*y[3] * (1 - t);
	double dfdt = -.25*x[0] * (1 - s) + .25*x[1] * (1 - s) + .25*x[2] * (1 + s) - .25*x[3] * (1 + s);
	double dgdt = -.25*y[0] * (1 - s) + .25*y[1] * (1 - s) + .25*y[2] * (1 + s) - .25*y[3] * (1 + s);

	double** jacobi = mat_cria(2, 2);

	jacobi[0][0] = -dfds;
	jacobi[1][0] = -dfdt;
	jacobi[0][1] = -dgds;
	jacobi[1][1] = -dgdt;

	return jacobi;
}

double** findJacobi3(double s,double t, double r, double* x, double* y, double* z){ (1-s)(1-t)(1-r) (1-s+t-st)(1-r) (1-s-t+st -r+sr -str) (-1+t+r-tr)

	
double dfds= -.125*x[0]*(1-t-r+t*r)-.125*x[1]*(1-t-r-t*r)+.125*x[2]*(1+t-r-t*r)+.125*x[3]*(1-t-r+t*r)-.125*x[4]*(1-t+r-t*r)-.125*x[5]*(1+t+r+t*r)+.125*x[6]*(1+t+r+t*r)+.125*x[7]*(1-t+r-t*r);
double dgds= -.125*y[0]*(1-t-r+t*r)-.125*y[1]*(1-t-r-t*r)+.125*y[2]*(1+t-r-t*r)+.125*y[3]*(1-t-r+t*r)-.125*y[4]*(1-t+r-t*r)-.125*y[5]*(1+t+r+t*r)+.125*y[6]*(1+t+r+t*r)+.125*y[7]*(1-t+r-t*r);
double dhds= -.125*z[0]*(1-t-r+t*r)-.125*z[1]*(1-t-r-t*r)+.125*z[2]*(1+t-r-t*r)+.125*z[3]*(1-t-r+t*r)-.125*z[4]*(1-t+r-t*r)-.125*z[5]*(1+t+r+t*r)+.125*z[6]*(1+t+r+t*r)+.125*z[7]*(1-t+r-t*r);
double dfdt= -.125*x[0]*(1-s+r+s*r)+.125*x[1]*(1-s-r+s*r)+.125*x[2]*(1+s-r-s*r)-.125*x[3]*(1+s-r-s*r)-.125*x[4]*(1-s+r-s*r)+.125*x[5]*(1-s+r-s*r)+.125*x[6]*(1+s+r+s*r)-.125*x[7]*(1+s+r+s*r);
double dgdt= -.125*y[0]*(1-s+r+s*r)+.125*y[1]*(1-s-r+s*r)+.125*y[2]*(1+s-r-s*r)-.125*y[3]*(1+s-r-s*r)-.125*y[4]*(1-s+r-s*r)+.125*y[5]*(1-s+r-s*r)+.125*y[6]*(1+s+r+s*r)-.125*y[7]*(1+s+r+s*r);
double dhdt= -.125*z[0]*(1-s+r+s*r)+.125*z[1]*(1-s-r+s*r)+.125*z[2]*(1+s-r-s*r)-.125*z[3]*(1+s-r-s*r)-.125*z[4]*(1-s+r-s*r)+.125*z[5]*(1-s+r-s*r)+.125*z[6]*(1+s+r+s*r)-.125*z[7]*(1+s+r+s*r);
double dfdr= -.125*x[0]*(1-s+t+s*t)-.125*x[1]*(1-s+t-s*t)-.125*x[2]*(1+s+t+s*t)-.125*x[3]*(1+s-t-s*t)+.125*x[4]*(1-s-t+s*t)+.125*x[5]*(1-s+t-s*t)+.125*x[6]*(1+s+t+s*t)+.125*x[7]*(1+s-t-s*t);
double dgdr= -.125*y[0]*(1-s+t+s*t)-.125*y[1]*(1-s+t-s*t)-.125*y[2]*(1+s+t+s*t)-.125*y[3]*(1+s-t-s*t)+.125*y[4]*(1-s-t+s*t)+.125*y[5]*(1-s+t-s*t)+.125*y[6]*(1+s+t+s*t)+.125*y[7]*(1+s-t-s*t);

double** jacobi = mat_cria(3,3);

jacobi[0][0]=dfds;
jacobi[0][1]=dgds;
jacobi[0][2]=dhds;
jacobi[1][0]=dfdt;
jacobi[1][1]=dgdt;
jacobi[1][2]=dhdt;
jacobi[2][0]=dfdr;
jacobi[2][1]=dgdr;
jacobi[2][2]=dhdr;

return jacobi;
}

double** invert_matrix2(double** matrix) {// inverte uma matriz qualquer 2 por 2

	double** inverted = mat_cria(2, 2);
	double den = (matrix[1][0] * matrix[0][1] * matrix[0][1]) + (matrix[0][0] * matrix[0][1] * matrix[1][0] * matrix[1][1]);
	inverted[0][0] = (1 / matrix[0][1]) / ((-1 * (matrix[1][0] / matrix[1][1]) + (matrix[0][0] / matrix[0][1])));
	inverted[0][1] = (-1 * (matrix[0][1] * inverted[0][0])) / (matrix[1][1]);
	inverted[1][0] = (1 / (matrix[0][1])) + ((matrix[1][1] * matrix[0][0]) / den);
	inverted[1][1] = (-matrix[0][0]) / ((matrix[1][0] * matrix[0][1]) + (matrix[0][0] * matrix[1][1] * matrix[1][0]));

	return inverted;
}

double** invert_matriz3(double** matrix){

	double** inverted=mat_cria(3,3);
	double
}

double f_func(double* x, double s, double t) { //funcao de s e t obtida com os x vezes as funcoes parametricas

	double N[4], ret = 0.;
	int cnt_x;

	N[0] = .25*(1 - s)*(1 - t);
	N[1] = .25*(1 - s)*(1 + t);
	N[2] = .25*(1 + s)*(1 + t);
	N[3] = .25*(1 + s)*(1 - t);

	for (cnt_x = 0; cnt_x < 4; cnt_x++) {

		ret += (N[cnt_x] * x[cnt_x]);
	}

	return ret;
}

double f_func3(double* x,double s, double t, double r){

	double N[8],sum=0;
	int i;

	N[0]=.125*(1-s)*(1-t)*(1-r);
	N[1]=.125*(1-s)*(1+t)*(1-r);
	N[2]=.125*(1+s)*(1+t)*(1-r);
	N[3]=.125*(1+s)*(1-t)*(1-r);
	N[4]=.125*(1-s)*(1-t)*(1+r);
	N[5]=.125*(1-s)*(1+t)*(1+r);
	N[6]=.125*(1+s)*(1+t)*(1+r);
	N[7]=.125*(1+s)*(1-t)*(1+r);

     for(i=0;i<8;i++)
     	sum+=N[i]*x[i];

     return sum;

}

double g_func(double* y, double s, double t) {// o mesmo para y

	double N[4], ret = 0.;
	int cnt_y;

	N[0] = .25*(1 - s)*(1 - t);
	N[1] = .25*(1 - s)*(1 + t);
	N[2] = .25*(1 + s)*(1 + t);
	N[3] = .25*(1 + s)*(1 - t);

	for (cnt_y = 0; cnt_y < 4; cnt_y++) {

		ret += (N[cnt_y] * y[cnt_y]);
	}

	return ret;
}

double g_func3(double* y, double s, double t,double r){

double N[8],sum=0;
int i;

	N[0]=.125*(1-s)*(1-t)*(1-r);
	N[1]=.125*(1-s)*(1+t)*(1-r);
	N[2]=.125*(1+s)*(1+t)*(1-r);
	N[3]=.125*(1+s)*(1-t)*(1-r);
	N[4]=.125*(1-s)*(1-t)*(1+r);
	N[5]=.125*(1-s)*(1+t)*(1+r);
	N[6]=.125*(1+s)*(1+t)*(1+r);
	N[7]=.125*(1+s)*(1-t)*(1+r);

     for(i=0;i<8;i++)
     	sum+=N[i]*y[i];

     return sum;

}

double h_func3(double* z, double s, double t,double r){

double N[8],sum=0;
int i;

	N[0]=.125*(1-s)*(1-t)*(1-r);
	N[1]=.125*(1-s)*(1+t)*(1-r);
	N[2]=.125*(1+s)*(1+t)*(1-r);
	N[3]=.125*(1+s)*(1-t)*(1-r);
	N[4]=.125*(1-s)*(1-t)*(1+r);
	N[5]=.125*(1-s)*(1+t)*(1+r);
	N[6]=.125*(1+s)*(1+t)*(1+r);
	N[7]=.125*(1+s)*(1-t)*(1+r);

     for(i=0;i<8;i++)
     	sum+=N[i]*z[i];

     return sum;

}

double* findSTquad(double* x_quad, double* y_quad, double x_dot, double y_dot, double s, double t, double tol) {

	double* st = (double*)malloc(2 * sizeof(double)), st1 = (double*)malloc(2 * sizeof(double)), uv = (double*)malloc(2 * sizeof(double));
	double** Jinv;
	double* prod = (double*)malloc(2 * sizeof(double));
	double tolerance = 10.;

	int counter;

	for (counter = 0; counter < tol; counter++) {

		tolerance /= 10.;
	}

	st[0] = s; st[1] = t; st1[0] = s; st1[1] = t; uv[0] = x_dot - f_func(x_quad, s, t); uv[1] = y_dot - g_func(y_quad, s, t);

	do{

		st1[0] = st[0]; st1[1] = st[1];
		Jinv = invert_matrix2(findJacobi2(st[0], st[1], x_quad, y_quad));
		prod[0] = Jinv[0][0] * uv[0] + Jinv[1][0] * uv[1];
		prod[1] = Jinv[0][1] * uv[0] + Jinv[1][1] * uv[1];
		st1[0] = st[0] + prod[0];
		st1[1] = st[1] + prod[1];

	} while (st1[0] - st[0] > tolerance || st1[1] - st[1] > tolerance);

	return st1;
}

double* findSTRhexa(double* x_quad,double* y_quad,double* z_quad,double x_dot,double y_dot,double z_dot,double s, double t,double r, double tol){

  double* str=(double*)malloc(3*sizeof(double)), str1=(double*)malloc(3*sizeof(double)),uvw=(double*)malloc(3*sizeof(double));
  double** Jinv;
  double* prod=(double*)malloc(3*sizeof(double));
  double tolerance=10,;
  int i;

     for(i=0;i<10;i++)
     	tolerance/=10;

     str[0]=s;
     str[1]=t;
     str[2]=r;
     str1[0]=s;
     str1[1]=t;
     str1[2]=r;
     

     uvw[0]=x_dot-f_func3(x_quad,s,t,r);
     uvw[1]=y_dot-g_func3(y_quad,s,t,r);
     uvw[2]=z_dot-h_func3(z_quad,s,t,r);

     do{

     	str1[0]=str[0]; str1[1]=str[1]; str1[2]=str[2];
     	Jinv= invert_matrix3(findJacobi3(str[0],str[1],str[2],x_quad,y_quad,z_quad));
     	prod[0]=Jinv[0][0]*uvw[0]+Jinv[1][0]*uvw[1]+Jinv[2][0]*uvw[2];
     	prod[1]=Jinv[0][1]*uvw[0]+Jinv[1][1]*uvw[1]+Jinv[2][1]*uvw[2];
     	prod[2]=Jinv[0][2]*uvw[0]+Jinv[1][2]*uvw[1]+Jinv[2][2]*uvw[2];
     	str1[0]=str[0]+prod[0];
     	str1[1]=str[1]+prod[1];
     	str1[2]=str[2]+prod[2];
     }while(str1[0]-str[0]>tolerance||str1[1]-str[1]>tolerance||str1[2]-str[2]>tolerance);

     return str1;
	
}

int main() {


  double x[4]={1,1,-1,-1};
  double y[4]={1,-1,1,-1};
  double x0=0.5;
  double y0=0.5;

  double* solucao=(double*)malloc(2*sizeof(double));

  solucao=findSTquad(x,y,x0,y0,0.5,1,6);


  printf("%f %f",solucao[0],solucao[1]);

  //free(solucao);

	return 0;
}