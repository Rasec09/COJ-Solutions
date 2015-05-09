#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cont, j, k;
    string word, line;

    cin >> word;
    cont = j = 0;
    while(!cin.eof())
    {
        getline(cin, line);
        for(int i = 0; i < line.size(); i++){
            if(line[i] != word[j] && j > 0){
                j = 0;
            }
            if(line[i] == word[j]){
                j++;
                if(j == word.size()){
                    cont++;
                    j = 0;
                }
            }
        }
        j = 0;
    }
    cout << cont << "\n";
    return 0;
}
