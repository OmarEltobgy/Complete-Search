#include <stdio.h>
#include <stdlib.h>

int main()
{
  int positions[1000], relativesN, i, bestPosition, test, j, myPosition, sum, minSum;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&relativesN);
		for(i=0; i<relativesN; i++)
			scanf("%d",&positions[i]);
		minSum = 1<<30;
		for(i=0; i<relativesN; i++)
		{
			sum = 0;
			myPosition = positions[i];
			for(j=0; j<relativesN && sum<minSum; j++)
			{
				sum += abs(myPosition - positions[j]);
			}
			if(sum < minSum)
			{
				bestPosition = myPosition;
				minSum = sum;
			}
		}
		printf("%d\n", minSum);
	}
	return 0;
}
