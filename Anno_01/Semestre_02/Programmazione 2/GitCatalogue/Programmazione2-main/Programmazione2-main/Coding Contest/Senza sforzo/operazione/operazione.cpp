#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, op1_int = 0, op2_int = 0, ris = 0;
    string str = "", op1 = "", op2 = "";
    char segno = '\0';
    bool flag = false;

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

            flag = false;
            op1_int = 0;
            op2_int = 0;
            op1 = "";
            op2 = "";
            segno = '\0';
            ris = 0;

            for (int j = 0; j < str.length(); j++)
            {
                if (str[j] == '+' || str[j] == '-' || str[j] == '*')
                {
                    segno = str[j];
                    flag = true;
                }
                else
                {
                    if (!flag)
                    {
                        op1 += str[j];
                    }
                    else
                    {
                        op2 += str[j];
                    }
                }
            }

            op1_int = stoi(op1);
            op2_int = stoi(op2);

            switch (segno)
            {
            case '+':
            {
                ris = op1_int + op2_int;
                break;
            }

            case '-':
            {
                ris = op1_int - op2_int;
                break;
            }

            case '*':
            {
                ris = op1_int * op2_int;
                break;
            }
            }

            fileOutput << ris << " ";
        }

        fileOutput << endl;
    }
}
