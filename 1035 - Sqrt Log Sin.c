#include <stdio.h>
#include <math.h>
#define mod 1000000

int x[1000005];

void calcula()
{
    int i;
    double d;

    x[0] = 1;
    for(i = 1; i <= 1000000; i++){
        d = i;
        x[i] = (x[(int)(d-sqrt(d))]%mod + x[(int)log(d)]%mod + x[(int)(d*sin(d)*sin(d))]%mod)%mod;
    }
}

int main()
{
    int n;

    calcula();
    while(1)
    {
        scanf("%d", &n);
        if(n == -1) break;
        printf("%d\n", x[n]);
    }
    return 0;
}
