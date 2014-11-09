#include <stdio.h>
#include <string.h>

int target[60];
long long int memo[60][2][60];

long long int dp(int pos, int menor, long long int sum)
{
	if(pos == -1)
		return sum;
	if(memo[pos][menor][sum] != -1)
		return memo[pos][menor][sum];
	long long int dev = 0;
	if(menor){
		dev += dp(pos - 1, menor, sum + 1) + dp(pos - 1, menor, sum);
	}
	else {
		if(target[pos] == 0)
			dev += dp(pos - 1, menor, sum);
		else
			dev += dp(pos - 1, 1, sum) + dp(pos - 1, 0, sum + 1);
	}
	memo[pos][menor][sum] = dev;

	return dev;
}

long long int f(long long int x)
{
	int count = 0;
	
	while(x != 0){
		target[count] = x%2;
		x /= 2;
		count++;
	}
	memset(memo, -1, sizeof(memo));
	return dp(count - 1, 0, 0);
}

int main()
{
	int T;
	long long int a, b, result;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", f(b) - f(a - 1));
	}
	return 0;
}
