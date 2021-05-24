#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(){


float N = 1000000000;
double dx = 1/N;
double sum = 0;

for (int i = 0; i <N ;i++){
    sum = sum + (4/(1+pow(i*dx,2)))*dx;
}


printf("pi = %f\n",sum);
}
