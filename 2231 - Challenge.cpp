#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, conA, conB;
    string A, B;

    cin >> n;
    conA = conB = 0;
    while(n--)
    {
        cin >> A >> B;
        if(A == "rock" && B == "scissors")
            conA++;
        else if(A == "rock" && B == "paper")
            conB++;
        else if(A == "scissors" && B == "paper")
            conA++;
        else if(A == "scissors" && B == "rock")
            conB++;
        else if(A == "paper" && B == "rock")
            conA++;
        else if(A == "paper" && B == "scissors")
            conB++;
    }
    if(conA > conB)
        cout << "A win\n";
    else if(conA == conB)
        cout << "tied\n";
    else
        cout << "B win\n";
    return 0;
}
