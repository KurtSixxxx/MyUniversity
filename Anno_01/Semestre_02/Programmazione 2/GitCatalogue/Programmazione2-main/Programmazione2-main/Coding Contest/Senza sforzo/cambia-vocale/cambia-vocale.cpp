#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string a_str = "", e_str = "", i_str = "", o_str = "", u_str = "", str = "";
    stringstream ris;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> a_str >> e_str >> i_str >> o_str >> u_str;

        char a = '\0', e = '\0', t = '\0', o = '\0', u = '\0';

        cout << i_str[2];

        a = a_str[2];
        e = e_str[2];
        t = i_str[2];
        o = o_str[2];
        u = u_str[2];

        getline(fileInput, str);

        ris.str("");

        str = str.substr(1, str.length());

        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
            case 'a':
            {
                ris << a;
                break;
            }
            case 'e':
            {
                ris << e;
                break;
            }
            case 'i':
            {
                ris << t;
                break;
            }
            case 'o':
            {
                ris << o;
                break;
            }
            case 'u':
            {
                ris << u;
                break;
            }
            default:
            {
                ris << str[i];
                break;
            }
            }
        }

        fileOutput << ris.str() << endl;
    }
}
