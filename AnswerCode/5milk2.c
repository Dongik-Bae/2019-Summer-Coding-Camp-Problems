/*
ID: BaeDongik
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct f
{
	int start_time;
	int end_time;
} farm;

int compare(const void *m, const void *n)
{
	farm *a = (farm*)m;
	farm *b = (farm*)n;

	return a->start_time - b->start_time;
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("milk2.in", "r");
	fout = fopen("milk2.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int cow = 0;
	fscanf(fin, "%d", &cow);

	farm t[cow];		
	for(int i = 0; i < cow; i++) fscanf(fin, "%d %d", &t[i].start_time, &t[i].end_time);

	qsort(t, cow, sizeof(t[0]), compare);


	farm tmp[cow];		
	for(int i = 0; i < cow; i++) tmp[i] = t[i];
	for(int i = 0; i < cow; i++)
	{
		for(int j = 0; j < cow; j++)
		{
			if((tmp[j].start_time >= tmp[i].start_time) && (tmp[j].start_time <= tmp[i].end_time)) tmp[j].start_time = tmp[i].start_time;
		}
	}
	
	int longtime = 0, temp = 0;
	for(int i = 0; i < cow; i++)
	{
		temp = tmp[i].end_time - tmp[i].start_time;
		if(temp >= longtime) longtime = temp;
	}


	int arr[cow];
	for(int i = 0; i < cow; i++) arr[i] = 1;	
	for(int i = 0; i < cow; i++)
	{
		for(int j = 0; j < cow; j++)
		{
			if(i != j)
			{
				if((t[i].start_time <= t[j].start_time) && (t[j].end_time <= t[i].end_time)) arr[j] = 0;
			}
		}
	}
	
	int freetime = 0;
	int term = 0;
	for(int i = 0, j = 1; i < cow-1;)
	{
		if(arr[j] == 0)
		{
			j++;
			continue;
		}
		if(arr[i] == 0)
		{
			i++;
			continue;
		}
		
		term = t[j].start_time - t[i].end_time;
		if((term > 0) && (freetime < term)) freetime = term;
		
		i++;
		j++;
	}


	fprintf(fout, "%d %d\n", longtime, freetime);

	// code--------------------------------- */
	
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
