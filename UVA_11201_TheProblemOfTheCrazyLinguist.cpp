#include <stdio.h>
#include <string.h>
char oddLetters[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
      					  'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
char evenLetters[5] = {'a', 'e', 'i', 'o', 'u'}, word[10], nowWord[10];
int wordSize, countLetters[26];
double P[26] = {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
				     6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52};
double SBCsum, count, average, inputSBC;

void solve(int index, double SBC)
{
	if(index == wordSize)
	{
		/*for(int i=0; i<wordSize; i++)
		{
			printf("%c ", nowWord[i]);
		}
		printf("\n");
		for(int i=0; i<26; i++)
		{
			printf("%d ", countLetters[i]);
		}
		printf("\n");*/
		SBCsum += SBC;
		count ++;
		return;
	}
	if((index+1)%2 == 0)
	{
		for(int i=0; i<5; i++)
		{
			if(countLetters[evenLetters[i]-'a'] < 2)
			{
				countLetters[evenLetters[i]-'a'] ++;
				nowWord[index] = evenLetters[i];
				solve(index+1, SBC+(index+1)*P[evenLetters[i]-'a']);
				countLetters[evenLetters[i]-'a'] --;
			}
		}
	}
	else
	{
		for(int i=0; i<21; i++)
		{
			if(countLetters[oddLetters[i]-'a'] < 2)
			{
				countLetters[oddLetters[i]-'a'] ++;
				nowWord[index] = oddLetters[i];
				solve(index+1, SBC+(index+1)*P[oddLetters[i]-'a']);
				countLetters[oddLetters[i]-'a'] --;
			}
		}
	}
}

int main()
{
	int test, i;
	char temp;
	scanf("%d",&test);
	scanf("%c",&temp);
	for(i=0; i<26; i++)
		countLetters[i] = 0;
	while(test--)
	{
		scanf("%s",word);
		wordSize = strlen(word);
		inputSBC = 0;
		for(i=0; i<wordSize; i++)
			inputSBC += (i+1)*P[word[i]-'a'];
		SBCsum = 0;
		count = 0;
		nowWord[0] = word[0];
		countLetters[word[0]-'a'] ++;
		solve(1, 1*P[word[0]-'a']);
		countLetters[word[0]-'a'] --;
		average = SBCsum / count;
		if(inputSBC < average)
			printf("below\n");
		else
			printf("above or equal\n");
	}	
}
