#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

int C[5]={0, 1, 3, 5, 6};
int memo[100001][5];

int cambio(int n, int m)
{
	if(n == 0)
		return 1;
	if(n < 0)
		return 1000000000;
	if(m <= 0 && n >= 1)
		return 1000000000;
	if(memo[n][m] != -1)
		return memo[n][m];

	memo[n][m] = min(cambio(n, m - 1), cambio(n - C[m], m) + 1);

	return memo[n][m];
}

int main()
{
	int TC, n, ans;

	memset(memo, (-1), sizeof(memo));
	scanf("%d", &TC);
	for(int i=1; i <= TC; i++){

		scanf("%d", &n);
		ans = cambio(n, 4) - 1;
		printf("Case %d: %d\n", i, ans);
	}
	return 0;
}
