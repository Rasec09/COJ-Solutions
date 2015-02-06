#include <stdio.h>
#include <string.h>

int max(int a, int b){ return (a > b)? a : b; }
int N, mat[201][101], memo[201][101];

int dp(int i, int j)
{
    if(i == (2*N - 1))
        return mat[0][0];
    if(memo[i][j] != -1)
        return memo[i][j];
    if(i < N - 1)
        memo[i][j] = max(dp(i + 1, j) + mat[i + 1][j], dp(i + 1, j + 1) + mat[i + 1][j + 1]);
    else if(i >= N - 1){
            if(j > 0)
                memo[i][j] = max(dp(i + 1, j - 1) + mat[i + 1][j - 1], dp(i + 1, j) + mat[i + 1][j]);
            else
                memo[i][j] = dp(i + 1, j) + mat[i + 1][j];
    }
    return memo[i][j];
}

int main()
{
    int TC, a, i, j, sol;

    scanf("%d", &TC);
    for(a = 1; a <= TC; a++)
    {
        scanf("%d", &N);
        for(i = 0; i < N; i++)
            for(j = 0; j <= i; j++)
                scanf("%d", &mat[i][j]);
        for(i = 0; i < N - 1; i++)
            for(j = 0; j < N - i - 1; j++)
                scanf("%d", &mat[N+i][j]);
        /*for(i = 0; i < 2*N - 1; i++){
            for(j = 0; j< N; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }*/
        memset(memo, -1, sizeof(memo));
        sol = dp(0, 0);
        printf("Case %d: %d\n", a, sol);
        memset(mat, 0, sizeof(mat));
    }
    return 0;
}
