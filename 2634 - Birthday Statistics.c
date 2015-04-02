#include <stdio.h>

int cubeta[13];

int main()
{
    int n, i, ID, dia, mes, year;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d/%d/%d", &ID, &dia, &mes, &year);
        cubeta[mes]++;
    }
    for(i = 1; i <= 12; i++){
        printf("%d %d\n", i, cubeta[i]);
    }
    return 0;
}
