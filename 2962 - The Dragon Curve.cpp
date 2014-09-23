#include <iostream>
#include <string>

using namespace std;

string dragon[16];	

void calcula()
{
	dragon[0] = "";
	dragon[1] = "L";

	for(int i=2; i<=15; i++){
		dragon[i] = dragon[i-1];
		dragon[i].append("L");
		for(int j=dragon[i-1].size()-1; j>=0; j--){
			if(dragon[i-1][j] == 'L')
				dragon[i].append("R");
			else
				dragon[i].append("L");				 
		}
	}
}

int main()
{
	int n;	

	calcula();
	while(1)
	{
		cin >> n;
		if(n == -1)
			break;
		else
			cout << dragon[n] << endl;	
	}	
	return 0;
}
