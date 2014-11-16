#include <stdio.h>

int main()
{
	int i, a[4], b[4], g, e;
	
	g = 0; 
	e = 0;
	for(i=0; i<4; i++){
		scanf("%d", &a[i]);
		g += a[i];	
	}	
	
	for(i=0; i<4; i++){
		scanf("%d", &b[i]);
		e += b[i];	
	}		
	
	if(e > g)
		printf("Emma\n");
	else if(g > e)
		printf("Gunnar\n");
	else
		printf("Tie\n");

	return 0;
}
