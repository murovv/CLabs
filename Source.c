#include <windows.h>
#include<stdio.h>
int main(int argv, char** argc) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char c;
	float f;
	printf("������� ������: ");
	scanf_s("%c", &c);
	printf("������� ������������ �����: ");
	scanf_s("%f", &f);
	printf("������: %c\n������������ �����: %f", c, f);
	return 0;
}