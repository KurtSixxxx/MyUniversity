#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int numel = 0;
    double num = 0, somma = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        somma = 0;
        fileInput >> numel;

        for (int i = 0; i < numel; i++)
        {
            fileInput >> num;
            somma += num;
        }

        fileOutput << somma << '\n';
    }
}
