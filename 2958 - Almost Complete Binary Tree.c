#include <stdio.h>
#define mod 1000000007

long long int fact[3001];
long long int pot[35];

long long int power(long long int x, long long int n)
{
	long long int next;

	if(n == 0)		
		return 1;
	if(n == 1)
		return x;
	next = power(x, n/2);
	next = (next*next)%mod;
	if(n%2 == 0)
		return next;
	else
		return (x*next)%mod;
}

void init()
{
	int i;	

	fact[0] = 1;
	fact[1] = 1;

	for(i=2; i<=3000; i++){
		fact[i] = (i*fact[i-1])%mod;
		fact[i] %= mod;
	}

	for(i=0; i<32; i++){
		pot[i] = power(2, i);
	}
}

long long int inverso(long long int a, long long int p)
{
	long long int inv;

	inv = power(a, p-2);
	inv %= mod;

	return inv;
}

long long int combina(int n, int r)
{
	int i = 0;
	long long int comb = 1, aux;

	for(i=n; i>(n-r); i--){
		comb *= i;
		comb %= mod;
	}	
	
	aux = inverso(fact[r], mod);
	comb = (comb*aux)%mod;	
	
	return comb;
}

int main()
{
	int T, n, sum, i;
	long long int res;

	scanf("%d", &T);	
	
	init();
	while(T--)
	{
		sum = 0; res = 0;		
	
		scanf("%d", &n);
		
		for(i=0; sum <= n; i++){
			sum += pot[i];
		}
		sum -= pot[i-1];	

		if(sum == n)
			printf("0\n");
		else{
			res = combina(pot[i-1], n - sum);
			res -= 1;
			printf("%lld\n", res);
		}
	}

	return 0;	
}
