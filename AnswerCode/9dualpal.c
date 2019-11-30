/*
ID: BaeDongik
LANG: C
TASK: dualpal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void change(int n, int num, char *result )
{
	char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for(int i = 0; num > 0; i++)
	{
		result[i] = arr[num % n];
		num = num / n;
	}
}

int main()
{
	FILE *fin, *fout;
	fin = fopen("dualpal.in", "r");
	fout = fopen("dualpal.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int N = 0, S = 0;
	fscanf(fin, "%d %d", &N, &S);

	char result[32];
	for(int i = 0; i < 32; i++) result[i] = '\0';

	int count_pal = 0, count_length = 0, count_same = 0;
	int i, j = S + 1, k, l, m, n;
	for(i = 1; i <= N; i++)
	{
		while(1)
		{
			for(k = 2; k <= 10; k++, count_length = 0, count_same = 0)
			{
				change(k, j, result);
				for(l = 0; result[l] != '\0'; l++) count_length++;
				for(m = 0; m < count_length; m++)
				{
					if(result[m] == result[count_length - 1 - m]) count_same++;	
				}
			
				for(n = 0; n < 32; n++) result[n] = '\0';
				
				if(count_length == count_same)
				{
					count_pal++;
					if(count_pal == 2)
					{
						count_same = 0;
						count_length = 0;
						break;
					}
				}
			}

			j++;
			if(count_pal == 2)
			{
				count_pal = 0;
				fprintf(fout, "%d\n", j - 1);
				break;	
			}
			count_pal = 0;
		}	

	}








	// code--------------------------------- */
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
