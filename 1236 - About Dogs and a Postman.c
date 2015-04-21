#include <stdio.h>

int dog1, dog2;

void simula(int A, int B, int C, int D, int N)
{
    int i, X, Y;
    dog1 = dog2 = 1;
    X = A;
    Y = C;
    for(i = 1; i < N; i++){
        if(i % X == 0 && dog1 == 0){
            dog1 = 1;
            X += A;
        }
        if(i % X == 0 && dog1 == 1){
            dog1 = 0;
            X += B;
        }
        if(i % Y == 0 && dog2 == 0){
            dog2 = 1;
            Y += C;
        }
        if(i % Y == 0 && dog2 == 1){
            dog2 = 0;
            Y += D;
        }
    }
    if(dog1 == 1 && dog2 == 1)
        printf("both\n");
    else if((dog1 == 1 && dog2 == 0) || (dog1 == 0 && dog2 == 1))
        printf("one\n");
    else if(dog1 == 0 && dog2 == 0)
        printf("none\n");
}

int main()
{
    int A, B, C, D, P, G , M;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    scanf("%d %d %d",&P, &G, &M);
    simula(A, B, C, D, P);
    simula(A, B, C, D, G);
    simula(A, B, C, D, M);
    return 0;
}
