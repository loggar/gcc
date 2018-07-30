#include <stdio.h>

/**
 * bermuda | geo2json < gpsdata.csv > gpsdata.json 2>gpsdata_err.txt
 */
int main()
{
	float latitude;
	float longitude;
	char info[80];
	while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
	{
		if ((latitude > 26) && (latitude < 34) && (longitude > -76) && (longitude < -64))
		{
			printf("%f,%f,%s\n", latitude, longitude, info);
		}
	}
	return 0;
}
