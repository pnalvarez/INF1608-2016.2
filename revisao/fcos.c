#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fcos.h"

#define PI 3.14159265

double fcos(double x){

 return cos(PI/2)-(sin(PI/2)/2)*pow((x-PI/2),1)-(cos(PI/2)/6)*pow(x-PI/2,2)+(sin(PI/2)/24)*pow((x-PI/2),3)+(cos(PI)/120)*pow((x-PI/2),4);

}