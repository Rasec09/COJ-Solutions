#include <stdio.h>
#include <string.h>

int main()
{
	char S[100000], T[100000];
	int tamS, tamT;
	int i, j;

	while(scanf("%s %s", S, T) != EOF)
	{
		tamS = strlen(S);
		tamT = strlen(T);

		j=0;
		for(i=0; i < tamT; i++){
			if(T[i] == S[j]){
				j++;
			}
		}
		if(j == tamS)
			printf("Yes\n");
		else
			printf("No\n");
	}


	return 0;
}
