#include<stdio.h>
int main() {
	double a;
	scanf_s("%lf", &a);
	double z2 = (4 - a * a) / 2;
	double div1 = 2 * a + a * a;
	double div2 = 2 * a - a * a;
	if (div1 == 0|| div2 == 0) {
		printf("incorrect input for z1\n");
		printf("%lf", z2);
		return 0;
	}
	double z1 = (1 + a + a * a) / (div1)+2 - (1 - a + a * a) / div2;
	if (z1 == 0) {
		printf("incorrect input for z1\n");
		printf("%lf", z2);
		return 0;
	}
	z1 = (1 / z1) * (5 - 2 * a * a);
	printf("%lf %lf", z1, z2);
	return 0;
}
