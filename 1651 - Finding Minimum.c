#include <stdio.h>
#define MAXN 100005
#define LOGN 20

int A[MAXN];
int sparse[MAXN][LOGN];
int logs[MAXN];

void precalcula(int n)
{
    int i, j;

    for (i = 2; i <= n; i++)
      logs[i] = logs[i >> 1] + 1;

    for(i = 0; i < n; i++)
        sparse[i][0] = i;

    for(j = 1; (1 << j) <= n ; j++){
        for(i = 0; i + (1 << j) - 1 < n; i++){
            int x = sparse[i][j - 1];
            int y = sparse[i + (1 << (j - 1))][j - 1];
            sparse[i][j] = (A[x] <= A[y]) ? x : y;
        }
    }
}

int RMQ(int i, int j)
{
    int k = logs[j - i + 1];
    int x = sparse[i][k];
    int y = sparse[j - (1 << k) + 1][k];
    return A[x] <= A[y] ? x : y;
}

int main()
{
    int N, i, q, a, b;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &A[i]);
    precalcula(N);
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &a, &b);
        if(a <= b)
            printf("%d\n", A[RMQ(a - 1, b - 1)]);
        else
            printf("%d\n", A[RMQ(b - 1, a - 1)]);
    }
    return 0;
}
