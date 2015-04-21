#include <stdio.h>
#include <math.h>

void binario(int n)
{
    if(n > 0){
        binario(n/2);
        printf("%d", n % 2);
    }
}

int main()
{
    int N, i, cont;

    while(1)
    {
        scanf("%d", &N);
        if(N == 0) break;
        cont = 0;
        for(i = 0; i <= (int)log2(N); i++){
            if((N & (1 << i)) != 0)
                cont++;
        }
        printf("The parity of ");
        binario(N);
        printf(" is %d (mod 2).\n", cont);
    }
    return 0;
}
