#include <stdio.h>
#include <string.h>

int main()
{
	int T, sum, i;
	char num[100];
	
	scanf("%d", &T);
	while(T--)
	{
		sum = 0;
		scanf("%s", num);
		if(num[0] == '-'){
			i = 1;
		}
		else{
			i = 0;
		}
		int l = strlen(num);
		while(i<l){
			sum = sum + (num[i] - 48);
			i++;
		}
		printf("%d\n", sum);
		memset(num, '\0', sizeof(num));
	}

	return 0;
}
