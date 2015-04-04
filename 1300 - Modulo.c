#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int n;
    set <int> modulo;

    for(int i = 0; i < 10; i++){
        scanf("%d", &n);
        modulo.insert(n % 42);
    }
    printf("%d", modulo.size());
    return 0;
}
