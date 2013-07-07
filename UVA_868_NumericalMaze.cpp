#include <stdio.h>
int maze[1000][1000], visited[1000][1000];
int height, width, first[2], last[2], found;

void escape(int i, int j, int nowNumber, int max)
{
  if(nowNumber == max+1)
	{
		escape(i, j, 1, max+1);
		return;
	}
	if(i == height-1)
	{
		found = 1;
		if(j < last[1])
		{
			last[0] = i;
			last[1] = j;
		}
		return;
	}
	if(maze[i][j] == nowNumber)
	{
		visited[i][j] = 1;
		if(i > 0)
		{
			if(visited[i-1][j] == 0)
			{
				if(maze[i-1][j]%max == (nowNumber+1)%max)
				{
					escape(i-1, j, nowNumber+1, max);
				}
			}
		}
		if(i < height-1)
		{
			if(visited[i+1][j] == 0)
			{
				if(maze[i+1][j]%max == (nowNumber+1)%max)
				{
					escape(i+1, j, nowNumber+1, max);
				}
			}
		}
		if(j > 0)
		{
			if(visited[i][j-1] == 0)
			{
				if(maze[i][j-1]%max == (nowNumber+1)%max)
				{
					escape(i, j-1, nowNumber+1, max);
				}
			}
		}
		if(j < width-1)
		{
			if(visited[i][j+1] == 0)
			{
				if(maze[i][j+1]%max == (nowNumber+1)%max)
				{
					escape(i, j+1, nowNumber+1, max);
				}
			}
		}
		visited[i][j] = 0;
	}
}

int main()
{
	int test, i, j;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&height,&width);
		for(i=0; i<height; i++)
		{
			for(j=0; j<width; j++)
			{
				scanf("%d",&maze[i][j]);
				visited[i][j] = 0;
			}
		}
		last[0] = 1000;
		last[1] = 1000;
		found = 0;
		first[0] = 0;
		for(j=0; j<width && found==0; j++)
		{
			first[1] = j;
			escape(0, j, 1, 1);
		}
		if(test != 0)
			printf("%d %d\n%d %d\n\n", first[0]+1, first[1]+1, last[0]+1, last[1]+1);
		else
			printf("%d %d\n%d %d\n", first[0]+1, first[1]+1, last[0]+1, last[1]+1);
	}
	return 0;
}
