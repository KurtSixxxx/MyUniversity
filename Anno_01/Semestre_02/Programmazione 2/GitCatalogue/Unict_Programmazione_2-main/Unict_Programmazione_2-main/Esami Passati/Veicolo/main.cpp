#include <iostream>
#include "BST.h"
#include "Veicolo.h"

using namespace std;

int main()
{
    BST<Veicolo*> bst;
    Veicolo* a = new Auto(1,"Panda FIRE","Fiat",1986,769,3);
    Veicolo* a1 = new Auto(3,"Ferrari Testarossa","Ferrari",1984,4943,3);
    Veicolo* m = new Moto(4,"YZF-R3","Yamaha",2014,249,"Sportiva");
    Veicolo* a2 = new Auto(5,"Peugeot 208","Peugeot",2019,1199,5);
    Veicolo* m1 = new Moto(6,"Honda Africa Twin 650","Honda",1983,749,"Enduro");

    bst.Insert(a1);
    bst.Insert(a);
    bst.Insert(a2);
    bst.Insert(m);
    bst.Insert(m1);

    BST_Node <Veicolo*> *nodo_a1 = bst.search(a1);
    bst.remove(nodo_a1);

    BST_Node <Veicolo*> *nodo_a5 = bst.search(a2);
    bst.remove(nodo_a5);

    bst.print_Pre_order(cout);

    return 0;
}   