#include <stdio.h>
#include <stdlib.h>

int main(){

float time[] = {};

size_t size = sizeof(time)/sizeof(float);

float average = 0;

for (int i = 0; i < size; i++){

    average = average + time[i];
}

    average = average/size;
    printf("%f", average);
}
