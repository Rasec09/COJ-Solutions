#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

struct estado
{
	int x, y;
	int dist;
} ini;

typedef struct estado State;
char mapa[10][10];
bool visitado[10][10];
int n;

int Breadth_First_Search(State ini)
{
	queue <State> cola;

	memset(visitado, false, sizeof(visitado));
	cola.push(ini);
	while(!cola.empty())
	{
		State act = cola.front();
		cola.pop();

		if(mapa[act.x][act.y] == '#')
			return act.dist;
		if(!visitado[act.x][act.y+1] && mapa[act.x][act.y+1] != '*' && (act.y + 1) < n){
			State aux = act;			
			visitado[act.x][act.y+1] = true;
			aux.y += 1;
			aux.dist += 1;
			cola.push(aux);
		}
		if(!visitado[act.x][act.y-1] && mapa[act.x][act.y-1] != '*' && (act.y - 1) >= 0){
			State aux = act;
			visitado[act.x][act.y-1] = true;
			aux.y -= 1;
			aux.dist += 1;
			cola.push(aux);
		}
		if(!visitado[act.x+1][act.y] && mapa[act.x+1][act.y] != '*' && (act.x + 1) < n){
			State aux = act;
			visitado[act.x+1][act.y] = true;
			aux.x += 1;
			aux.dist += 1;
			cola.push(aux);
		}
		if(!visitado[act.x-1][act.y] && mapa[act.x - 1][act.y] != '*' && (act.x - 1) >= 0){
			State aux = act;
			visitado[act.x-1][act.y] = true;
			aux.x -= 1;
			aux.dist += 1;
			cola.push(aux);
		}
	}

	return -1;
}

int main()
{	
	int d = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mapa[i][j];
			if(mapa[i][j] == 'm'){
				ini.x = i;
				ini.y = j;
				ini.dist = 0;
			}			
		}
	}
	
	d = Breadth_First_Search(ini);
	printf("%d\n", d);
	
	return 0;
}
