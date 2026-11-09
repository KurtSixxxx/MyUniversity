// Esercizio 2.9 - IMPLEMENTAZIONE: i corpi delle funzioni
#include "geometria.h"       // virgolette: cerca prima nella cartella del progetto

namespace geometria {
    double areaCerchio(double r)              { return PI * r * r; }
    double areaRettangolo(double b, double h) { return b * h; }
    double perimetroCerchio(double r)         { return 2 * PI * r; }
}
