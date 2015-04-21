#include <stdio.h>
#include <math.h>

int main()
{
    int TC, N, i;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &N);
        for(i = 0; i <= (int)log2(N); i++){
            if((N & (1 << i)) != 0)
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
