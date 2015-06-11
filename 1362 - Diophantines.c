#include <stdio.h>

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
    int a, b, c, mcd;

    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0) break;
        if(a >= b)
            mcd = gcd(a, b);
        else
            mcd = gcd(b, a);

        if(c % mcd == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
