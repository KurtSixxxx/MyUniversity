// Modulo 12 - Laboratorio a step: pile e code al lavoro
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template <typename T> struct Nodo { T valore; Nodo<T>* succ; };

// ===== STEP 1 =====  Pila generica su nodi
template <typename T>
class Pila {
    Nodo<T>* cima = nullptr;
public:
    ~Pila() { while (!vuota()) pop(); }
    void push(const T& x) { cima = new Nodo<T>{x, cima}; }
    T pop() {
        if (vuota()) throw underflow_error("pila vuota");
        Nodo<T>* v = cima; T x = v->valore; cima = cima->succ; delete v; return x;
    }
    bool vuota() const { return cima == nullptr; }
};

// ===== STEP 2 =====  Uso della pila: parentesi bilanciate
bool bilanciata(const string& s) {
    Pila<char> p;
    for (char c : s) {                                 // "per ogni carattere c di s"
        if (c == '(' || c == '[' || c == '{') p.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (p.vuota()) return false;               // chiusa senza aperta
            char a = p.pop();
            if ((c == ')' && a != '(') || (c == ']' && a != '[') || (c == '}' && a != '{')) return false;
        }
    }
    return p.vuota();                                   // aperte rimaste senza chiusura?
}

// ===== STEP 3 =====  Coda generica su nodi
template <typename T>
class Coda {
    Nodo<T>* testa = nullptr;
    Nodo<T>* fondo = nullptr;
    int n = 0;
public:
    ~Coda() { while (!vuota()) dequeue(); }
    void enqueue(const T& x) {
        Nodo<T>* nuovo = new Nodo<T>{x, nullptr};
        if (vuota()) testa = nuovo; else fondo->succ = nuovo;
        fondo = nuovo; n++;
    }
    T dequeue() {
        if (vuota()) throw underflow_error("coda vuota");
        Nodo<T>* v = testa; T x = v->valore; testa = testa->succ;
        if (!testa) fondo = nullptr;
        delete v; n--; return x;
    }
    bool vuota() const { return testa == nullptr; }
    int size() const { return n; }
};

// ===== STEP 4 =====  Simulazione di uno sportello (FIFO)
void sportello(int minuti) {
    Coda<int> fila;                                    // ogni cliente = minuto di arrivo
    int prossimoNumero = 1, serviti = 0, attesaTotale = 0, massimaFila = 0;
    int occupatoFinoA = 0;
    for (int t = 0; t < minuti; t++) {
        if (rand() % 100 < 60) { fila.enqueue(t); prossimoNumero++; }   // 60%: arriva qualcuno
        if (t >= occupatoFinoA && !fila.vuota()) {     // sportello libero: servo il primo
            int arrivo = fila.dequeue();
            attesaTotale += t - arrivo;
            serviti++;
            occupatoFinoA = t + 1 + rand() % 3;        // servizio di 1-3 minuti (in media 2)
        }
        if (fila.size() > massimaFila) massimaFila = fila.size();
    }
    cout << "  arrivati " << prossimoNumero - 1 << ", serviti " << serviti
         << ", ancora in fila " << fila.size() << ", fila massima " << massimaFila << endl;
    if (serviti) cout << "  attesa media " << (double)attesaTotale / serviti << " minuti" << endl;
}

// ===== STEP 5 =====  Coda su ARRAY CIRCOLARE a capacità fissa
template <typename T, int N>
class CodaCircolare {
    T dati[N];
    int inizio = 0, n = 0;                             // inizio = indice del primo
public:
    bool isEmpty() const { return n == 0; }
    bool isFull() const { return n == N; }
    void enqueue(const T& x) {
        if (isFull()) throw overflow_error("coda piena");
        dati[(inizio + n) % N] = x;                    // dopo l'ultima cella si riparte da 0
        n++;
    }
    T dequeue() {
        if (isEmpty()) throw underflow_error("coda vuota");
        T x = dati[inizio];
        inizio = (inizio + 1) % N;
        n--;
        return x;
    }
};

// ===== STEP 6 =====  Calcolatrice in notazione postfissa (polacca inversa)
double valutaPostfissa(const string& espr) {
    Pila<double> p;
    stringstream ss(espr);
    string tok;
    while (ss >> tok) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            double b = p.pop(), a = p.pop();           // ATTENZIONE: esce prima il secondo operando
            if (tok == "+") p.push(a + b);
            else if (tok == "-") p.push(a - b);
            else if (tok == "*") p.push(a * b);
            else p.push(a / b);
        } else {
            p.push(stod(tok));                         // stod: string -> double
        }
    }
    double r = p.pop();
    if (!p.vuota()) throw invalid_argument("espressione malformata");
    return r;
}

int main() {
    cout << "STEP 2:" << endl;
    string prove[] = {"{[(a+b)*c]-d}", "(a+b))", "([)]", "((a)"};
    for (int i = 0; i < 4; i++) cout << "  " << prove[i] << (bilanciata(prove[i]) ? "  bilanciata" : "  NON bilanciata") << endl;

    cout << "STEP 4: sportello per 60 minuti" << endl;
    srand(111222333);
    sportello(60);

    cout << "STEP 5: coda circolare da 3" << endl;
    CodaCircolare<int, 3> cc;
    cc.enqueue(1); cc.enqueue(2); cc.enqueue(3);
    try { cc.enqueue(4); } catch (const overflow_error& e) { cout << "  " << e.what() << endl; }
    cout << "  esce " << cc.dequeue();
    cc.enqueue(4);                                     // va nella cella 0, liberata
    cout << ", poi escono:";
    while (!cc.isEmpty()) cout << " " << cc.dequeue();
    cout << endl;

    cout << "STEP 6:" << endl;
    string espressioni[] = {"3 4 + 2 *", "5 1 2 + 4 * + 3 -", "10 2 8 * + 3 -"};
    for (int i = 0; i < 3; i++) cout << "  " << espressioni[i] << "  =  " << valutaPostfissa(espressioni[i]) << endl;
    return 0;
}
