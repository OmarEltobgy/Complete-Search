#include <stdio.h>
int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
  				  , 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};
int maxSize = 43, NToReach, shot[3];
int combinationsCount, permutationsCount;

void generateCombinations(int shotN, int startNumberIndex, int sum)
{
	if(shotN == 3)
	{
		if(sum == NToReach)
		{
			combinationsCount++;
			if(shot[0] == shot[1] && shot[1] == shot[2])
			{
				permutationsCount += 1;
			}
			else if(shot[0] == shot[1] || shot[1] == shot[2] || shot[2] == shot[0])
			{
				permutationsCount += 3;
			}
			else
			{
				permutationsCount += 6;
			}
		}
		return;
	}
	for(int i=startNumberIndex; i<maxSize; i++)
	{
		shot[shotN] = numbers[i];
		generateCombinations(shotN+1, i, sum+numbers[i]);
	}
}
int main()
{
	scanf("%d",&NToReach);
	while(NToReach > 0)
	{
		combinationsCount = 0;
		permutationsCount = 0;
		generateCombinations(0, 0, 0);
		if(combinationsCount == 0)
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", NToReach);
		else
		{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", NToReach, combinationsCount);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", NToReach, permutationsCount);
		}
		printf("**********************************************************************\n");
		scanf("%d",&NToReach);
	}
	printf("END OF OUTPUT\n");
}
