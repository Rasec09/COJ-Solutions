#include <stdio.h>

int main()
{
    int n, k, sum, i;

    scanf("%d", &n);
    sum = 0;
    while(n--)
    {
        scanf("%d", &k);
        for(i = 0; i < 32; i++){
            if((k & (1 << i)) != 0)
                sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
