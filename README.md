# 2019-Summer-Coding-Camp-Problems

## * 개요
2019년 경북대학교 전자공학부에서 시행한 여름 코딩캠프 문제에 대한 해답 코드이다. 문제는 파일 첨부 돼있다.
담당 연구실 : [ARCHITECTURE AND COMPILER FOR EMBEDDED SYSTEMS LAB](http://www.aces.re.kr/aces/ "ARCHITECTURE AND COMPILER FOR EMBEDDED SYSTEMS LAB")

------------
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
------------
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
------------
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
------------
#### 4) 목걸이 끊기
```c
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
```
목걸이를 두 배로 늘인다. 검색의 편의성을 키우기 위함이다.
```c
	int i, j;
	int count = 0, save_Length = 0, temp_Length = 0;
	char save_Letter;

	// 한 보석에서 그 뒤로 모든 보석을 살핀다.
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
			
			// 색깔이 2번 변하면 빠져나온다.
			if(count == 2)
			{
				count -= 2;
				break;
			}
			
			// 길이를 1 추가한다.
			temp_Length++;
		}
		if(save_Length < temp_Length) save_Length = temp_Length;
	}
	if(save_Length > beads_Number) save_Length = beads_Number;
	fprintf(fout, "%d\n", save_Length);
```
------------
#### 5) 우유 짜기
```c
typedef struct f
{
	int start_time;
	int end_time;
} farm;
```
시작 시과 종료 시간을 가지는 구조체 생성
```c
	int cow = 0;
	fscanf(fin, "%d", &cow);
	farm t[cow];		
	for(int i = 0; i < cow; i++) fscanf(fin, "%d %d", &t[i].start_time, &t[i].end_time);
	qsort(t, cow, sizeof(t[0]), compare);
```
구조체형 배열에 입력을 받고, 시작 시간에 따라 배열을 정렬한다.
```c
	// 다른 착유 시간 안에 들어가는 착유 시간을 제거
	farm tmp[cow];		
	for(int i = 0; i < cow; i++) tmp[i] = t[i];
	for(int i = 0; i < cow; i++)
	{
		for(int j = 0; j < cow; j++)
		{
			if((tmp[j].start_time >= tmp[i].start_time) && (tmp[j].start_time <= tmp[i].end_time)) tmp[j].start_time = tmp[i].start_time;
		}
	}
	// 가장 오래 착유하는 시간을 구한다.
	int longtime = 0, temp = 0;
	for(int i = 0; i < cow; i++)
	{
		temp = tmp[i].end_time - tmp[i].start_time;
		if(temp >= longtime) longtime = temp;
	}	
```
```c
	// 다른 착유 시간 안에 들어가는 착유 시간을 제거
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
	
	// 인접한 두 시간 사이의 자유시간을 저장, 비교
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
```
---------
#### 6) 패턴 변형
```c
	int count1 = 0;
	char spin90[N][N];
	
	// 원하는 변형에 맞는 식을 찾아내서 행렬에 적용시킨다.
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{	
			*(*(spin90 + j) + N-1-i) = *(*(before + i) + j);
		}
	}
	
	// 구하고자 하는 행렬과 일치하는 지 판별한다.
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(spin90[i][j] == after[i][j]) count1++;
		}
	}
```
다른 모든 변환도 위와 구성이 같다.
----------
#### 7) 
```c
char name[13];
	long long number = 0;
	int count = 0;
	
	// 리스트에 적힌 모든 이름을 불러온다
	for(int i = 0; i < 5000; i++, number = 0)
	{
		fscanf(dict, "%s", name);
		
		//각각의 이름에 맞는 숫자들로 변형한다.
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

		// 이름과 비교하여 출력한다.
		if(number == num)
		{
			count++;
			fprintf(fout, "%s\n", name);
			break;
		}
	}
```
----------
#### 8) 회문 찾기
```c
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
```
입력한 10진수 숫자를 n진수 문자열로 변환하는 함수이다.
```c
	int nary = 0; // 진수 입력
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

		for(int j = 0; result[j] != '\0'; j++) count++; // 길이 계산
		
		// 처음과 끝을 비교
		for(int j = 0; j < count; j++)
		{
			if(result[j] == result[count - 1 - j]) k++;
		}

		if(k == count)
		{
			change(nary, i, r);
			
			//기존 값 출력
			for(int j = 0; r[j] != '\0'; j++) rc++;	
			for(int j = rc - 1; j >= 0; j--) fprintf(fout, "%c", r[j]);
			fprintf(fout, " ");
			
			//제곱 값 출력
			for(int j = count - 1; j >= 0; j--) fprintf(fout, "%c", result[j]);	
			fprintf(fout, "\n");	
		}
		count = 0;
		k = 0;
		rc = 0;
	}
```
---------
#### 9) 이중 회문 
```c
void change(int n, int num, char *result )
{
	char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for(int i = 0; num > 0; i++)
	{
		result[i] = arr[num % n];
		num = num / n;
	}
}
```
주어진 입력을 n진법 문자열로 변환하는 함수이다.
```c
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
			// 2에서 10진법 까지
			for(k = 2; k <= 10; k++, count_length = 0, count_same = 0)
			{
				change(k, j, result);
				// 변환된 문자열의 길이를 측정하고
				for(l = 0; result[l] != '\0'; l++) count_length++;
				
				// 앞과 뒤 숫자를 비교하여
				for(m = 0; m < count_length; m++)
				{
					if(result[m] == result[count_length - 1 - m]) count_same++;	
				}
			
				for(n = 0; n < 32; n++) result[n] = '\0';
				
				// 회문인지를 판별하고
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
			
			// 2개 이상의 진법에서 회문일 경우 루프문 탈출
			if(count_pal == 2)
			{
				count_pal = 0;
				fprintf(fout, "%d\n", j - 1);
				break;	
			}
			count_pal = 0;
		}	
	}
```
----------
#### 10) 우유 구매
```c
typedef struct F
{
	int P;
	int A;
} Farmer;
```
가격과 개수에 관한 농부 구조체 생성
```c
	int total = 0;	
	int N = 0, M = 0;
	fscanf(fin, "%d %d", &N, &M);

	Farmer farmer[M];
	for(int i = 0; i < M; i++)
	{
		fscanf(fin, "%d %d", &(farmer + i)->P, &(farmer + i)->A);
	}
	
	// 가격 순으로 정렬
	qsort(farmer, M, sizeof(Farmer), compare);

	// 가장 낮은 가격 부터
	for(int i = 0; i < M; i++)
	{
		// 필요한 개수보다 가진 유닛이 작을 경우 풀 매수
		if(farmer[i].A <= N) 
		{
			N = N - farmer[i].A;
			total += farmer[i].A * farmer[i].P;
			if(N == 0) break;
		}
		
		// 아닐 경우 필요한 만큼 
		else
		{
			total += N * farmer[i].P;
			N = 0;
			break;
		}
	}	
```
