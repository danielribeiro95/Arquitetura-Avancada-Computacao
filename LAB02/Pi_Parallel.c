#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

#define N 100000000

double dx = 1/N;
double pi[N];


void *compute(void *arg){
	int *i = (int*)arg;
    pi[*i] =  (4/(1+pow((*i)*dx,2)))*dx;
}

int main(){
clock_t t = clock();

double sum = 0;

pthread_t thread[N];


for (int i = 0; i < N; i++){
    pthread_create(&thread[i],NULL,compute,&i);
}

for (int i = 0; i< N; i++){
    pthread_join(thread[i],NULL);
    sum = sum + pi[i];
}
    printf("%lf", sum);
    double tempo = ((double)t)/CLOCKS_PER_SEC;
	printf("Tempo de execucao: %f\n",tempo);
}



