#include <stdio.h>

int main()
{
    int TC, N, ans, i;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &N);
        ans = N;
        for(i = 0; i < 3; i++){
            ans += 3;
            ans *= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
