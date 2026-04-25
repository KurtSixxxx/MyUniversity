#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string soloConsonanti(string str, int dim)
{
    string res = "";

    for (int i = 0; i < dim; i++)
    {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
        {
            res += str[i];
        }
    }

    return res;
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

        nome1 = soloConsonanti(nome1, n);
        nome2 = soloConsonanti(nome2, n);
        nome3 = soloConsonanti(nome3, n);

        fileOutput << nome1 << " " << nome2 << " " << nome3 << endl;
    }
}
