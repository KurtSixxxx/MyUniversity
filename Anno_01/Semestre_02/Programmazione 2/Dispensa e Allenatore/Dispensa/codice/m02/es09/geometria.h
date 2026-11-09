// Esercizio 2.9 - INTERFACCIA: solo dichiarazioni (prototipi e costanti)
#ifndef GEOMETRIA_H          // include guard: se GEOMETRIA_H non è ancora definito...
#define GEOMETRIA_H          // ...lo definisco e includo il contenuto. La seconda volta salto.

namespace geometria {
    const double PI = 3.14159265;
    double areaCerchio(double r);
    double areaRettangolo(double b, double h);
    double perimetroCerchio(double r);
}

#endif
