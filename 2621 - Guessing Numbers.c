#include <stdio.h>

int main()
{
    int n, cont;

    scanf("%d", &n);
    cont = 0;
    while(n > 0)
    {
        n /= 2;
        cont++;
    }
    printf("%d\n", cont);
    return 0;
}
