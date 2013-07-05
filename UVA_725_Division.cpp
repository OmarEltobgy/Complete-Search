#include <stdio.h>
#include <stdlib.h>
int N;
char second[6];
char first[10];
int taken[10];
int isThere[10];
int solFlag;
int flag;

void calc(int i)
{
  second[5] = '\0';
	if(flag == 0)
		return;
	if(i == 5)
	{
		/*for(int k=0; k<5; k++)
			printf("%c", second[k]);
		printf("\n");*/
		int S = atoi(second);
		int F = N*S;
		//printf("%d %d\n",F,S);
		int temp = F, counter = 0;
		if(temp >= 100000)
		{
			flag = 0;
			return;
		}
		while(temp < 100000 && temp != 0)
		{
			first[4-counter] = temp%10+'0';
			counter ++;
			temp = temp/10;
		}
		/*for(int k=0; k<counter; k++)
			printf("%c", second[k]);
		printf("\n");*/
		if(counter == 5)
		{
			int k, isSol = 1;
			for(k=0; k<10; k++)
				isThere[k] = 0;
			for(k=0; k<5 && isSol==1; k++)
			{
				if(isThere[first[k]-'0'] == 0)
				{
					isThere[first[k]-'0'] = 1;
				}
				else
				{
					isSol = 0;
				}
			}
			for(k=0; k<5 && isSol==1; k++)
			{
				if(isThere[second[k]-'0'] == 0)
				{
					isThere[second[k]-'0'] = 1;
				}
				else
				{
					isSol = 0;
				}
			}
			if(isSol == 1)
			{
				solFlag = 1;
				for(k=0; k<5; k++)
					printf("%c", first[k]);
				printf(" / ");
				for(k=0; k<5; k++)
					printf("%c", second[k]);
				printf(" = %d\n", N);
			}
		}
		return;
	}
	for(int num=0; num<10; num++)
	{
		if(taken[num] == 0)
		{
			second[i] = num+'0';
			taken[num] = 1;
			calc(i+1);
			taken[num] = 0;
		}
	}
}

int main()
{
	scanf("%d",&N);
	while(N != 0)
	{
		solFlag = 0;
		flag = 1;
		calc(0);
		if(solFlag == 0)
			printf("There are no solutions for %d.\n", N);
		scanf("%d",&N);
		if(N != 0)
			printf("\n");	
	}
	return 0;
}
