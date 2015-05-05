#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
    long long int a, b;

    while(scanf("%lld %lld", &a, &b) != EOF)
    {
        if(gcd(a, b) == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
