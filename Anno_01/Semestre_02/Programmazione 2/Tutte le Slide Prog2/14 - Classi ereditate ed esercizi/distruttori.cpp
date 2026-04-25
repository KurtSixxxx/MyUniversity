

#include <iostream>
using namespace std;

class MyClass{
    // valore tipico per distinguere le singole istanze
    int value;
    // incrementa nel costruttore e decrementa nel distruttore
    static int num_obj;

public:
    MyClass();
    MyClass(int);

    //Distruttore:
    // * nessun valore di ritorno
    // * invocato al momento della distruzione dell'istanza
    ~MyClass();
    int getValue(){return value;}
    void setValue(int x){ value=x;}

    static int getNumObj(){return num_obj;}


    // Restituisce un puntatore alla copia creata
    MyClass * clone();

    void copyIn(MyClass *destination){
        destination->setValue(value);
    }

};

int MyClass::num_obj =0;
MyClass::~MyClass(){num_obj--;}
MyClass::MyClass(int x){value = x; num_obj++;};
// Costruttore con delega
MyClass::MyClass(): MyClass(-10){}


MyClass * MyClass::clone(){
    // Crea la copia nel HEAP (... ho usato new --> all. dinamica)
    MyClass *copia_p = new MyClass();
    copia_p->setValue(value);
    return copia_p;
}

int main(){

    MyClass obj1;
    obj1.setValue(20);
    MyClass obj2(10);

    cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;
    cout << "Obj1 value:\t" << obj1.getValue() << endl;
    cout << "Obj2 value:\t" << obj2.getValue() << endl;

    cout << endl;

    MyClass *cp_p_1 = obj1.clone();
    MyClass *cp_p_2 = obj2.clone();
    cout << "Copia Obj1 value:\t" << cp_p_1->getValue() << endl;
    cout << "Copia Obj2 value:\t" << cp_p_2->getValue() << endl;
    cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;

    cout << endl;

    // Creo un'oggetto che viene eliminato in automatico..
    {
        MyClass obj3; // memorizzato nello STACK
        cout << "Obj3 value:\t" << obj3.getValue() << endl;
        cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;
    }

    cout << endl;
    cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;

    cout << endl;

    delete cp_p_1;
    delete cp_p_2;


    cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;
    cout << endl;


    MyClass obj4;
    obj4.setValue(200);
    cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;
    cout << "Obj4 value:\t" << obj4.getValue() << endl;

    MyClass cp_4;
    obj4.copyIn(&cp_4);
    cout << "Copia Obj4 value:\t" << cp_4.getValue() << endl;
    cout << "Numero oggetti:\t" << MyClass::getNumObj() << endl;


    return 0;
}






