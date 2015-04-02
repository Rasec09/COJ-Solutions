#include <stdio.h>

const int mod = 100;
int S[1002];

int main()
{
    int TC, i, a, b;

    S[0] = 0;
    for(i = 1; i <= 1000; i++){
        S[i] = (i)*(i+1)*(i+2);
        S[i] = (S[i]%mod + S[i-1]%mod)%mod;
    }
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", (S[b] - S[a - 1] + mod)%mod);
    }
    return 0;
}
