#include <stdio.h>

int killed[2000][2000];
int main()
{
	int testsN, ratsN, x, y, i, j, num, range, k, max, bestX, bestY;
	scanf("%d",&testsN);
	while(testsN --)
	{
		for(i=0; i<=1024; i++)
		{
			for(j=0; j<=1024; j++)
			{
				killed[i][j] = 0;
			}
		}
		scanf("%d",&range);
		scanf("%d",&ratsN);
		max = 0;
		for(k=0; k<ratsN; k++)
		{
			scanf("%d %d %d",&x,&y,&num);
			for(i=x-range; i<=x+range; i++)
			{
				for(j=y-range; j<=y+range; j++)
				{
					if(i >=0 && i <= 1024 && j >= 0 && j <= 1024)
					{
						killed[i][j] += num;
						if(killed[i][j] > max)
						{
							max = killed[i][j];
							bestX = i;
							bestY = j;
						}
						else if(killed[i][j] == max)
						{
							if(i < bestX)
							{
								bestX = i;
								bestY = j;
							}
							else if(i == bestX && j < bestY)
							{
								bestX = i;
								bestY = j;
							}
						}
					}
				}
			}
		}
		printf("%d %d %d\n", bestX, bestY, max);
	}
	return 0;
}
