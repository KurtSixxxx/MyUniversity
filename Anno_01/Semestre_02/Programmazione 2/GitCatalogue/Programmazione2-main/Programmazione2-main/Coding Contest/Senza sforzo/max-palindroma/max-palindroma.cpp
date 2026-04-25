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

    if (s == aux) // Stringa palindroma
    {
        return true;
    }

    return false;
}

int maxPalindroma(string s)
{
    int i = 0, f = s.length() - 1, max = s.length() - 1;
    while (i != f)
    {
        if (palindroma(s.substr(i, (f - i) + 1)))
        {
            return (f - i) + 1;
        }
        else
        {
            if (f == s.length() - 1)
            {
                max--;
                i = 0;
                f = max;
            }
            else
            {
                i++;
                f++;
            }
        }
    }

    return 1;
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
        fileInput >> str;

        n = maxPalindroma(str);

        fileOutput << n << endl;
    }
}