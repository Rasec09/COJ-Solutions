#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, figh[10005];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &figh[i]);
    sort(figh, figh + n);
    printf("%d", figh[n - 1]);
    for(int i = 0; i < n - 1; i++)
        printf(" %d", figh[i]);
    return 0;
}
