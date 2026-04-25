#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, value_int = 0;
    double value_double = 0.0;
    char value_char = '\0';
    bool value_bool = false;
    string type = "", value = "";

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> type >> n;

        if (type == "int")
        {
            Stack<int> int_stack;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "pop")
                {
                    int_stack.pop();
                }
                else
                {
                    value_int = stoi(value.substr(1, value.length()));
                    int_stack.push(value_int);
                }
            }

            int len = int_stack.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << int_stack.pop();
            }
        }

        if (type == "double")
        {
            Stack<double> double_stack;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "pop")
                {
                    double_stack.pop();
                }
                else
                {
                    value_double = stod(value.substr(1, value.length()));
                    double_stack.push(value_double);
                }
            }

            int len = double_stack.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << double_stack.pop();
            }
        }

        if (type == "bool")
        {
            Stack<bool> bool_stack;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "pop")
                {
                    bool_stack.pop();
                }
                else
                {
                    value = value[1];

                    if (value == "0")
                    {
                        value_bool = false;
                    }
                    if (value == "1")
                    {
                        value_bool = true;
                    }

                    bool_stack.push(value_bool);
                }
            }

            int len = bool_stack.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << bool_stack.pop();
            }
        }

        if (type == "char")
        {
            Stack<char> char_stack;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "pop")
                {
                    char_stack.pop();
                }
                else
                {
                    value_char = value[1];

                    char_stack.push(value_char);
                }
            }

            int len = char_stack.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << char_stack.pop();
            }
        }

        fileOutput << endl;
    }
}