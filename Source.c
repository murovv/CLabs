#include <windows.h>
#include<stdio.h>
int main(int argv, char** argc) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char c;
	float f;
	printf("input char: ");
	scanf_s("%c", &c);
	printf("input float: ");
	scanf_s("%f", &f);
	printf(" char: %c\n float: %f", c, f);
	return 0;
}
