#include <iostream>
#include <fstream>

using namespace std;
bool palindroma(string s)
{
    string aux = "";
    int cont = 0;
    int j = s.length() - 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        aux += s[i];
    }

    if (s == aux) // Palindroma
    {
        return true;
    }

    for (int i = 0; i < s.length(); i++) // Quasi palindroma
    {
        if (s[i] == aux[i])
        {
            cont++;
        }
    }

    if (cont == s.length() - 2)
    {
        return true;
    }

    return false;
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0;
    string str;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n;

        for (int i = 0; i < n; i++)
        {
            fileInput >> str;
            if (palindroma(str))
            {
                fileOutput << str << " ";
            }
        }

        fileOutput << endl;
    }
}