#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int N, degree, digitsN, maxDigits, i, j, firstN, secondN, firstIndex = 0, secondIndex = 0;;
	long long NSquare, NSquare2;
	char number[10], reverseNumber[10], first[5], second[5];
	while(scanf("%d",&degree) != EOF)
	{
		maxDigits = degree;
		number[maxDigits] = '\0';
		for(N=0; N<pow(10, degree/2); N++)
		{
			for(i=0; i<maxDigits; i++)
			{
				number[i] = '0';
				reverseNumber[i] = '0';
			}
			NSquare = N*N;
			//printf("%lld\n",NSquare);
			digitsN = 0;
			int temp = NSquare;
			while(temp != 0)
			{
				reverseNumber[digitsN] = temp%10+'0';
				temp = temp/10;
				digitsN ++;
			}
			for(i=0; i<maxDigits; i++)
				number[i] = reverseNumber[maxDigits-1-i];
			
			firstIndex = 0;
			secondIndex = 0;
			for(j=0; j<maxDigits; j++)
			{
				if(j < degree/2)
				{
					first[firstIndex] = number[j];
					firstIndex ++;
				}
				else
				{
					second[secondIndex] = number[j];
					secondIndex ++;
				}
			}
			first[firstIndex] = '\0';
			second[secondIndex] = '\0';
			firstN = atoi(first);
			secondN = atoi(second);
			if((firstN+secondN) == N)
			{
				for(i=0; i<maxDigits; i++)
					printf("%c", number[i]);
				printf("\n");
			}
		}
	}
	
	return 0;
}
