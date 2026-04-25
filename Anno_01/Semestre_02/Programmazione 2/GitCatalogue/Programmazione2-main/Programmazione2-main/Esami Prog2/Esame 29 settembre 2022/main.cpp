#include <iostream>
using namespace std;

#include "bst.h"

int main()
{
    BST<int> alberoIntero;
    BST<char> alberoChar;

    alberoIntero.insert(10);
    alberoIntero.insert(24);
    alberoIntero.insert(5);
    alberoIntero.insert(9);
    alberoIntero.insert(7);
    alberoIntero.insert(20);
    alberoIntero.insert(12);
    alberoIntero.insert(8);
    alberoIntero.insert(4);
    alberoIntero.insert(11);

    cout << "\n\n**** VISUALIZZAZIONE BST DI INTERI ****" << endl;

    alberoIntero.postorder();

    BSTNode<int> *aux = alberoIntero.successor(20);

    if (aux == NULL)
    {
        cout << "Non esiste un successore!";
    }
    else
    {
        cout << "Successore: " << aux->getKey() << endl;
    }

    cout << "Distanza successore 5: " << alberoIntero.distanza_successore(5) << endl;
    cout << "Distanza successore 8: " << alberoIntero.distanza_successore(8);

    alberoChar.insert('a');
    alberoChar.insert('d');
    alberoChar.insert('c');
    alberoChar.insert('e');
    alberoChar.insert('h');
    alberoChar.insert('b');

    cout << "\n\n**** VISUALIZZAZIONE BST DI CHAR ****" << endl;

    alberoChar.postorder();

    BSTNode<char> *aux2 = alberoChar.successor('c');

    if (aux == NULL)
    {
        cout << "Non esiste un successore!";
    }
    else
    {
        cout << "Successore: " << aux2->getKey() << endl;
    }

    cout << "Distanza successore a: " << alberoChar.distanza_successore('a') << endl;
    cout << "Distanza successore e: " << alberoChar.distanza_successore('e');
}