#include <stdio.h>
#include <string.h>
#define mod 1000000000

int N;
int set[1002], memo[1002][1002];

int dp(int ind, int sum)
{
    if(ind == N && sum == 0)
        return 1;
    if(ind == N && sum != 0)
        return 0;
    if(memo[ind][sum] != -1)
        return memo[ind][sum];

    memo[ind][sum] = (dp(ind+1, (sum + set[ind])%3)%mod + dp(ind+1, sum%3)%mod)%mod;

    return memo[ind][sum]%mod;
}

int main()
{
    int i, res;

    while(scanf("%d", &N) != EOF)
    {
        memset(memo, -1, sizeof(memo));
        for(i = 0; i < N; i++)
            scanf("%d", &set[i]);

        res = dp(0, 0)%mod;
        res -= 1;
        printf("%d\n", res);
    }
    
    return 0;
}
