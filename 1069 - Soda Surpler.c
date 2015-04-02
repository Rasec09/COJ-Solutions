#include <stdio.h>

int main()
{
    int TC, E, F, C, total, con;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d %d", &E, &F, &C);
        total = E + F;
        con = 0;
        if(C == 1)
            printf("0\n");
        else {
            while(total >= C){
                total = total - C + 1;
                con++;
            }
            printf("%d\n", con);
        }
    }
    return 0;
}
