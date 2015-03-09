#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#define INF 1000000000

typedef pair<int, int> ii;
typedef pair<int, ii> arista;
vector <arista> aristas, MST, aux;

bool operator < (const arista a, const arista b){
    if(a.first < b.first)
        return true;
    return false;
}

struct DisjointSet
{
    int sets;
    int *padres;
    int *numVertices;

    void initSet(int n)
    {
        sets = n;
        padres = new int[n];
        numVertices = new int[n];
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

int kruskal(int v, bool bandera)
{
    DisjointSet mst;
    int origen, destino, peso, total = 0;

    mst.initSet(v);
    sort(aristas.begin(), aristas.end());
    for(int i = 0; i < aristas.size(); i++){
        peso = aristas[i].first;
        origen = aristas[i].second.first;
        destino = aristas[i].second.second;
        if(!mst.isSameSet(origen, destino)){
            total += peso;
            if(bandera) MST.push_back(arista(peso, ii(origen, destino)));
            mst.unionSet(origen, destino);
        }
    }
    return total;
}

void copiar()
{
    aristas.clear();
    for(int i = 0; i < aux.size(); i++){
        aristas.push_back(arista(aux[i].first, ii(aux[i].second.first,aux[i].second.second)));
    }
}

bool compara(int i, int j)
{
    if(MST[i].first == aristas[j].first && aristas[j].second.first == MST[i].second.first && aristas[j].second.second == MST[i].second.second)
        return true;
    else
        return false;
}

int main()
{
    int TC, V, E, mst, a, b, w, menor;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; i++){
            scanf("%d %d %d", &a, &b, &w);
            aristas.push_back(arista(w, ii(a, b)));
            aux.push_back(arista(w, ii(a, b)));
        }
        mst = kruskal(V, true);
        menor = INF;
        for(int i = 0; i < MST.size(); i++){
            copiar();
            for(int j = 0; j < aux.size(); j++){
                if(compara(i, j)){
                    aristas[j].first = INF;
                    menor = min(menor, kruskal(V, false));
                    break;
                }
            }
        }
        printf("%d %d", mst, menor);
        if(TC) printf("\n");
        aristas.clear();
        aux.clear();
    }
    return 0;
}
