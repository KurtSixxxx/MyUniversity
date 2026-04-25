//Esercizio 4.
//Reference vs Pointer: In C++ esiste il tipo "Reference" (int& ref = x;). Scrivi una funzione void raddoppia(int& n) che raddoppia il valore senza usare l'asterisco all'interno della funzione. Nota la differenza sintattica rispetto al puntatore.

//Esercizio 5.
//Test del nullptr: In C++ prova a scrivere int* p = nullptr;. Verifica cosa succede se provi a fare if (p == 0) e if (p == NULL).

//Esercizio 6.
//Allocazione Dinamica (New/Delete): In C usavi malloc e free. In C++ si usa new e delete. Alloca un singolo intero dinamicamente, assegnagli un valore e liberalo.

//Esercizio 7.
//Array Dinamici: Usa int* arr = new int[5]; per creare un array. Riempilo e poi liberalo usando la sintassi corretta delete[] arr; (nota le parentesi quadre!).

//------------------------------------------
#include <iostream>
using namespace std; //Lo uso solo per comodità. Ma per l'esame è più opportuno l'utilizzo di: 'std:: '

void raddoppia(int& n);

int main(){
//  ---Esercizio 4 inizio ---
    cout << "Esercizio 4:       ";
    int n = 2;
    cout << "Valore precedente: " << n << "\t"; 
    raddoppia(n);
    cout << "| Valore raddoppiato: " << n << "\n"; 
//  ---Esercizio 4 fine ---

//  ---Esercizio 5 inizio ---
    int *p = nullptr;
    cout << "Esercizio 5:       ";
    if(p == 0){
        cout << "(p == 0) Valore di p: " << p << "\t";
    }
    if(p == NULL){
        cout << "(p == NULL) Valore di p: " << p << "\n";
    }
    //? Perché nelle due righe di "cout" se inserisco *p (che serve per vedere il contenuto del puntatore) non stampa? Spiegazione nel blocco commento qui sotto
    /*
    Il mistero del nullptr 🚫
    Riflettiamo su cosa abbiamo detto prima: un puntatore è un indirizzo. nullptr (o 0) è l'indirizzo "nullo", ovvero un cartello che dice "qui non c'è niente".

    Quando scrivi *p, stai ordinando alla CPU: "Vai all'indirizzo contenuto in p e leggimi il valore". Ma se l'indirizzo è nullptr:

    La CPU prova ad andare all'indirizzo 0.

    Il sistema operativo interviene perché l'indirizzo 0 è protetto e non accessibile.

    Il programma va in crash (spesso con un errore di Segmentation Fault).

    Ecco perché non stampa nulla: il programma si interrompe bruscamente prima di arrivare al cout! In Programmazione 2 imparerai che dereferenziare un puntatore nullo è uno degli errori più gravi che si possano fare.
    */
//  ---Esercizio 5 fine ---

//  ---Esercizio 6 inizio ---
    cout << "Esercizio 6:       ";
    int *x = new int (23); //Occorre inseriere il valore tra parentesi
    cout << "Intero allocato: " << *x << "\t";
    delete x;
    cout << "Prova di stampa dopo 'delete': " << *x << "\n"; //Stampa un indirizzo casuale. Lo puoi notare eseguendo il programma diverse volte e leggendo la console.
    //delete non cancella i dati fisicamente, ma dice al sistema: "Questa zona di memoria è libera, puoi darla a qualcun altro"
    //Il puntatore x però contiene ancora il vecchio indirizzo! Questo si chiama Dangling Pointer (puntatore sospeso). È un'ottima pratica, dopo un delete, assegnare il puntatore a nullptr. In questo modo, se per sbaglio provi a usarlo, il programma crasha subito invece di darti valori casuali e imprevedibili 
    //! x = nullptr;
    //  ---Esercizio 6 fine ---

//  ---Esercizio 7 inizio ---
    cout << "Esercizio 7:       \n";
    int *arr = new int[5]; 

    for(int i = 0; i < 5; i++){ // Usa < e la variabile dimensione
        arr[i] = (i + 1) * 3; // Esempio per assegnare 3, 6, 9...
        cout << "Valore in posizione [" << i << "]: " << arr[i] << "\n";
    }
    delete []arr; //Quando vogliamo eliminare un array con 'delete' bisogna indicarlo con le parentesi quadre [] che precedono il nome []arr;
    cout << "Valore dell'array, dopo l'eliminazione: " << "\n";

    for(int i = 0; i < 5; i++){ // Usa < e la variabile dimensione
        cout << "Valore in posizione [" << i << "]: " << arr[i] << "\n";
    }
    cout << "Come vedi stampa valori casuali poiche' e' tutto sporcato da indirizzi di memoria 'liberati e riassegnati'\n";
//  ---Esercizio 7 fine ---

return 0;
}

void raddoppia(int& n){
    n *= 2;
}