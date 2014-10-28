#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int N, tam;
	char key[35];
	set <string> L;
	string k;

	scanf("%d", &N);
	while(N--)
	{
		scanf("%s", key);
		tam = strlen(key);
		sort(key, key+tam);
		L.insert(key);
	}
	cout << L.size() << "\n";
	return 0;
}
