#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int V, E, Q;
vector <int> grafo[MAX];
bool visitado[MAX];
int distancia[MAX];

int BFS(int start, int end)
{
	int actual;
	queue <int> cola;	
	
	visitado[start] = true;
	distancia[start] = 1;
	cola.push(start);	

	while(!cola.empty())
	{
		actual = cola.front();
		cola.pop();	
		
		for(int i = 0; i < grafo[actual].size(); i++){
			int v = grafo[actual][i];
			if(!visitado[v]){
				visitado[v] = true;
				distancia[v] = distancia[actual] + 1;
				cola.push(v);
			}		
		}
	}
	
	return distancia[end];
}

int main()
{
	int T, u, v, q;

	scanf("%d", &T);
	while(T--)
	{	
		scanf("%d %d %d", &V, &E, &Q);
		while(E--){
			scanf("%d %d", &u, &v);
			grafo[u].push_back(v);
		}
		fill(visitado, visitado + MAX, false);
		fill(distancia, distancia + MAX, -1);
		BFS(1, V);
		while(Q--){
			scanf("%d", &q);			
			printf("%d\n", distancia[q]);
		}

		for(int i = 0; i < MAX; i++){
			grafo[i].clear();
		}
	}
	return 0;
}
