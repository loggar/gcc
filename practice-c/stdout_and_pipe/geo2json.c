#include <stdio.h>

/* 
 * $ ./geo2json < gpsdata.csv
 * $ ./geo2json < gpsdata.csv > gpsdata.json
 * $ ./geo2json < gpsdata.csv > gpsdata.json 2>gpsdata_err.txt
 */
int main()
{
	float latitude;
	float longitude;
	char info[80];
	int started = 0;
	int err_count = 0;

	puts("{\"data\" : [");
	while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
	{
		if ((latitude < -90.0) || (latitude > 90.0) || (longitude < -180.0) || (longitude > 180.0))
		{
			fprintf(stderr, "Invalid Value: {latitude: %f, longitude: %f, info: '%s'}\n", latitude, longitude, info);
			err_count++;
		}
		else
		{
			if (started)
				printf(",\n");
			else
				started = 1;
			printf("{\"latitude\": %f, \"longitude\": %f, \"info\": \"%s\"}", latitude, longitude, info);
		}
	}
	puts("\n]}");
	return 0;
}