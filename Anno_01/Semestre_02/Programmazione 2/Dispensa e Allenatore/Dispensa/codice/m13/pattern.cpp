// Modulo 13 - Pattern: albero binario di ricerca (BST) generico, come nelle slide
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
    T val;
    Nodo<T>* left = nullptr;
    Nodo<T>* right = nullptr;
    Nodo<T>* padre = nullptr;            // serve a cancellazione e successore
    Nodo(T v) : val(v) {}
};

template <typename T>
class BST {
    Nodo<T>* root = nullptr;

    // --- funzioni ricorsive di supporto (lavorano su un sottoalbero) ---
    void preOrder(Nodo<T>* p) const  { if (p) { cout << p->val << " "; preOrder(p->left); preOrder(p->right); } }
    void inOrder(Nodo<T>* p) const   { if (p) { inOrder(p->left); cout << p->val << " "; inOrder(p->right); } }
    void postOrder(Nodo<T>* p) const { if (p) { postOrder(p->left); postOrder(p->right); cout << p->val << " "; } }
    int altezza(Nodo<T>* p) const {
        if (p == nullptr) return -1;     // albero vuoto: -1, così una foglia ha altezza 0
        int hs = altezza(p->left), hd = altezza(p->right);
        return 1 + (hs > hd ? hs : hd);
    }
    void distruggi(Nodo<T>* p) {         // post-order: prima i figli, poi il padre
        if (p) { distruggi(p->left); distruggi(p->right); delete p; }
    }
    Nodo<T>* minimo(Nodo<T>* x) const { while (x->left) x = x->left; return x; }

    // TRAPIANTA (slide): il sottoalbero di radice v prende il posto di quello di radice u
    void trapianta(Nodo<T>* u, Nodo<T>* v) {
        if (u->padre == nullptr) root = v;                 // u era la radice
        else if (u == u->padre->left) u->padre->left = v;
        else u->padre->right = v;
        if (v != nullptr) v->padre = u->padre;
    }

public:
    BST() {}
    ~BST() { distruggi(root); }
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    // INSERIMENTO (slide): scendo fino a una posizione vuota, ricordando il padre y
    void insert(T elemento) {
        Nodo<T>* x = root;
        Nodo<T>* y = nullptr;
        while (x != nullptr) {
            y = x;
            x = (elemento < x->val) ? x->left : x->right;   // minori a sinistra, >= a destra
        }
        Nodo<T>* nodo = new Nodo<T>(elemento);
        nodo->padre = y;
        if (y == nullptr) root = nodo;                     // albero vuoto
        else if (elemento < y->val) y->left = nodo;
        else y->right = nodo;
    }

    // RICERCA iterativa (slide): O(h)
    Nodo<T>* search(T elemento) const {
        Nodo<T>* x = root;
        while (x != nullptr && !(elemento == x->val))
            x = (elemento < x->val) ? x->left : x->right;
        return x;
    }

    // CANCELLAZIONE (slide): tre casi, tutto con trapianta
    bool remove(T elemento) {
        Nodo<T>* z = search(elemento);
        if (z == nullptr) return false;
        if (z->left == nullptr) trapianta(z, z->right);            // 0 figli o solo il destro
        else if (z->right == nullptr) trapianta(z, z->left);       // solo il sinistro
        else {                                                      // due figli
            Nodo<T>* y = minimo(z->right);                          // successore di z
            if (y->padre != z) {                                    // y è più in basso:
                trapianta(y, y->right);                             //   tolgo y dal suo posto
                y->right = z->right;                                //   e gli do il figlio destro di z
                y->right->padre = y;
            }
            trapianta(z, y);                                        // y prende il posto di z
            y->left = z->left;                                      // e il figlio sinistro di z
            y->left->padre = y;
        }
        delete z;
        return true;
    }

    T min() const { return minimo(root)->val; }
    T max() const { Nodo<T>* x = root; while (x->right) x = x->right; return x->val; }
    int altezza() const { return altezza(root); }
    void stampaVisite() const {
        cout << "  pre:  "; preOrder(root);  cout << endl;
        cout << "  in:   "; inOrder(root);   cout << endl;
        cout << "  post: "; postOrder(root); cout << endl;
    }
};

int main() {
    BST<int> t;
    int valori[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    for (int i = 0; i < 10; i++) t.insert(valori[i]);
    cout << "Visite:" << endl;
    t.stampaVisite();                  // l'in-order esce ORDINATO
    cout << "min " << t.min() << ", max " << t.max() << ", altezza " << t.altezza() << endl;
    cout << "cerco 45: " << (t.search(45) ? "trovato" : "assente")
         << ", cerco 99: " << (t.search(99) ? "trovato" : "assente") << endl;

    t.remove(20);  cout << "tolto 20 (foglia):" << endl; t.stampaVisite();
    t.remove(60);  cout << "tolto 60 (un figlio):" << endl; t.stampaVisite();
    t.remove(30);  cout << "tolto 30 (due figli):" << endl; t.stampaVisite();
    t.remove(50);  cout << "tolto 50 (la radice):" << endl; t.stampaVisite();
    return 0;
}
