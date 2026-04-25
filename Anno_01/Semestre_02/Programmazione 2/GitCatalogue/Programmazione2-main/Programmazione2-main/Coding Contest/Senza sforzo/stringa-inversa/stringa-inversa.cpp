#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string inverti(string s, int dim)
{
    string aux = "";
    int cont = 0;

    for (int i = dim - 1; i >= 0; i--)
    {
        aux += s[i];
    }

    return aux;
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0;
    string nome1, nome2, nome3;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> n;
        fileInput >> nome1 >> nome2 >> nome3;

        nome1 = inverti(nome1, n);
        nome2 = inverti(nome2, n);
        nome3 = inverti(nome3, n);

        fileOutput << nome1 << " " << nome2 << " " << nome3 << endl;
    }
}
