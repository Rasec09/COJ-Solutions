#include <stdio.h>

int main()
{
    int N, x, y;

    scanf("%d", &N);
    while(N--)
    {
        scanf("%d %d", &x, &y);
        if(x == y){
            if(x % 2 == 0)
                printf("%d\n", 2*x);
            else
                printf("%d\n", 2*x - 1);
        }
        else if(x - 2 == y){
            if(x % 2 == 0)
                printf("%d\n", x + y);
            else
                printf("%d\n", x + y - 1);
        }
        else
            printf("No Number\n");
    }
    return 0;
}
