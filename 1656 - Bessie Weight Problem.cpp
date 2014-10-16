#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 502

int H, N;
int balls[MAX];
int DP[MAX][45002];

int buttom_up()
{
	for(int i = 0; i <= H; i++)
		DP[0][i] = 0;
	
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= H; j++){
			if(balls[i - 1] <= j)
				DP[i][j] = max(DP[i - 1][j], balls[i - 1] + DP[i - 1][j - balls[i - 1]]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}		

	return DP[N][H];
}

int main()
{
	int ans;
	
	scanf("%d %d", &H, &N);	
	for(int i = 0; i < N; i++){
		scanf("%d", &balls[i]);
	}
	ans = buttom_up();
	printf("%d\n", ans);

	return 0;
}
