#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int T, sum = 0;
    string cadena;
    stringstream stream;

    cin >> T;
    while(T--)
    {
        cin >> cadena;
        for(int i=0; i<cadena.size(); i++){
            sum += cadena[i] - '0';
        }

        while(sum >= 10){

            cadena = "";
            stream.str("");
            stream << sum;
            cadena = stream.str();

            int aux = 0;
            for(int i=0; i<cadena.size(); i++){
                aux += cadena[i] - '0';
            }

            sum = aux;
        }

        cout << sum << endl;
        sum = 0;
    }

    return 0;
}
