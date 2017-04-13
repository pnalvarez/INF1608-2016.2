#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raiz.h"

double f(double x){

	return -pow(x,2)+1.8*x+2.5;
}

int main(void){

printf("%f\n",pontofixo(5,0.0005,f));

return 0;

}