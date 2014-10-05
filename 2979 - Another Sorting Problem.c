#include <stdio.h>

int arr[100];

int main()
{
	int T, i, n, cont;
	
	scanf("%d", &T);
	while(T--)
	{
		cont = 0;
		scanf("%d", &n);
		for(i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
			if(arr[i] != i)
				cont++;
		}

		printf("%d\n", cont);
	}	

	return 0;
}
