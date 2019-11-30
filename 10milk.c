/*
ID: BaeDongik
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct F
{
	int P;
	int A;
} Farmer;

int compare(const void *m1, const void *m2)
{
	Farmer *a = (Farmer *)m1;
	Farmer *b = (Farmer *)m2;

	return a->P - b->P;
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("milk.in", "r");
	fout = fopen("milk.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------
	int total = 0;	
	int N = 0, M = 0;
	fscanf(fin, "%d %d", &N, &M);

	Farmer farmer[M];
	for(int i = 0; i < M; i++)
	{
		fscanf(fin, "%d %d", &(farmer + i)->P, &(farmer + i)->A);
	}
	
	qsort(farmer, M, sizeof(Farmer), compare);

	for(int i = 0; i < M; i++)
	{
		if(farmer[i].A <= N) 
		{
			N = N - farmer[i].A;
			total += farmer[i].A * farmer[i].P;
			if(N == 0) break;
		}
		else
		{
			total += N * farmer[i].P;
			N = 0;
			break;
		}
	}	

	fprintf(fout, "%d\n", total);

	// code--------------------------------- */
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
