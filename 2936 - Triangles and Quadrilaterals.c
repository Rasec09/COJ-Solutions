#include <stdio.h>

int main()
{
	int n, m;
	long long int a, b;
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		a = n*(n-1)/2;
		b = m*(m-1)/2;

		printf("Triangles: %lld\n", a*m + b*n);
		printf("Quadrilaterals: %lld\n", a*b);
		printf("\n");
	}	

	return 0;
}
