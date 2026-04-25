#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n1, n2, n3;
    string cognome1, cognome2, cognome3;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n1 >> cognome1;
        fileInput >> n2 >> cognome2;
        fileInput >> n3 >> cognome3;

        cognome1[0] = cognome1[0] - 32;
        cognome2[0] = cognome2[0] - 32;
        cognome3[0] = cognome3[0] - 32;

        fileOutput << cognome1 << " " << cognome2 << " " << cognome3 << '\n';
    }
}
