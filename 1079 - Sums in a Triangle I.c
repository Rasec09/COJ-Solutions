#include <stdio.h>
#include <string.h>

int n, Tri[100][100], memo[100][100];
int max(int a, int b){ return (a > b)? a : b; }

int sum(int i, int j)
{
    if(i == n)
        return 0;
    if(memo[i][j] != -1)
        return memo[i][j];

    memo[i][j] = max(sum(i+1, j) + Tri[i][j], sum(i+1, j+1) + Tri[i][j]);

    return memo[i][j];
}

int main()
{
    int TC, i, j, sol;

    scanf("%d", &TC);
    while(TC--)
    {
        memset(memo, -1, sizeof(memo));
        scanf("%d\n", &n);
        for(i = 0; i < n; i++)
            for(j = 0; j <= i; j++)
                scanf("%d", &Tri[i][j]);
        sol = sum(0, 0);
        printf("%d\n", sol);
    }
    return 0;
}
