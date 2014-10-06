#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#define MAX 10005

using namespace std;

vector <int> grafo[MAX];
int total;
bool visitado[MAX];

int dfs(int ini)
{
	int act, dom = 0;
	stack <int> pila;

	pila.push(ini);
	visitado[ini] = true;	

	while(!pila.empty())
	{
		act = pila.top();
		pila.pop();

		for(int v = 0; v < grafo[act].size(); v++){
			if(!visitado[grafo[act][v]]){
				visitado[grafo[act][v]] = true;		
				pila.push(grafo[act][v]);
				dom++;
			}
		}
	}

	return dom;
}

int main()
{
	int T, n, m, l, x, y, z;

	scanf("%d", &T);
	while(T--)
	{
		memset(visitado, false, sizeof(visitado));
		scanf("%d %d %d", &n, &m, &l);
		for(int i = 0; i < MAX; i++){
			grafo[i].clear();
		}

		while(m--){
			scanf("%d %d", &x, &y);
			grafo[x].push_back(y);
		}
		total = 0;		
		while(l--){			
			scanf("%d", &z);
			if(!visitado[z]) total++; 		
			total += dfs(z);
		}

		printf("%d\n", total);		
	}
	
	return 0;
}
