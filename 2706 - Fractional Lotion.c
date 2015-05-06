#include <stdio.h>
#define MAXN 10000

int main()
{
    int n, x, result;
    while(scanf(" 1/%d", &n) != EOF)
    {
        result = 0;
        for(x = n+1; x <= 2*n; x++) {
            if((n*x)%(x-n) == 0)
                result++;
        }
        printf("%d\n", result);
    }
	  return 0;
}
