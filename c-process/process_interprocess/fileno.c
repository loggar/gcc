#include <stdio.h>

int main()
{
	FILE *my_file = fopen("fileno.txt", "r");
	int descriptor = fileno(my_file);
	printf("descriptor %d", descriptor);
	fclose(my_file);
	return 0;
}
