/*
ID: BaeDongik
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	FILE *fin, *fout, *dict;
	fin = fopen("namenum.in", "r");
	fout = fopen("namenum.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------
	dict = fopen("dict.txt", "r");

	long long num = 0;
	fscanf(fin, "%lld", &num);

	char name[13];
	long long number = 0;
	int count = 0;
	for(int i = 0; i < 5000; i++, number = 0)
	{
		fscanf(dict, "%s", name);
		for(int j = 0; name[j] != '\0'; j++)
		{
			if(name[j] == 'A' || name[j] == 'B' || name[j] == 'C') number = number * 10 + 2;
			else if(name[j] == 'Z' || name[j] == 'X' || name[j] == 'Y') number = number * 10 + 9;
			else if(name[j] == 'D' || name[j] == 'E' || name[j] == 'F') number = number * 10 + 3;
			else if(name[j] == 'G' || name[j] == 'H' || name[j] == 'I') number = number * 10 + 4;
			else if(name[j] == 'J' || name[j] == 'K' || name[j] == 'L') number = number * 10 + 5;
			else if(name[j] == 'M' || name[j] == 'N' || name[j] == 'O') number = number * 10 + 6;
			else if(name[j] == 'P' || name[j] == 'R' || name[j] == 'S') number = number * 10 + 7;
			else if(name[j] == 'T' || name[j] == 'U' || name[j] == 'V') number = number * 10 + 8;
		}

		if(number == num)
		{
			count++;
			fprintf(fout, "%s\n", name);
			break;
		}
	}

	if(count == 0) fprintf(fout, "NONE\n");


	// code--------------------------------- */
	
	fclose(dict);
	fclose(fin);
	fclose(fout);
	exit(0);
}	
