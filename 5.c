#include<stdio.h>
int main(){
    int array[7] = {123,123,123,123,456,321,1}; 
    int matrixA[2][2] = {1,2,3,1};
    int matrixB[2][2] = {1,1,0,2};
    int matrixC[2][2] = {0};
    for(int i = 0;i<7;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    for(int i = 0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k = 0;k<2;k++){
                matrixC[i][j]+=matrixA[i][k]*matrixB[k][j];
            }
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    
}