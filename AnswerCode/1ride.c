/*
ID: BaeDongik
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int calculate(char something[])
{
	int i, result = 1;	
	for(i = 0; something[i] != '\0'; i++)
	{
		result *= (something[i]-64);
		result = result % 47;
	}

	return result;
}


int main()
{
	FILE *fin, *fout;
	char comet[7];
	char group[7];

	fin = fopen("ride.in", "r");
	fout = fopen("ride.out", "w");
	assert((fin != NULL) && (fout != NULL));

	fscanf(fin, "%s", comet);
	fscanf(fin, "%s", group);

	if(calculate(comet) == calculate(group)) fprintf(fout, "GO\n");
	else fprintf(fout, "STAY\n");

	fclose(fin);
	fclose(fout);

	return 0;
}	
