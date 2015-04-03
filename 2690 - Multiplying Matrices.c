#include <stdio.h>
#define TAM 105

int N, M, R, C;
int A[TAM][TAM], B[TAM][TAM], S[TAM][TAM];

int main()
{
    int i, j, k;

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            scanf("%d", &A[i][j]);
    scanf("%d %d", &R, &C);
    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            scanf("%d", &B[i][j]);
    if(M != R)
        printf("The matrices can not be multiplied\n");
    else {
        for(i = 0; i < N; i++){
            for(j = 0; j < C; j++){
                for(k = 0; k < R; k++){
                    S[i][j] += A[i][k]*B[k][j];
                }
                printf("%d ", S[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
