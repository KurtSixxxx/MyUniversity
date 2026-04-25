/*
Implementare una classe Array che simuli il comportamento di un array che conterrà 
solo interi.
*/

//....


#include <iostream>
#include <limits.h>
using namespace std;


class Array {
    int numeroElementi;
    int dimensioneMassima;
    int *array;

    public:
        Array(int _dimensioneMassima) : dimensioneMassima(_dimensioneMassima){
            numeroElementi = 0;
            array = new int [dimensioneMassima]; //Allochiamo una porzione di memoria di dimensioneMassima
        }
        void print(){
            cout << "[ ";
            for(int i=0; i<numeroElementi; i++) cout << array[i] << " ";
            cout << "]";
        }
       void inserisci(int n){
            if(numeroElementi == dimensioneMassima){ //Se il numero di elementi è uguale alla dimensioneMassima voglio che l'array diventi di dimensione il doppio 
                dimensioneMassima *= 2;
                int *tmp = new int[dimensioneMassima];
                for(int i=0; i<numeroElementi; i++){
                    tmp[i] = array[i];
                }
                int *toDelete = array;
                array = tmp;
                delete [] toDelete;
            }
            array[numeroElementi++] = n; //inserisco n nella prima posizione libera disponibile
        }
        void cancella(int i){
            if(i >= numeroElementi){ //Se ti chiedo di cancellare qualcosa in una posizione a cui non arriva l'array
                cout << endl << "--------------ERRORE NELLA CANCELLAZIONE----------------------" << endl;
                cout <<  "Non ci sono " << i+1 << " elementi nell'array" << endl;
                cout << "--------------------------------------------------------------" << endl << endl;
                return;
            }
            for(int j=i; j<numeroElementi-1; j++){
                array[j] = array[j+1]; 
            }
            numeroElementi--; //Ho tolto un elemento diminuisco il numero di elementi presenti nell'array
            if(numeroElementi <=dimensioneMassima/2){ 
                dimensioneMassima = dimensioneMassima/2;
                int *tmp = new int[dimensioneMassima];
                for(int j=0; j<numeroElementi; j++){
                    tmp[j] = array[j];
                }
                int *toDelete = array;
                array = tmp;
                delete [] toDelete;
            }
        }
        int getNumeroElementi(){
            return numeroElementi;
        }
        int getDimensioneMassima(){
            return dimensioneMassima;
        }
        void setDimensioneMassima(int _dimensioneMassima){
            dimensioneMassima = _dimensioneMassima;
        }

        //Restituisco un riferimento che sarà costante e che posso usare anche in un'operazione di assegnamento
        int& operator[] (int i) const{ //Operatore di estrazione
            if(i>=0 && i < numeroElementi){
                return array[i];
            }
            cout << endl << "--------------ERRORE NELL'ACCESSO----------------------" << endl;
            exit(0);
        }
};


int main(){
    int n = 3;
    Array array(n);
    cout << "Array iniziale--> "; 
    array.print();
    cout << " di dimensione massima " << array.getDimensioneMassima() << endl;

    for(int i=0; i<n; i++) array.inserisci(i);
    array.inserisci(10000);
    array.inserisci(10001);
    array.inserisci(10002);


    cout << "Array dopo inserimento--> ";
    array.print();
    cout << " di dimensione massima " << array.getDimensioneMassima() << endl;

    array.cancella(2);
    array.cancella(3);
    array.cancella(4);

    cout << "Array dopo cancellazione--> ";
    array.print();
    cout << " di dimensione massima " << array.getDimensioneMassima() << endl;


    cout << array[3] << endl;
    cout << array[300] << endl;
    array[3] = 1209; //Overloadare l'operatore significa poter fare anche una cosa di questa
    cout << array[3] << endl;
    int c = array[3];
    cout << c << endl;
    return 0;
}


