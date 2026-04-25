#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n1, n2, n3, cont = 0;
    string cognome1, cognome2, cognome3;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        cont = 0;
        fileInput >> n1 >> cognome1;
        fileInput >> n2 >> cognome2;
        fileInput >> n3 >> cognome3;

        if (cognome1[0] == cognome1[n1 - 1])
        {
            cont++;
        }

        if (cognome2[0] == cognome2[n2 - 1])
        {
            cont++;
        }

        if (cognome3[0] == cognome3[n3 - 1])
        {
            cont++;
        }

        fileOutput << cont << '\n';
    }
}
