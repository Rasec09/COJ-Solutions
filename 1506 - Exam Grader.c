#include <stdio.h>

int main()
{
    int n, m, i;
    char res[105], exam[105];
    double score;

    scanf("%d", &n);
    scanf("%s", res);
    scanf("%d", &m);
    while(m--)
    {
        scanf("%s", exam);
        score = 0;
        for(i = 0; i < n; i++){
            if(exam[i] == res[i])
                score += 1;
            else if(exam[i] != '#')
                score -= 0.25;

        }
        printf("%0.2lf\n", score);
    }
    return 0;
}
