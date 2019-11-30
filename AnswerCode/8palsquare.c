/*
ID: BaeDongik
LANG: C
TASK: palsquare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void change(int n, int num, char *result)
{
	char arr[20] = {'0','1','2','3','4','5','6','7','8','9',
					'A','B','C','D','E','F','G','H','I','J'};

	for(int i = 0; num > 0; i++)
	{
		result[i] = arr[num % n];
		num = num / n;
	}
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("palsquare.in", "r");
	fout = fopen("palsquare.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int nary = 0;
	fscanf(fin, "%d", &nary);

	char result[20], r[20];
	for(int i = 0; i < 17; i++)
	{
		r[i] = '\0';
		result[i] = '\0';
	}
	int count = 0;
	int k = 0;
	int rc = 0;
	
	for(int i = 1; i <= 300; i++)
	{
		change(nary, i*i ,result);
		
		for(int j = 0; result[j] != '\0'; j++) count++;
		
		for(int j = 0; j < count; j++)
		{
			if(result[j] == result[count - 1 - j]) k++;
		}

		if(k == count)
		{
			change(nary, i, r);
			for(int j = 0; r[j] != '\0'; j++) rc++;	
			
			for(int j = rc - 1; j >= 0; j--) fprintf(fout, "%c", r[j]);
			fprintf(fout, " ");
			for(int j = count - 1; j >= 0; j--) fprintf(fout, "%c", result[j]);	
			fprintf(fout, "\n");	
		}
		count = 0;
		k = 0;
		rc = 0;
	}

	// code--------------------------------- */
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
