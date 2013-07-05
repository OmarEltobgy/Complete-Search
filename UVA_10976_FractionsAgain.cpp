#include <stdio.h>

int main()
{
  int x, y, N, result[100000][2], count, i;
	double xDouble;
	while(scanf("%d",&N) != EOF)
	{
		y = N+1;
		count = 0;
		xDouble = (N*y) / (y-N);
		x = (int)xDouble;	
		while(x >= y)
		{
			if(xDouble == x)
			{
				result[count][0] = x;
				result[count][1] = y;
				count++;
			}
			y ++;
			xDouble = (double)(N*y) / (y-N);
			x = (int)xDouble;	
		}
		printf("%d\n", count);
		for(i=0; i<count; i++)
			printf("1/%d = 1/%d + 1/%d\n", N, result[i][0], result[i][1]);
	}
	return 0;
}
