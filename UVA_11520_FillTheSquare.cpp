#include <stdio.h>
char X[10][10];
int N;

bool check(char ch, int i, int j)
{
  if(i-1>=0 && i-1<N  && j>=0 && j<N)
		if(X[i-1][j] == ch)
			return false;
	if(i>=0 && i<N  && j-1>=0 && j-1<N)
		if(X[i][j-1] == ch)
			return false;
	if(i+1>=0 && i+1<N  && j>=0 && j<N)
		if(X[i+1][j] == ch)
			return false;
	if(i>=0 && i<N  && j+1>=0 && j+1<N)
		if(X[i][j+1] == ch)
			return false;
	return true;
}
int main()
{
	int T, i, j, count = 1;
	char ch;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		scanf("%c",&ch);
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				scanf("%c",&X[i][j]);
			}
			scanf("%c",&ch);
		}
		printf("Case %d:\n",count);
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(X[i][j] == '.')
				{
					for(ch='A'; ch<='Z'; ch++)
					{
						if(check(ch, i, j) == true)
						{
							X[i][j] = ch;
							printf("%c",X[i][j]);
							break;
						}
					}
				}
				else
				{
					printf("%c",X[i][j]);
					continue;
				}
			}
			printf("\n");
		}
		count++;		
	}
	return 0;
}
