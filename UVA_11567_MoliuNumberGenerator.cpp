#include <stdio.h>

long long test(long long N, long long count)
{
  if(N == 0)
		return count;
	else if(N == 1)
	{
		return (count+1);
	}
	else if(N%2 == 0)
	{
		return test(N/2, count+1);
	}
	else
	{
		long long count1 = test((N-1)/2, count+2);
		long long count2 = test((N+1)/2, count+2);
		if(count1 < count2)
			return count1;
		else
			return count2;
	}
	return count;
}
int main()
{
	long long N, count = 0;
	while(scanf("%lld",&N) != EOF)
	{
		count = test(N, 0);
		printf("%lld\n", count);
	}
}
