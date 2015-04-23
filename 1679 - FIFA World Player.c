#include <stdio.h>
#include <math.h>
#include <string.h>

char nombre[100], best[100];
int  PA, PJ, G, A, TA, TR;

int main()
{
    int N;
    double max, factor;

    max = 0;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s %d %d %d %d %d %d", nombre, &PA, &PJ, &G, &A, &TA, &TR);
        factor = log10(PA) + PJ + 2*G + A - (TA + 2*TR);
        if(factor > max){
            strcpy(best, nombre);
            max = factor;
        }
    }
    printf("%s\n", best);
    return 0;
}
