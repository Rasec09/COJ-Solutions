#include <stdio.h>
#include <stdlib.h>

const long long int MOD = 1000000000;

long long int **MatrixPower(long long int **fib, long long int **mat)
{
	int i, j, k;
	long long int **res = (long long int **)malloc(sizeof(long long int *) * 2);

	for(i = 0; i < 2; i++)
		res[i] = (long long int *)malloc(sizeof(long long int) * 2);

	res[0][0] = 0;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 0;

	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			for(k=0; k<2; k++){
				res[i][j] += (fib[i][k]%MOD)*(mat[k][j]%MOD);
				res[i][j] = res[i][j]%MOD;
			}
		}
	}

	return res;
}

long long int **binaryPow(long long int **fib, long long int n)
{
	long long int **nextPow;

	if(n == 1)
		return fib;

	nextPow = binaryPow(fib, n/2);
	nextPow = MatrixPower(nextPow, nextPow);

	if(n % 2 == 0)
		return nextPow;
	else
		return MatrixPower(nextPow, fib);
}

void init(long long int **fib)
{
	fib[0][0] = 0;
	fib[0][1] = 1;
	fib[1][0] = 1;
	fib[1][1] = 1;
}

int main()
{
	int i;
	long long int **fib, N;

	fib = (long long int **)malloc(2 * sizeof(long long int *));
	for(i = 0; i < 2; i++)
		fib[i] = (long long int *)malloc(2 * sizeof(long long int));

    while(scanf("%lld", &N) != EOF)
    {
        init(fib);
        fib = binaryPow(fib, N);
        printf("%lld\n", fib[0][1]%10);
    }
	free(fib);
	return 0;
}
