#include <stdio.h>

int copG[100001], copA[100001];

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}

int main()
{
	int G, A, R, gi, gj, ai, aj, rG, rA;
	int i, q, pG, pA;	

	scanf("%d %d", &G, &A);
	scanf("%d", &R);
	pG = 0;
	pA = 0;
	for(i = 1; i <= 100000; i++){
		copG[i] += copG[i-1];
		if(gcd(i, G) == 1)
			copG[i]++;
	}	
	for(i = 1; i <= 100000; i++){
		copA[i] += copA[i-1];
		if(gcd(i, A) == 1)
			copA[i]++;
	}
	while(R--)
	{
		scanf("%d %d %d %d", &gi, &gj, &ai, &aj);
		scanf("%d %d", &rA, &rG);
		q = copG[gj] - copG[gi - 1];
		if(q == rA)
			pA += 2;
		else
			pA -= 1;
		q = copA[aj] - copA[ai - 1];		
		if(q == rG)
			pG += 2;
		else
			pG -= 1;		
	}	
	if(pA > pG){
		printf("Anders wins\n");
	}	
	else if(pG > pA){
		printf("Garfield wins\n");
	}
	else {
		printf("Draw\n");
	}
			
	return 0;	
}
