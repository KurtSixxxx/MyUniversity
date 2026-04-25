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
        getline(fileInput, str);
        cout << str << endl;
        int alfabeto[25]{0};

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                alfabeto[str[i] - 97]++;
            }
        }

        int max = alfabeto[0];
        int posMax = 0;

        for (int i = 0; i < 25; i++)
        {
            if (alfabeto[i] >= max)
            {
                max = alfabeto[i];
                posMax = i;
            }
        }

        char c = posMax + 97;
        fileOutput << c << " " << max << endl;
    }
}