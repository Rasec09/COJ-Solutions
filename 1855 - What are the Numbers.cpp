#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int TC, n, num;
    set <int> myset;

    scanf("%d\n", &TC);
    while(TC--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            if(myset.find(num) != myset.end())
                printf("%d\n", num);
            else
                myset.insert(num);
        }
        if(n == myset.size())
            printf("Not found!\n");
        myset.clear();
    }
    return 0;
}
