#include <stdio.h>
#include <string.h>

int k;
char S[100002];

int max(int a, int b){ return (a > b)? a : b; }

int rango(char c)
{
	int ini = 0, fin = 0, aux = k, count = 0, sol = -1, tam;

	tam = strlen(S);
	//printf("tam: %d\n", tam);
	while(fin < tam)
	{
		if(S[fin] == c){
			count++;
			fin++;
		}
		else {
			if(aux > 0){
				count++;
				aux--;
				fin++;	
			}
			else {
				if(S[ini] == c){
					count--;
				}
				else{
					count--;
					aux++;
				}
				ini++;	
			}
		}
		sol = max(sol, count);
	}

	return sol;
}

int main()
{
	int TC;

	scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d %s", &k, S);
		printf("%d\n", max(rango('<'), rango('>')));
	}
	return 0;
}
