// Esercizio 2.9 - USO: il main conosce solo l'interfaccia
// Compila TUTTI i .cpp insieme:  g++ main.cpp geometria.cpp -o es09.exe
#include <iostream>
#include "geometria.h"
#include "geometria.h"       // incluso due volte apposta: grazie alla guard non succede nulla
using namespace std;

int main() {
    cout << "Area cerchio r=1:     " << geometria::areaCerchio(1) << endl;
    cout << "Perimetro cerchio r=1: " << geometria::perimetroCerchio(1) << endl;
    cout << "Area rettangolo 3x4:  " << geometria::areaRettangolo(3, 4) << endl;
    return 0;
}
