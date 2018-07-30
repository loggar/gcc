#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * $ categorize UFO gpsdata_aliens.csv Elvis gpsdata_elvises.csv gpsdata_rest.csv
 */
int main(int argc, char *args[])
{
	if (argc != 6)
	{
		fprintf(stderr, "You need to give 5 arguments\n");
		return 1;
	}

	FILE *in;
	if (!(in = fopen("gpsdata.data", "r")))
	{
		fprintf(stderr, "Can't open the file.\n");
		return 1;
	}

	FILE *file1;
	if (!(file1 = fopen(args[2], "w")))
	{
		fprintf(stderr, "Can't open the file.\n");
		return 1;
	}

	FILE *file2;
	if (!(file2 = fopen(args[4], "w")))
	{
		fprintf(stderr, "Can't open the file.\n");
		return 1;
	}

	FILE *file3;
	if (!(file3 = fopen(args[5], "w")))
	{
		fprintf(stderr, "Can't open the file.\n");
		return 1;
	}

	char line[80];

	while (fscanf(in, "%79[^\n]\n", line) == 1)
	{
		if (strstr(line, args[1]))
			fprintf(file1, "%s\n", line);
		else if (strstr(line, args[3]))
			fprintf(file2, "%s\n", line);
		else
			fprintf(file3, "%s\n", line);
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	return 0;
}
