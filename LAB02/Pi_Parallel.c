#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define N 100

double dx = 1/N;
double pi[N];


void compute(int i){
    pi[i] =  (4/(1+pow(i*dx,2)))*dx;
}

int main(){

double sum = 0;
pthread_t thread[N];


for (int i = 0; i < N; i++){
    pthread_create(&thread[i],NULL,compute,NULL);
}

for (int i = 0; i< N; i++){
    pthread_join(thread[i],NULL);
    sum = sum + pi[i];
}

    printf("%lf", sum);
}


