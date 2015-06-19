#include <stdio.h>

int sum(int n)
{
    return n * (n + 1) / 2;
}

int busqueda(int s)
{
    int ini = 0, fin = 50000, m;

    while(ini <= fin)
    {
        m = (ini + fin) / 2;
        if(sum(m) == s)
            return m + 1;
        else if(sum(m) < s)
            ini = m + 1;
        else
            fin = m - 1;
    }
    return ini;
}

int main()
{
    int s, n, pag;
    double aux;

    while(1)
    {
        scanf("%d", &s);
        if(s == 0) break;
        n = busqueda(s);
        pag = sum(n) - s;
        printf("%d %d\n", pag, n);
    }
    return 0;
}
