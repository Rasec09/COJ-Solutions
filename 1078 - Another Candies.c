#include <stdio.h>

int main()
{
    int TC, n, i, sum, dul;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        sum = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &dul);
            sum += dul;
        }
        if(sum%n == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
