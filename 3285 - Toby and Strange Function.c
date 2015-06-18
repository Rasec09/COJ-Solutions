#include <stdio.h>
#include <string.h>

int main()
{
    int TC, l, i;
    long long int n, m;
    char S[105];

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%lld", &n);
        scanf("%s", S);
        l = strlen(S);
        n %= l;
        for(i = l - n; i < l; i++)
            printf("%c", S[i]);
        for(i = 0; i < l - n; i++)
            printf("%c", S[i]);
        printf("\n");
    }
    return 0;
}
