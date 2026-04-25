#include <iostream>
#include <fstream>
#include "BST.h"
#include "Animale.h"

using namespace std;


int main()
{
    fstream file("input.txt", ios::in);

    BST <Animale*> bst;
    Animale *a;
    Cane* c;
    Gatto* g;

    if(!file.is_open())
    {
        cerr << "Errore apeetura del file"<<endl;
        return -1;
    }

    string nome;
    string razza;
    int eta;
    string tipo;

    while(file >> nome >> razza >> eta >> tipo)
    {
    
        if(tipo=="Cane")
        {
            c = new Cane(nome,razza,eta);
            bst.insert(c);
        }
        else
        {
            g = new Gatto(nome,razza,eta);
            bst.insert(g);
        }
    }

    cout << "Elenco di tutti gli animali in ordine alfabetico" << endl;
    bst.printInorder(cout);

    
    cout << "Inserici il nome di un animale da cercare: ";
    cin >> nome;
    
    BST_Node<Animale*>* nodo = bst.search(nome);  //deferenziamo visto search ritorna un puntatore a nodo dell’albero (BST_Node<T>*), non direttamente un Animale*.
    if(nodo)
    {
        Animale* animale = nodo->getDato();
        animale->stampa(cout);
        cout << "Il verso di " << nome << " e':" << animale->verso() << endl;

    }
    else
    {
        cout << "Nessun animale con questo nome trovato nell'albero.";
    }

    file.close();
    return 0;


    

}