#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, x = 0, cont = 0, num = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> n;
        fileInput >> x;

        cont = 0;
        int maggiori[n]{0};

        for (int i = 0; i < n; i++)
        {
            fileInput >> num;

            if (num > x)
            {
                maggiori[cont++] = num;
            }
        }

        fileOutput << cont << " ";

        for (int i = 0; i < cont; i++)
        {
            fileOutput << maggiori[i] << " ";
        }

        fileOutput << '\n';
    }
}
