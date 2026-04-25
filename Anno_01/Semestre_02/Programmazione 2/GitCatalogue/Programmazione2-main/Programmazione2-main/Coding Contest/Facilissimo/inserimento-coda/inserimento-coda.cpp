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
    string type = "";

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
                fileInput >> value_int;
                int_queue.enqueue(value_int);
            }

            for (int i = 0; i < n; i++)
            {
                fileOutput << int_queue.dequeue();
            }

            fileOutput << endl;
        }

        if (type == "double")
        {
            Queue<double> double_queue;

            for (double i = 0; i < n; i++)
            {
                fileInput >> value_double;
                double_queue.enqueue(value_double);
            }

            for (int i = 0; i < n; i++)
            {
                fileOutput << double_queue.dequeue();
            }

            fileOutput << endl;
        }

        if (type == "bool")
        {
            Queue<bool> bool_queue;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value_bool;
                bool_queue.enqueue(value_bool);
            }

            for (int i = 0; i < n; i++)
            {
                fileOutput << bool_queue.dequeue();
            }

            fileOutput << endl;
        }

        if (type == "char")
        {
            Queue<char> char_queue;

            for (int i = 0; i < n; i++)
            {
                fileInput >> value_char;
                char_queue.enqueue(value_char);
            }

            for (int i = 0; i < n; i++)
            {
                fileOutput << char_queue.dequeue();
            }

            fileOutput << endl;
        }
    }
}