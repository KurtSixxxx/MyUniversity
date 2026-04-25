#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0;
    string sub = "", str = "";

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n >> sub;

        for (int i = 0; i < n; i++)
        {
            fileInput >> str;

            if (str.find(sub) != string::npos)
            {
                fileOutput << str << " ";
            }
        }

        fileOutput << endl;
    }
}