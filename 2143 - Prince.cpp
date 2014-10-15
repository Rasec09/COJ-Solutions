#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 255

struct item
{
	int peso;
	int valor;
};

struct item lista[MAX];
int N, M;
int memo[MAX][1002];

int dp(int ind, int w)
{
	if(w > M)
		return -1000000000;
	if(ind == N)
		return 0;
	if(memo[ind][w] != -1)
		return memo[ind][w];

	memo[ind][w] = max( dp(ind + 1, w), lista[ind].valor + dp(ind + 1, w + lista[ind].peso) );

	return memo[ind][w];
}

int main()
{
	int R, total = 0;

	scanf("%d", &R);
	while(R--)
	{		
		memset(memo, -1, sizeof(memo));
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; i++){
			scanf("%d %d", &lista[i].peso, &lista[i].valor);
		}

		total += dp(0, 0); 
	}

	printf("%d\n", total);
	return 0;
}
