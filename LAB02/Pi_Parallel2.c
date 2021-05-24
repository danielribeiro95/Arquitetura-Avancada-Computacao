#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define N 1000000000
#define num_thread 8

const float N1 = N;
double dx = 1/N1;
double pi = 0;
pthread_t thread[num_thread];
pthread_mutex_t gLock;


void *compute(void *arg){
	int num = *((int*)arg);
    double partial_sum = 0;

    for (int i = num;i<N;i+=num_thread){
    partial_sum += (4/(1+pow((i)*dx,2)))*dx;
    }
    pthread_mutex_lock(&gLock);
    pi += partial_sum;
    pthread_mutex_unlock(&gLock);

    return 0;
}


int main(){

int i,tNum[num_thread];
pthread_mutex_init(&gLock, NULL);

for ( i = 0; i < num_thread; i++ ) {
tNum[i] = i;
pthread_create(&thread[i],NULL,compute,(void*)&tNum[i]);      
}

for (int i = 0; i< num_thread; i++){
    pthread_join(thread[i],NULL);
}

    printf("\npi = %lf \n", pi);
    pthread_mutex_destroy(&gLock);
    return 0;
}
