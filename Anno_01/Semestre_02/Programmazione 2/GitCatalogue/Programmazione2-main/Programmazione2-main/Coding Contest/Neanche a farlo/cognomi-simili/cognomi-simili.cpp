#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n;
    string cognome1, cognome2, cognome3;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n;
        fileInput >> cognome1 >> cognome2 >> cognome3;

        string subCognome1 = cognome1.substr(0, n);
        string subCognome2 = cognome2.substr(0, n);
        string subCognome3 = cognome3.substr(0, n);

        if (subCognome1 == subCognome2 && cognome1[n] != cognome2[n])
        {
            fileOutput << cognome1 << " " << cognome2;
            if (subCognome1 == subCognome3 && cognome1[n] != cognome3[n] && cognome2[n] != cognome3[n])
            {
                fileOutput << " " << cognome3;
            }
            fileOutput << "\n";
        }
        else if (subCognome1 == subCognome3 && cognome1[n] != cognome3[n])
        {
            fileOutput << cognome1 << " " << cognome3 << "\n";
        }
        else if (subCognome2 == subCognome3 && cognome2[n] != cognome3[n])
        {
            fileOutput << cognome2 << " " << cognome3;
            fileOutput << "\n";
        }
        else
        {
            fileOutput << cognome1 << "\n";
        }
    }
}
