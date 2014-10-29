#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	string s;
	set <char> str;

	cin >> T;
	while(T--)
	{
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			str.insert(s[i]);
		}
		cout << str.size() << "\n";
		str.clear();
	}
	return 0;
}
