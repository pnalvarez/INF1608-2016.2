#include<stdio.h>
#include"fcos.h"

#define PI 3.141592653

double fcos(double x){

 return 0-(x-PI/2)+0+(1/6)*(x-PI/2)*(x-PI/2)*(x-PI/2)+0;
}

double residuo(double x){

if(x-PI/2>=0)

return (1/120)*(x-PI/2)*(x-PI/2)*(x-PI/2)*(x-PI/2)*(x-PI/2);

else
  return -1*(1/120)*(x-PI/2)*(x-PI/2)*(x-PI/2)*(x-PI/2)*(x-PI/2);
}
