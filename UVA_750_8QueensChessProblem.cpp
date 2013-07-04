#include <stdio.h>
#include <stdlib.h>
int places[8];
int places2[10000][8];
int row, column;
int NNN;

void solve(int i, int j, int N)
{
  if(i == 8)
	{
		if(N == 8)
		{
			for(int k=0; k<8; k++)
			{
				places2[NNN][k] = places[k];
			}
			int swap = 1;
			for(int k=NNN-1; k>=0 && swap==1; k--)
			{
				swap = 0;
				for(int kk=0; kk<8; kk++)
				{
					if(places2[k+1][kk] < places2[k][kk])
					{
						swap = 1;
						break;
					}
					else if(places2[k+1][kk] > places2[k][kk])
					{
						swap = 0;
						break;
					}
				}
				if(swap == 1)
				{
					for(int kk=0; kk<8; kk++)
					{
						int temp = places2[k][kk];
						places2[k][kk] = places2[k+1][kk];
						places2[k+1][kk] = temp;
					}
				}
			}
			NNN++;
		}
		return;
	}
	if(j == 8)
	{
		solve(i+1, 0, N);
		return;
	}
	if(i == (row-1) && j == (column-1))
	{
		solve(i, j+1, N);
	}
	else
	{
		int canWe = 1;
		for(int k=0; k<8 && canWe==1; k++)
		{
			if(places[k] != -1)
			{
				if( j == k || places[k] == i)
					canWe = 0;
				if( places[k]+k==i+j || places[k]-k==i-j)
					canWe = 0;
			}
		}
		if(canWe == 1)
		{		
			places[j] = i;
			solve(i, j+1, N+1);
			places[j] = -1;
			solve(i, j+1, N);	
		}
		else
		{
			solve(i, j+1, N);
		}
	}		
}

int main()
{
	int test, i, j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&row,&column);
		for(i=0; i<8; i++)
		{
			places[i] = -1;
		}
		places[column-1] = row-1;
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
		for(int kkk=0; kkk<NNN; kkk++)
		{
			printf("%2d      ", (kkk+1));
			for(int k=0; k<8; k++)
			{
				if(k != 7)
					printf("%d ", (places2[kkk][k]+1));
				else
					printf("%d\n", (places2[kkk][k]+1));			
			}
		}
		if(test != 0)
			printf("\n");
	}
	return 0;
}
