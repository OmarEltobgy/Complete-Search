#include <stdio.h>
#include <stdlib.h>
int places[8];
int row, column;
int NNN;
int horizontalCheck[20], verticalCheck[20], sumDiagonal[40], diffDiagonal[40];

void solve(int i, int j, int N)
{
	if(N < j)
		return;
	if(j == 8)
	{
		if(N == 8)
		{
			printf("%2d      ", (NNN+1));
			for(int k=0; k<8; k++)
			{
				if(k != 7)
					printf("%d ", (places[k]+1));
				else
					printf("%d\n", (places[k]+1));			
			}
			NNN++;
		}
		return;
	}
	if(i == 8)
	{
		solve(0, j+1, N);
		return;
	}
	if(horizontalCheck[i]==0 && verticalCheck[j]==0 && sumDiagonal[i+j]==0 && diffDiagonal[i-j+(8-1)]==0)
	{
		horizontalCheck[i] = 1;
		verticalCheck[j] = 1;
		sumDiagonal[i+j] = 1;
		diffDiagonal[i-j+(8-1)] = 1;
		places[j] = i;
		solve(0, j+1, N+1);
		horizontalCheck[i] = 0;
		verticalCheck[j] = 0;
		sumDiagonal[i+j] = 0;
		diffDiagonal[i-j+(8-1)] = 0;
		places[j] = -1;
		solve(i+1, j, N);	
	}
	else
	{
		solve(i+1, j, N);
	}
}

int main()
{
	int test, i, j;
	scanf("%d",&test);
	for(i=0; i<8; i++)
	{
		horizontalCheck[i] = 0;
		verticalCheck[i] = 0;
		sumDiagonal[i] = 0;
		diffDiagonal[i] = 0;
		places[i] = -1;
	}
	for(i=8; i<=2*(8-1); i++)
	{
		sumDiagonal[i] = 0;
		diffDiagonal[i] = 0;
	}
	while(test--)
	{
		scanf("%d %d",&row,&column);
		places[column-1] = row-1;
		horizontalCheck[row-1] = 1;
		verticalCheck[column-1] = 1;
		sumDiagonal[(row-1)+(column-1)] = 1;
		diffDiagonal[(row-1)-(column-1)+(8-1)] = 1;
		NNN = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      ");
		for(i=1; i<=8; i++)
		{
			if(i != 8)
				printf("%d ", i);
			else
				printf("%d\n", i);	
		}
		printf("\n");
		solve(0, 0, 1);
		if(test != 0)
			printf("\n");
		horizontalCheck[row-1] = 0;
		verticalCheck[column-1] = 0;
		sumDiagonal[row-1+column-1] = 0;
		diffDiagonal[(row-1)-(column-1)+(8-1)] = 0;
	}
	return 0;
}
