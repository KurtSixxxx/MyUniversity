#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int pos = 0;
    char c = '\0';
    bool flag = false;
    string str;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> c;

        getline(fileInput, str);

        pos = 0;
        flag = false;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                pos = 0;
            }
            else
            {
                if (str[i] == c)
                {
                    fileOutput << pos << " ";
                    flag = true;
                }

                pos++;
            }
        }

        if (!flag)
        {
            fileOutput << "none";
        }

        fileOutput << endl;
    }
}