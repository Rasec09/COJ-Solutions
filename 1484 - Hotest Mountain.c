#include <stdio.h>

int main()
{
    int n, i, P;
    float max, mountain;

    scanf("%d", &n);
    max = 0;
    for(i = 1; i <= n; i++){
        scanf("%f", &mountain);
        if(mountain >= max){
            max = mountain;
            P = i;
        }
    }
    printf("%d\n", P);
    return 0;
}
