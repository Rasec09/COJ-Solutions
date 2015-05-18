#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int myints[] = {1,2,3,4,5,6,7,8};
    int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    int N, TC, m, cont;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &N);
        m = f[N]/3;
        cont = 0;
        do {
            if(cont == m){
                for(int i = 0; i < N; i++)
                    printf("%d", myints[i]);
                printf("\n");
            }
            cont++;
        } while ( next_permutation(myints,myints+N) );
    }
    return 0;
}
