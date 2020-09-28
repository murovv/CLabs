#include<stdio.h>
int main(){
	int a;
	scanf_s("%d", &a);
	int right = 50;
	int left = -50;
	int sign = (right - a) * (a - left);
	printf("%d\n", sign >> (8 * sizeof(int) - 1));
	unsigned int b;
	scanf_s("%d", &b);
	printf("%d", (b>>(18))&1);

}