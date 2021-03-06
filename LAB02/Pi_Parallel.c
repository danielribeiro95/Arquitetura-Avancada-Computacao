#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#define N 100000000
#define num_thread 8

const float N1 = N;
double dx = 1/N1;
double pi = 0;
pthread_t thread[num_thread];
pthread_mutex_t gLock;



void *compute(void *arg){
	int num = *((int*)arg);
    double partial_sum = 0.0,x;
    double h = 2.0 / N;

   for (int i = num; i < N; i += num_thread){
       x = -1 + (i + 0.5f) * h;
        partial_sum += sqrt(1.0 - x*x) * h;
        }
    pthread_mutex_lock(&gLock);
    pi += partial_sum;
    pthread_mutex_unlock(&gLock);

    return 0;
}


int main(){

clock_t t = clock();
int i,tNum[num_thread];
pthread_mutex_init(&gLock, NULL);

for ( i = 0; i < num_thread; i++ ) {
tNum[i] = i;
pthread_create(&thread[i],NULL,compute,(void*)&tNum[i]);      
}

for (int i = 0; i< num_thread; i++){
    pthread_join(thread[i],NULL);
}



    printf("%lf \n", 2*pi);
    t = clock()-t;
    double tempo = ((double)t)/CLOCKS_PER_SEC;
	printf("Tempo de execucao: %f\n",tempo);
    pthread_mutex_destroy(&gLock);
    return 0;
}



