#include <stdio.h>

int main()
{
    int N, c, r;

    while(scanf("%d", &N) != EOF)
    {
        c = (N*(N + 1)*(2*N + 1))/6;
        r = (N*N*(N + 1)*(N + 1))/4;
        printf("%d %d\n", c, r);
    }
    return 0;
}
