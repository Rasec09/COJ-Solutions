#include <stdio.h>

const long long int mod = 1000007;
long long int cub[1000005];
long long int sum[1000005];

void precalcula()
{
    long long int i;
    for(i = 1; i <= 1000000; i++){
        cub[i] = i*i*i;
        sum[i] = sum[i-1]%mod + cub[i]%mod;
        sum[i] %= mod;
    }
}

int bsearch(long long int n)
{
    int ini = 0, fin = 1000000, med;

    while(ini <= fin)
    {
        med = (ini + fin)/2;
        if(cub[med] == n){
            return med;
        }
        else if(cub[med] < n){
            ini = med + 1;
        }
        else {
            fin = med - 1;
        }
    }
    return med;
}

int main()
{
    int TC, l, r;
    long long int a, b;

    precalcula();
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%lld %lld", &a, &b);
        l = bsearch(a);
        r = bsearch(b);
        if(cub[l] >= a) l--;
        if(cub[r] > b) r--;
        printf("%lld", (sum[r] - sum[l] + mod)%mod);
        if(TC) printf("\n");
    }
    return 0;
}
