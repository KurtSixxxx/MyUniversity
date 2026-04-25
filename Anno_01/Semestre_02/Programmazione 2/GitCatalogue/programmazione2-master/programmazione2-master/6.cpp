#include <iostream>
using namespace std;

/*
I membri della classe dichiarati friend, sono dei membri che 
vengono dichiarati nella classe A, ma il suo scope logico è fuori dall calsse.
Non avrei più la possibilità di accedere ai membri x e y, 
l'unico modo per farlo è passare al membro dichiarato
friend l'indirizzo di un'istanza della classe A
*/

class A {
    int x, y;

    public:
        A(int _x, int _y) : x(_x), y(_y) {}
        friend void print(A a){ 
            cout << "x = " << a.x << ", y = " << a.y << endl;
        }
};

class B {
    string s;
    int a, b;

    public:
        B(string _s, int _a, int _b) : s(_s), a(_a), b(_b) {}
        void print(){
            cout << "s = " << s << ", a = " << a << ", b = " << b << endl;
        }
        friend int sum(B b){
            return b.a + b.b;
        }
};


int main(){
    A a = {2, 5};
    print(a);

    B b = {"Ciao", 3, 4};
    b.print();
    cout << "a + b = " << sum(b) << endl;

    return 0;
}