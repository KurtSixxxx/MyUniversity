#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int cont = 0;
    string str;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        cont = 0;
        getline(fileInput, str);

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                cont++;
            }
        }

        fileOutput << cont + 1 << endl;
    }
}
