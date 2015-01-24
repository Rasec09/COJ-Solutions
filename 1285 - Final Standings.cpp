#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct team
{
    int Id, M;
} var;

bool operator<(struct team a, struct team b)
{
    if(a.M > b.M)
        return true;
    return false;
}

int main()
{
    int N;
    vector <struct team> score;

    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &var.Id, &var.M);
        score.push_back(var);
    }
    stable_sort(score.begin(), score.end());
    for(int i = 0; i < score.size(); i++)
        printf("%d %d\n", score[i].Id, score[i].M);

    return 0;
}
