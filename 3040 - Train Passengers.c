#include <stdio.h>

int main()
{
	long long int C, n, left, enter, stay, tren;
	
	scanf("%lld %lld", &C, &n);
	tren = 0;
	while(n--)
	{
		scanf("%lld %lld %lld", &left, &enter, &stay);
		if(tren - left < 0){
			printf("impossible\n");
			return 0;
		}
		tren -= left;
		if(tren + enter > C){
			printf("impossible\n");
			return 0;
		}		
		tren += enter;
		if(stay != 0 && tren < C){
			stay -= (C - tren);			
			tren += stay;
		}
	}
	if(tren == 0 && stay == 0)
		printf("possible\n");
	else
		printf("impossible\n");	
	return 0;
}
