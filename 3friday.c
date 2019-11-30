n*
ID: BaeDongik
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Date
{
	char day[3];
	int count;
};

int main()
{
	FILE *fin, *fout;
	fin = fopen("friday.in", "r");
	fout = fopen("friday.out", "w");
	assert((fin != NULL) && (fout != NULL));
	
	
	// code---------------------------------

	int input;
	fscanf(fin, "%d", &input);

	struct Date date[7];
	strcpy(date[0].day,"Sat");
	strcpy(date[1].day,"Sun");
	strcpy(date[2].day,"Mon");
	strcpy(date[3].day,"Tue");
	strcpy(date[4].day,"Wed");
	strcpy(date[5].day,"Thr");
	strcpy(date[6].day,"Fri");
	for(int i = 0; i < 7; i++)
	{
		date[i].count = 0;
	}

	int year = 1900, month = 1, day = 1, loop = 2;
	while(year < 1900+input)
	{
		if(month == 13)
		{
			month -= 12;
			year ++;
		}
		else if((year % 400 == 0) && (month == 2) && (day == 30))
		{
			day -= 29;
			month ++;
		}
		else if((year % 100 == 0) && (year % 400 != 0) && (month == 2) && (day == 29))
		{
			day -= 28;
			month ++;
		}
		else if((year % 4 == 0) && (month == 2) && (day == 30))
		{
			day -= 29;
			month ++;
			
		}
		else if((year % 4 != 0) && (month == 2) && (day == 29))
		{
			day -= 28;
			month ++;
		}
		else if ( ((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day == 31))
		{
			day -= 30;
			month ++;
		}
		else if(day == 32)
		{
			day -= 31;
			month ++;
		}
		else
		{	
			day ++;
			loop ++;
		}

		for(int i = 0; i < 7; i++)
		{
			if((day == 13) && (loop % 7) == i)
			{
				date[i].count ++;
			}
		}
	}
	
	fprintf(fout, "%d %d %d %d %d %d %d\n", date[0].count, date[1].count, date[2].count, date[3].count, date[4].count, date[5].count, date[6].count);




	// code--------------------------------- */
	
	
	fclose(fin);
	fclose(fout);
	exit(0);
}	
