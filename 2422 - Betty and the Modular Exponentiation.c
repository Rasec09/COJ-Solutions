#include <stdio.h>
#define MOD 1000000000

long long int binaryPow(long long x, int n)
{
	long long int next;

	if(n == 0)
		return 1;
	if(n == 1)
		return x;
	next = binaryPow(x, n/2);
	next = (next*next)%MOD;
	if(n % 2 == 0)
		return next;
	
	return (next*x)%MOD; 
}

int main()
{
	int T;
	long long int a, b, ans;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld %lld", &a, &b);
		if(a == MOD && b == 1)
			printf("0\n");
		else {
			ans = binaryPow(a, b);
			printf("%lld\n", ans);
		}
	}

	return 0;
}
