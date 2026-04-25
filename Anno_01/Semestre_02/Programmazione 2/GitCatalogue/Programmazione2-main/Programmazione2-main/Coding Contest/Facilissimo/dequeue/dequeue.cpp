#include <iostream>
#include <fstream>
#include "queue.h"
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
            Queue<int> int_queue;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "dequeue")
                {
                    int_queue.dequeue();
                }
                else
                {
                    value_int = stoi(value.substr(1, value.length()));
                    int_queue.enqueue(value_int);
                }
            }

            int len = int_queue.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << int_queue.dequeue();
            }
        }

        if (type == "double")
        {
            Queue<double> double_queue;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "dequeue")
                {
                    double_queue.dequeue();
                }
                else
                {
                    value_double = stod(value.substr(1, value.length()));
                    double_queue.enqueue(value_double);
                }
            }

            int len = double_queue.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << double_queue.dequeue();
            }
        }

        if (type == "bool")
        {
            Queue<bool> bool_queue;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "dequeue")
                {
                    bool_queue.dequeue();
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

                    bool_queue.enqueue(value_bool);
                }
            }

            int len = bool_queue.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << bool_queue.dequeue();
            }
        }

        if (type == "char")
        {
            Queue<char> char_queue;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value;

                if (value == "dequeue")
                {
                    char_queue.dequeue();
                }
                else
                {
                    value_char = value[1];

                    char_queue.enqueue(value_char);
                }
            }

            int len = char_queue.getSize();

            for (int i = 0; i < len; i++)
            {
                fileOutput << char_queue.dequeue();
            }
        }

        fileOutput << endl;
    }
}