#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    char c1, c2;
    int n1, n2, n3;
    string cognome1, cognome2, cognome3;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> c1 >> c2;
        fileInput >> n1 >> cognome1;
        fileInput >> n2 >> cognome2;
        fileInput >> n3 >> cognome3;

        if (cognome1[0] == c1 || cognome1[n1 - 1] == c1)
        {
            if (cognome1[0] != c2 && cognome1[n1 - 1] != c2)
            {
                fileOutput << cognome1 << " ";
            }
        }

        if (cognome2[0] == c1 || cognome2[n2 - 1] == c1)
        {
            if (cognome2[0] != c2 && cognome2[n2 - 1] != c2)
            {
                fileOutput << cognome2 << " ";
            }
        }

        if (cognome3[0] == c1 || cognome3[n3 - 1] == c1)
        {
            if (cognome3[0] != c2 && cognome3[n3 - 1] != c2)
            {
                fileOutput << cognome3 << " ";
            }
        }

        fileOutput << '\n';
    }
}
