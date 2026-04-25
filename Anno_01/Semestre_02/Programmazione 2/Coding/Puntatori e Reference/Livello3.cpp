#include <iostream>
using namespace std;

void allocaIntero(int*& p);

int main(){
    //  ---Esercizio 8 inizio ---
    cout << "Esercizio 8:       ";

    /* 
       DIFFERENZA TRA I DUE CASI:
       CASO 1 'const int* p': Puntatore a un intero costante. 
       Il valore della variabile puntata è bloccato, ma il puntatore può cambiare indirizzo.

       CASO 2 'int* const p': Puntatore costante. 
       L'indirizzo è bloccato (il puntatore è "incollato" alla variabile), ma puoi cambiare il valore.

       IL TRUCCO: Leggi da destra a sinistra rispetto all'asterisco '*'
       - const a SINISTRA del '*': blocca il VALORE (*p)
       - const a DESTRA del '*': blocca l'INDIRIZZO (p)
    */

    int x = 10;
    int y = 12;

    // --- TEST CASO 2: Puntatore Costante ---
    int* const p = &x; 

    cout << "[PRIMA] Valore puntato da p: " << *p << "\t|";

    // TEST VALORE: Funziona perché il valore NON è const
    *p = 20; 
    cout << "   [MODIFICA VALORE] Ora x vale: " << x << "\n";

    // TEST INDIRIZZO: Decommenta la riga sotto per vedere l'ERRORE (assignment of read-only variable 'p')
    // p = &y; 

    /* 
       --- TEST CASO 1 (Inverso): ---
       const int* p_val_const = &x;
       p_val_const = &y;       // OK: Posso cambiare indirizzo
       //*p_val_const = 30;   // ERRORE: Il valore è bloccato
    */
    
    //  ---Esercizio 8 fine ---

    //  ---Esercizio 9 inizio ---
    cout << "Esercizio 9:       \n";
    int* pointer = nullptr; // Creiamo il contenitore "reale"
    allocaIntero(pointer);        // Passiamo il contenitore (p diventerà il suo alias)

    if (pointer != nullptr) {
        cout << "Valore allocato: " << *pointer << endl;
        cout << "Indirizzo in memoria: " << pointer << endl;
    }

    delete pointer; // Pulizia finale
    //  ---Esercizio 9 fine ---


     //  ---Esercizio 10 inizio ---
    cout << "Esercizio 10:       \n";
    char str[] = "Papera";
    char *pointerStr = str;
    int count = 0;
    while(*pointerStr != '\0'){
        cout << *pointerStr << " ";
        pointerStr++;
        count++;
    }
    cout << "\nLunghezza totale stringa: " << count << "\n";
    //  ---Esercizio 10 fine ---

    return 0;
}

void allocaIntero(int*& p){
    p = new int (5); //Allochiamo valore 5
}
