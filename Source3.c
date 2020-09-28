#include<stdio.h>
int main() {
	int a;
	scanf_s("%o", &a);
	printf("%x\n",a);
	printf("%o\n", (a << 3));
	printf("%o\n", a);
	printf("%o\n", (~a));
	int b;
	scanf_s("%o", &b);
	printf("%o", (b & a));
}
