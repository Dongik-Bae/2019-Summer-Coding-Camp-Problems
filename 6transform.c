/*
ID: BaeDongik
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	FILE *fin, *fout;
	fin = fopen("transform.in", "r");
	fout = fopen("transform.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int N = 0;
	fscanf(fin, "%d", &N);

	char before[N][N];
	for(int i = 0; i < N; i++) fscanf(fin, "%s", *(before + i));
	
	char c = before[0][0];
	char after[N][N];
	for(int i = 0; i < N; i++) fscanf(fin, "%s", *(after + i));


	before[0][0] = c;
	int same = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++) if(before[i][j] == after[i][j]) same++; 
	}
	
	int count1 = 0;
	char spin90[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{	
			*(*(spin90 + j) + N-1-i) = *(*(before + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(spin90[i][j] == after[i][j]) count1++;
		}
	}
	
	int count2 = 0;
	char spin180[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			*(*(spin180 + N-1-i) + N-1-j) = *(*(before + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(spin180[i][j] == after[i][j]) count2++;
		}
	}
	

	int count3 = 0;
	char spin270[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			*(*(spin270 + N-1-j) + i) = *(*(before + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(spin270[i][j] == after[i][j]) count3++;
		}
	}


	int count4 = 0;
	char mirror[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			*(*(mirror + i) + N-1-j) = *(*(before + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(mirror[i][j] == after[i][j]) count4++;
		}
	}


	int count51 = 0, count52 = 0, count53 = 0;
	char base[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			*(*(base + i) + N-1-j) = *(*(before + i) + j);
		}
	}
	char combi1[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{	
			*(*(combi1 + j) + N-1-i) = *(*(base + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(combi1[i][j] == after[i][j]) count51++;
		}
	}
	char combi2[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			*(*(combi2 + N-1-i) + N-1-j) = *(*(base + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(combi2[i][j] == after[i][j]) count52++;
		}
	}
	char combi3[N][N];
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{	
			*(*(combi3 + N-1-j) + i) = *(*(base + i) + j);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(combi3[i][j] == after[i][j]) count53++;
		}
	}


	if(count1 == N*N) fprintf(fout, "1\n");
	else if(count2 == N*N) fprintf(fout, "2\n");
	else if(count3 == N*N) fprintf(fout, "3\n");
	else if(count4 == N*N) fprintf(fout, "4\n");
	else if((count51 == N*N) || (count52 == N*N) || (count53 == N*N)) fprintf(fout, "5\n");
	else if(same == N*N) fprintf(fout, "6\n");
	else fprintf(fout, "7\n");


	// code--------------------------------- */
	
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
