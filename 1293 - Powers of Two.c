#include <stdio.h>

int main()
{
	
	const int tam = 100;
	int n, power[tam], i, j, k, m=0, aux=0;

	scanf("%d", &n);
	
	for(i=0; i<tam; i++){
		power[i] = 0;
	}
	power[tam-1] = 2;
	if(n == 0){
		printf("1");
	}
	else {	
		for(i=1; i<n; i++){
			for(j=tam-1; j>0; j--){
				power[j] *= 2;
				if(aux == 1){
					power[j] += aux;
					aux = 0;
				}
				if(power[j] >= 10){
					power[j] -= 10;
					aux = 1;
				}
			}
		}
	
		while(power[m] == 0)
			m++;	
	
		for(k=m; k<tam; k++)
			printf("%d", power[k]);
	}
	printf("\n");
	
	return 0;
}
