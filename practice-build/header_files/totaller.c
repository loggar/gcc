#include <stdio.h>

#include "totaller.h"

float total = 0.0;
short count = 0;
short tax_percent = 6;

int main()
{
	float val;
	float arr[5] = {10.0, 20.0, 30.0, 40.0, 50.0};

	for (int i = 0; i < 5; i++)
	{
		val = arr[i];
		printf("Total so far: %.2f\n", add_with_tax(val));
	}

	printf("\nFinal total: %.2f\n", total);
	printf("Number of items: %hi\n", count);

	return 0;
}

float add_with_tax(float f)
{
	float tax_rate = 1 + tax_percent / 100.0;
	total = total + (f * tax_rate);
	count = count + 1;
	return total;
}
