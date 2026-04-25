

#include <iostream>
using namespace std;

template <typename T>
void ordina(T a[], int n){

    for(int i=1;i<n;i++){
        int pos = i;
        T key = a[i];
        while(pos>0 && a[pos-1]>key){
                a[pos] = a[pos-1];
                pos--;
        }
            a[pos] = key;
    }
}

/*
Implementare la classe Rettangolo con il metodo operator>
ed usare il metodo 'ordina' per ordinare un array di rettangoli
in base all'area.
*/
