// Esercizio 13.8 - Un albero binario è un BST? (attenzione alla trappola dei nipoti)
#include <iostream>
#include <climits>
using namespace std;

struct Nodo { int val; Nodo* sx = nullptr; Nodo* dx = nullptr; Nodo(int v) : val(v) {} };

// SBAGLIATO: controlla solo i figli diretti
bool controlloIngenuo(Nodo* r) {
    if (!r) return true;
    if (r->sx && r->sx->val >= r->val) return false;
    if (r->dx && r->dx->val < r->val) return false;
    return controlloIngenuo(r->sx) && controlloIngenuo(r->dx);
}

// GIUSTO: ogni nodo deve stare in un intervallo [minimo, massimo) ereditato dagli antenati
bool eBST(Nodo* r, long minimo, long massimo) {
    if (!r) return true;
    if (r->val < minimo || r->val >= massimo) return false;
    return eBST(r->sx, minimo, r->val) && eBST(r->dx, r->val, massimo);
}

int main() {
    /* Albero:      10
                   /  \
                  5    20
                   \
                    12      <- 12 > 5 (va bene per suo padre), ma 12 > 10
                               ed e' nel sottoalbero SINISTRO di 10!        */
    Nodo* r = new Nodo(10);
    r->sx = new Nodo(5);
    r->dx = new Nodo(20);
    r->sx->dx = new Nodo(12);
    cout << "controllo ingenuo: " << (controlloIngenuo(r) ? "BST" : "non BST") << endl;
    cout << "controllo giusto:  " << (eBST(r, LONG_MIN, LONG_MAX) ? "BST" : "non BST") << endl;
    r->sx->dx->val = 7;                            // ora è corretto
    cout << "con 7 al posto di 12: " << (eBST(r, LONG_MIN, LONG_MAX) ? "BST" : "non BST") << endl;
    delete r->sx->dx; delete r->sx; delete r->dx; delete r;
    return 0;
}
