#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    freopen(argv[3],"w",stdout);
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d",(a+b));

}