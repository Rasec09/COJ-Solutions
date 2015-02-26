#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int x[13], N, con;

bool isSafe(int col, int row)
{
    for(int ant = 1; ant <= col - 1; ant++)
        if(x[ant] == row || (abs(x[ant] - row) == abs(ant - col)))
            return false;
    return true;
}

void NQueens(int col)
{
    for(int row = 1; row <= N; row++){
        if(isSafe(col, row)){
            x[col] = row;
            if(col == N){
                printf("%d : ", ++con);
                for(int i = 1; i <= N; i++)
                    printf("%d ", x[i]);
                printf("\n");
            }
            else {
                NQueens(col + 1);
            }
        }
    }
}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        memset(x, 0, sizeof(x));
        con = 0;
        NQueens(1);
        if(con == 0)
            printf("No Solution.\n");
    }
    return 0;
}
