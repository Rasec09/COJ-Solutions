#include <stdio.h>

int main()
{
    int L, R;

    while(1)
    {
        scanf("%d %d", &L, &R);
        if(L == 0 && R == 0) break;
        printf("%d\n", L + R);
    }
    return 0;
}
