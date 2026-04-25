#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string str, ris = "";

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        getline(fileInput, str);
        ris = "";

        for (int i = 0; i < str.length(); i++)
        {
            ris += str[i];

            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            {
                ris += 'f';
                ris += str[i];
            }
        }

        fileOutput << ris << endl;
    }
}
