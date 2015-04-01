#include <stdio.h>

int set[] = {1, 1, 2, 2, 2, 8};
int found[6];

int main()
{
    int TC, i;

    scanf("%d", &TC);
    while(TC--)
    {
        for(i = 0; i < 6; i++)
            scanf("%d", &found[i]);

        for(i = 0; i < 6; i++){
            if(set[i] != found[i])
                printf("%d ", set[i] - found[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}
