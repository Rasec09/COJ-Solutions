#include <stdio.h>

int main()
{
    int TC, N, sum, i;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &N);
        sum = 0;
        for(i = 1; i < N; i++)
            if(N % i == 0)
                sum += i;
        if(sum < N)
            printf("Deficient\n");
        else if(sum == N)
            printf("Perfect\n");
        else
            printf("Abundant\n");
    }
    return 0;
}
