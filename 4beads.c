/*
ID: BaeDongik
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	FILE *fin, *fout;
	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int beads_Number = 0;
	fscanf(fin, "%d", &beads_Number);

	char input_N[beads_Number];
	fscanf(fin, "%s", input_N);

	char temp_N[beads_Number * 2];
	for(int i = 0; i < beads_Number; i++)
	{
		temp_N[i] = input_N[i];
	}
	for(int i = beads_Number; i < 2 * beads_Number; i++)
	{
		temp_N[i] = input_N[i-beads_Number];
	}

	int i, j;
	int count = 0, save_Length = 0, temp_Length = 0;
	char save_Letter;

	for(i = 0, j = 0; i < beads_Number; i++, temp_Length = 0)
	{	
		save_Letter = temp_N[i];
		for(j = i; j < beads_Number * 2; j++)
		{
			if(temp_N[j] == 'r')
			{
				if(save_Letter == 'b' )	count++;
				save_Letter = temp_N[j];
			}	
			else if(temp_N[j] == 'b')
			{
				if(save_Letter == 'r' ) count++;
				save_Letter = temp_N[j];
			}	

			if(count == 2)
			{
				count -= 2;
				break;
			}
			temp_Length++;
		}

		if(save_Length < temp_Length) save_Length = temp_Length;
	}

	if(save_Length > beads_Number) save_Length = beads_Number;
	fprintf(fout, "%d\n", save_Length);
			

	// code--------------------------------- */
	
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
