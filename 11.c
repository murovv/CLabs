#include"parameters.h"
#include<stdio.h>
int main(){
    triangle tr;
    scanf("%d%d%d%d%d%d",&tr.x1,&tr.x2,&tr.x3,&tr.y1,&tr.y2,&tr.y3);
    printf("%f\n",countP(tr));
    printf("%f",countS(tr));
}