#include <iostream>
#include "studente.h"
using namespace std;

int main()
{
    Studente s1;

    s1.print();

    Studente s2("Giulio", "Pedicone", 19, "giulio.pedicone@studium.unict.it", "1000031068");

    s2.print();

    Studente s3 = s2;

    s3.print();

    // Nota bene: s2 e s3 possiedono indirizzi in memoria differenti

    cout << "Studente s2: " << &s2 << endl
         << "Studente s3: " << &s3 << endl;
}
