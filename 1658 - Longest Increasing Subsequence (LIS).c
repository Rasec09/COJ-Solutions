#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int arr[1001];

int LIS(int n)
{
	int *best, i, j, max = INT_MIN;
	best = (int *) malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		best[i] = 1;

	for(i = 1; i < n; i++){
		for(j = 0; j < i; j++){
			if(arr[i] > arr[j] && best[i] < best[j] + 1){
				best[i] = best[j] + 1;
			}
		}		
	}

	for(i = 0; i < n; i++)
		if(max < best[i])
			max = best[i];

	free(best);

	return max;
}

int main()
{
	int T, n, i, res;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		res = LIS(n);
		printf("%d\n", res);
	}

	return 0;
}
