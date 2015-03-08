#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> Edge;
typedef pair<int, Edge> arista;
vector <arista> aristas;

bool operator < (const arista a, const arista b){
    if(a.first < b.first)
        return true;
    return false;
}

struct DisjointSet
{
    int sets;
    int padres[1002];
    int numVertices[1002];

    void initSet(int n)
    {
        sets = n;
        for(int i = 0; i <= n; i++){
            padres[i] = i;
            numVertices[i] = 1;
        }
    }

    int findSet(int x)
    {
        if(x == padres[x])
            return x;
        else
            return padres[x] = findSet(padres[x]);
    }

    int setSize(int x)
    {
        return numVertices[findSet(x)];
    }

    bool isSameSet(int x, int y)
    {
        if(findSet(x) == findSet(y))
            return true;
        else
            return false;
    }

    void unionSet(int x, int y)
    {
        int xRoot = findSet(x);
        int yRoot = findSet(y);

        if(!isSameSet(xRoot, yRoot)){
            numVertices[yRoot] += numVertices[xRoot];
            padres[xRoot] = yRoot;
            sets--;
        }
    }
};

void kruskal(int v)
{
    DisjointSet mst;
    int origen, destino, peso, total = 0, num = 0;

    mst.initSet(v);
    sort(aristas.begin(), aristas.end());
    reverse(aristas.begin(), aristas.end());
    for(int i = 0; i < aristas.size(); i++){
        peso = aristas[i].first;
        origen = aristas[i].second.first;
        destino = aristas[i].second.second;
        if(!mst.isSameSet(origen, destino)){
            total += peso;
            num++;
            mst.unionSet(origen, destino);
        }
    }
    if(v - 1 != num)
        printf("-1\n");
    else
        printf("%d\n", total);
}

int main()
{
    int V, E, u, v, peso;

    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &peso);
        aristas.push_back(arista(peso, Edge(u, v)));
    }
    kruskal(V);
    return 0;
}
