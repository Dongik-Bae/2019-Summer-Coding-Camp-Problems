/*
ID: BaeDongik
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Person
{
	char name[15];
	int money;
};

int main()
{
	FILE *fin, *fout;
	fin = fopen("gift1.in", "r");
	fout = fopen("gift1.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int NP;
	fscanf(fin, "%d", &NP);
	char tempName[15];

	struct Person p[NP];
	for(int i = 0; i < NP; i++)
	{
		fscanf(fin, "%s", tempName);	
		strcpy(p[i].name, tempName);
		p[i].money = 0;
	}

	for(int i = 0; i < NP; i++)
	{
		int NG, totalMoney;
		fscanf(fin, "%s", tempName);
		fscanf(fin, "%d %d", &totalMoney, &NG);

		if(NG == 0)
			continue;
		int charge = totalMoney % NG;

		for(int j = 0; j < NP; j++)
		{	
			if(strcmp(p[j].name, tempName) == 0)
				p[j].money -= (totalMoney - charge);
		}
		
		for(int j = 0; j < NG; j++)
		{
			fscanf(fin, "%s",tempName);
			for(int k = 0; k < NP; k++)
			{
				if(strcmp(p[k].name, tempName) == 0)
				p[k].money += totalMoney / NG;
			}
			
		}
	}	
	for(int i = 0; i < NP; i++)
	{
		fprintf(fout, "%s %d\n", p[i].name, p[i].money);
	}
	
	// code--------------------------------- */
	
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
