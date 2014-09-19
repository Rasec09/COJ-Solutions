#include <stdio.h>
#include <stdlib.h>

const long long int MOD = 1000007;

long long int **MatrixPower(long long int **fib, long long int **mat)
{
	int i, j, k;

	long long int **aux = (long long int **)malloc(sizeof(long long int*) * 2);
	for (i=0; i<2; i++) {
		aux[i] = (long long int *)malloc(sizeof(long long int) * 2);
	}
    	
   	aux[0][0]=0;
	aux[0][1]=0;
	aux[1][0]=0;
	aux[1][1]=0;
	
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			for(k=0; k<2; k++){
				aux[i][j] += (fib[i][k]%MOD)*(mat[k][j]%MOD);
				aux[i][j] = aux[i][j]%MOD;
			}
		}
	}
	
	return aux;
}

long long int **binaryPow(long long int **fib, long long int n)
{
	int i;	
	long long int **nextPow = (long long int **)malloc(sizeof(long long int*) * 2);
	
	for(i = 0; i < 2; i++)
		nextPow[i] = (long long int *)malloc(sizeof(long long int) * 4);

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
	int TC, i;
	long long int **fib, N;

	fib = (long long int **)malloc(2 * sizeof(long long int *));
	for(i = 0; i < 2; i++)
		fib[i] = (long long int *)malloc(2 * sizeof(long long int));
	
	scanf("%d", &TC);
	while(TC--)
	{		
		init(fib);
		scanf("%lld", &N);
		fib = binaryPow(fib, N+2);
		printf("%lld\n", fib[0][1]);		
	}	

	return 0;
}
