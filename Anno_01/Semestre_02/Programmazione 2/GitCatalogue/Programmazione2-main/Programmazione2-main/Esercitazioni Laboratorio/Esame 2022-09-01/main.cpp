#include <iostream>
#include <fstream>
#include "bst.h"
using namespace std;

int main()
{
    fstream file("input.txt");
    string type, size_string, value_string, conf1_string, conf2_string;
    int size, value_int, conf1_int, conf2_int;
    char value_char, conf1_char, conf2_char;

    if (file.is_open())
    {
        while (file.good())
        {
            file >> type;

            if (type == "int") // BST di interi
            {
                BST<int> BST_int;

                file >> size_string;

                size = stoi(size_string);

                for (int i = 0; i < size; i++)
                {
                    file >> value_string;

                    value_string = value_string.substr(4, value_string.length()); // cancello ins:

                    value_int = stoi(value_string);

                    BST_int.insert(value_int); // Inserisco nel BST i valori interi
                }

                // BST_int.preorder();

                file >> conf1_string;
                file >> conf2_string;

                conf1_int = stoi(conf1_string);
                conf2_int = stoi(conf2_string);

                cout << "Distanza chiavi: " << BST_int.distanzaChiavi(conf1_int, conf2_int) << endl;
            }
            else if (type == "char") // BST di char
            {
                BST<char> BST_char;

                file >> size_string;

                size = stoi(size_string);

                for (int i = 0; i < size; i++)
                {
                    file >> value_string;

                    value_string = value_string.substr(4, value_string.length()); // cancello ins:

                    value_char = value_string[0];

                    BST_char.insert(value_char); // Inserisco nel BST i valori char
                }

                // BST_char.preorder();

                file >> conf1_string;
                file >> conf2_string;

                conf1_char = conf1_string[0];
                conf2_char = conf2_string[0];
            }
        }

        file.close();
    }
}