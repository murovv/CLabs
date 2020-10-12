#include<stdio.h>
#include<stdlib.h>
int main(){

    int array[4];
    *array = -1;
    *(array+1) = -12;
    *(array+2) = -123;
    *(array+3) = -1234;
    for(int i = 0;i<4;i++){
        printf("%d ",*(array+i));
    }
    printf("\n");
    int *dynamicArray = (int*) malloc(4*sizeof(int));
    dynamicArray[0] = -1;
    dynamicArray[1] = -12;
    dynamicArray[2] = -123;
    dynamicArray[3] = -1234;
    for(int i = 0;i<4;i++){
        printf("%d ",dynamicArray[i]);
    }
    printf("\n");
}
