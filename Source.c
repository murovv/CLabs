#include <windows.h>
#include<stdio.h>
int main(int argv, char** argc) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char c;
	float f;
	printf("Введите символ: ");
	scanf_s("%c", &c);
	printf("Введите вещественное число: ");
	scanf_s("%f", &f);
	printf("Символ: %c\nВещественное число: %f", c, f);
	return 0;
}