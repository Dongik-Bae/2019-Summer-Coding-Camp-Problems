# 2019-Summer-Coding-Camp-Problems

## * 개요
2019년 경북대학교 전자공학부에서 시행한 여름 코딩캠프 문제에 대한 해답 코드이다. 문제는 파일 첨부 돼있다.

#### 1) 혜성
```c
int calculate(char something[])
{
	int i, result = 1;
  
  //영어 대문자를 숫자로 변환
	for(i = 0; something[i] != '\0'; i++)
	{
		result *= (something[i]-64);
		result = result % 47;
	}

	return result;
}
```
아스키 코드에서 영어 대문자 A는 65이다. 입력된 문자에 64를 빼면 원하는 숫자를 뽑아낼 수 있다.
```C
if(calculate(comet) == calculate(group)) fprintf(fout, "GO\n");
	else fprintf(fout, "STAY\n");
```

#### 2) 선물 비용
```C
struct Person
{
	char name[15];
	int money;
};
```
이름과 돈의 정보를 가진 구조체를 설정한다.
```C
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

    // 나눠주는 금액을 당사자에게서 차감
		for(int j = 0; j < NP; j++)
		{	
			if(strcmp(p[j].name, tempName) == 0)
				p[j].money -= (totalMoney - charge);
		}
		
    // 나눠받는 금액을 당사자에게서 증감
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
```

#### 3) 13일의 금요일
윤년을 세는 시스템을 만드는 문제이다.
```c
struct Date
{
	char day[3];
	int count;
};
```
요일과 개수를 가지는 구조체를 생성한다.
```c
struct Date date[7];
	strcpy(date[0].day,"Sat");
	strcpy(date[1].day,"Sun");
	strcpy(date[2].day,"Mon");
	strcpy(date[3].day,"Tue");
	strcpy(date[4].day,"Wed");
	strcpy(date[5].day,"Thr");
	strcpy(date[6].day,"Fri");
```
7개의 구조체를 각각의 요일로 설정한다.
```c
int year = 1900, month = 1, day = 1, loop = 2;

	while(year < 1900+input)
	{
    // 13월이 되었을 때 년을 1 증가시키고 월을 1로 만듬
		if(month == 13)
		{
			month -= 12;
			year ++;
		}
    
    // 400년 단위 윤년에는 2월 30일일 때 월을 1 더해주고, 일을 1로 만듬
		else if((year % 400 == 0) && (month == 2) && (day == 30))
		{
			day -= 29;
			month ++;
		}
    
    // 100년 단위 윤년에는 2월 29일일 때 월을 1 더해주고, 일을 1로 만듬
		else if((year % 100 == 0) && (year % 400 != 0) && (month == 2) && (day == 29))
		{
			day -= 28;
			month ++;
		}
    
    // 4년 단위 윤년에는 2월 30일일 때 월을 1 더해주고, 일을 1로 만듬
		else if((year % 4 == 0) && (month == 2) && (day == 30))
		{
			day -= 29;
			month ++;
			
		}
    
    // 윤년이 아닐 때는 2월 29일일 때 월을 1 더해주고, 일을 1로 만듬      
		else if((year % 4 != 0) && (month == 2) && (day == 29))
		{
			day -= 28;
			month ++;
		}
    
    // 4, 6, 9, 11월 31일 때 월을 1 더해주고, 일을 1로 만듬
		else if ( ((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day == 31))
		{
			day -= 30;
			month ++;
		}
    
    // 나머지 월에는, 32일 때 월을 1 더해주고, 일을 1로 만듬
		else if(day == 32)
		{
			day -= 31;
			month ++;
		}
    
    // 루프를 돌 때마다 일을 1 추가
		else
		{	
			day ++;
			loop ++;
		}

    // 매월 13일이 무슨 요일인지 셈
		for(int i = 0; i < 7; i++)
		{
			if((day == 13) && (loop % 7) == i)
			{
				date[i].count ++;
			}
		}
	}
```
#### 4) 
