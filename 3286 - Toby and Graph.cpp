#include <stdio.h>

struct DisjointSet
{
    int sets;
    int *padres;
    int *numVertices;

    void initSet(int n)
    {
        sets = n;
        padres = new int[n + 1];
        numVertices = new int[n + 1];
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

int main()
{
    int TC, n, m, a, b, ans;
    DisjointSet ds;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &n, &m);
        ds.initSet(n);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            ds.unionSet(a, b);
        }
        ans = (ds.sets * (ds.sets - 1))/2;
        printf("%d\n", ans);
    }
    return 0;
}
