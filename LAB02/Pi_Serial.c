#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(){
clock_t t;
t = clock();

float N = 1000000;
double dx = 1/N;
double sum = 0;

for (int i = 0; i <N ;i++){
    sum = sum + (4/(1+pow(i*dx,2)))*dx;
}

t = clock() - t;
double tempo = ((double)t)/CLOCKS_PER_SEC;

printf("pi = %f\n Tempo de Execucao: %f \n",sum,tempo);
}
