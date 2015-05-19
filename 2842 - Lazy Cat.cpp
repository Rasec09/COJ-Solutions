#include <bits/stdc++.h>
#define MAX 10000010
using namespace std;

long long int tam;
bitset <MAX> bs;
int primos[MAX];

void sieve(long long int upperbound)
{
    tam = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= tam; i++){
        if(bs[i]){
            for(long long int j = i*i; j <= tam; j += i)
                bs[j] = 0;
        }
    }
}

bool esPalindromo(int n)
{
    stringstream stream;
    string p1, p2;

    stream << n;
    p1 = stream.str();
    p2 = p1;
    reverse(p2.begin(), p2.end());
    if(p1 == p2)
        return true;
    else
        return false;
}

void precalcula()
{
    int acu;

    for(int i = 0; i <= MAX; i++){
        if(bs[i] && esPalindromo(i)){
            acu++;
        }
        primos[i] = acu;
    }
}

int main()
{
    int Q, i, j;

    sieve(MAX);
    precalcula();
    scanf("%d", &Q);
    while(Q--)
    {
        scanf("%d %d", &i, &j);
        printf("%d\n", primos[j] - primos[i - 1]);
    }
    return 0;
}
