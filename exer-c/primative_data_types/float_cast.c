#include <stdio.h>

float test_1(int x, int y)
{
	float z = x / y;
	return z;
}

float test_2(int x, int y)
{
	float z = (float)x / (float)y;
	return z;
}

int main()
{
	int x = 7;
	int y = 2;

	printf("test_1: %.2f\n", test_1(x, y));
	printf("test_2: %.2f\n", test_2(x, y));
	return 0;
}