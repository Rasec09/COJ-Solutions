#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

long long int DP[MAXN];
long long int val[MAXN];

long long int f(long long int a)
{
	long long int raiz = (long long int)(sqrt(a));
	long long int ans = DP[raiz - 1];
	ans += (a - raiz * raiz + 1) * val[raiz];
	return ans;
}

int main()
{
	long long int bin = 1;
	int pot = 0;
	for(long long int i = 1; i < MAXN; i++){
		pot = -1;
		bin = i;
		while(bin){
			pot++;
			bin /= 2;
		}
		DP[i] = DP[i - 1] + (i * 2 + 1) * (1ll << pot);
		val[i] = 1ll << pot;
	}
	
	int T;
	cin >> T;
	while(T--)
	{
		long long int a, b;
		cin >> a >> b;
		cout << f(b) - f(a - 1) << endl;
	}
	return 0;
}
