#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100002

int array[MAX];
long long int *stree;

void build_tree(int nodo, int l, int r)
{
	if(l == r){
		stree[nodo] = array[l];
		return;
	}
	else{
		int m = (l + r)/2;
		build_tree(nodo*2, l, m);
		build_tree(nodo*2+1, m + 1, r);
		stree[nodo] = stree[nodo*2] + stree[nodo*2 + 1];	
	}
}

long long int query(int nodo, int l, int r, int a, int b)
{
	if(b < l || r < a)
		return 0;
	if(a <= l && r <= b)
		return stree[nodo];

	int m = (l + r)/2;
	long long int L = query(nodo*2, l, m, a, b);
	long long int R = query(nodo*2+1, m + 1, r, a, b);
	return L + R;
}


long long int updateValue(int nodo, int l, int r, int a, int value)
{
	if(a < l || r < a)
		return stree[nodo];
	if(a <= l && r <= a)
		return stree[nodo] = value;

	int m = (l + r)/2;
	long long int L = updateValue(nodo*2, l, m, a, value);
	long long int R = updateValue(nodo*2+1, m + 1, r, a, value);
		
	return stree[nodo] = L + R;	
}

void update(int n, int index, int value)
{
	array[index] = value;
	updateValue(1, 0, n - 1, index, value);
}

void init_tree(int N)
{
	int x = (int)(ceil(log2(N)));
	int max_size = (int)(2 * pow(2, x)) - 1;

	stree = (long long int *)malloc(sizeof(long long int)*max_size);
	build_tree(1, 0, N - 1);
}

int main()
{
	int T, n, q, a, b, i;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++){
			scanf("%d", &array[i]);
		}
		init_tree(n);
		while(q--){
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(1, 0, n - 1, a, b));
		}

		free(stree);
		memset(array, 0, sizeof(array));		
		if(T) printf("\n");
	}
	
	return 0;
}
