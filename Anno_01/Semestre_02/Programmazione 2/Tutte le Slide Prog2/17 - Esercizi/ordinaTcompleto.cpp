/*
Implementare la classe Rettangolo con il metodo operator>
ed usare il metodo 'ordina' per ordinare un array di rettangoli
in base all'area.
*/


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


class Rettangolo{
private:
    int b,h;
public:
    Rettangolo(int _b = 10,int _h =5): b(_b), h(_h){}
    int getB() const {return b;}
    int getH() const {return h;}
    void setB(int _b){b=_b;}
    void setH(int _h){h=_h;}
    bool operator>(const Rettangolo& r) const{
        return b*h > r.getB()*r.getH();
    }

    friend
    ostream& operator<<(ostream& out, const Rettangolo& r);

};

ostream& operator<<(ostream& out, const Rettangolo& r){
    out << r.getB() << "X" << r.getH();
    return out;
}

int main(){
    int int_arr[] = {11,5,30,5,20};
    int n = 5;
    ordina<int>(int_arr,n);
    cout << "Array ordinato:\t";
    for(int i=0;i<5;i++)
        cout << int_arr[i] << " ";
    cout << endl;

    Rettangolo arrR[] = {{2,3}, {10,20}, {4,5}, {2,8}, {2,4}};
    ordina<Rettangolo>(arrR,n);
    cout << "Array ordinato:\t";
    for(int i=0;i<5;i++)
        cout << arrR[i] << " ";
    cout << endl;


    return 0;
}






