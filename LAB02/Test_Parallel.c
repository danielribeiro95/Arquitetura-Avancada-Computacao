#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

void test(){
    printf("Test \n");
}


void main(){

    pthread_t thread1;

    pthread_create(&thread1,NULL,&test,NULL);

    pthread_join(thread1,NULL);

}
