#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string str;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> str;

        if (str.length() % 2 != 0)
        {
            str = str.substr(0, str.length() - 1);
        }

        fileOutput << str << '\n';
    }
}
