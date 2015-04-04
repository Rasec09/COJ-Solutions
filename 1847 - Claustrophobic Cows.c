#include <stdio.h>
#include <math.h>

struct Coord
{
    int x, y;
} vacas[2005];

double distancia(struct Coord a, struct Coord b)
{
    long long int d, e;
    double raiz;
    d = (b.x - a.x);
    d *= d;
    e = (b.y - a.y);
    e *= e;
    d += e;
    raiz = sqrt(d);
    return raiz;
}

int main()
{
    int n, i, j, a = 0, b = 0;
    long double min, dist;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d %d", &vacas[i].x, &vacas[i].y);
    min = 1 << 30;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(i != j){
                dist = distancia(vacas[i], vacas[j]);
                if(dist < min){
                    min = dist;
                    a = i;
                    b = j;
                }
            }
        }
    }
    if(a < b)
        printf("%d %d\n", a, b);
    else
        printf("%d %d\n", b, a);
    return 0;
}
