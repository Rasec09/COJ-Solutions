#include <stdio.h>
#include <string.h>

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    char num[10];
    int sum, i, lon;

    while(1)
    {
        scanf("%s", num);
        if(num[0] == '0') break;
        sum = 0;
        lon = strlen(num);
        for(i = 0; i < lon; i++){
            sum += (num[i] - '0')*factorial(lon - i);
        }
        printf("%d\n", sum);
    }
    return 0;
}
