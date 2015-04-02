#include <stdio.h>
#include <math.h>

int main()
{
    int TC;
    double L, sol;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%lf", &L);
        sol = L*L - (M_PI*pow(L/2, 2));
        printf("%0.2lf\n", sol);
    }
    return 0;
}
