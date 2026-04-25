#include <iostream>
using namespace std;

int main()
{
    // Inizializzazione statica

    int array1[100];
    cout << "Dimensione dell'array1: " << sizeof(array1) << endl
         << endl; // 400 byte di memoria occupati 100*4 byte (intero occupa 4 byte)

    cout << "Array1: [ ";
    for (int c = 0; c < 100; c++)
    {
        array1[c] = c;
        cout << array1[c] << ", ";
    }

    cout << "]";

    cout << endl
         << endl;

    int array2[] = {1, 3, 5, 7};
    int n_array2 = sizeof(array2) / sizeof(int); // Restituisce il numero di elementi dell'array

    cout << "Dimensione dell'array2: " << sizeof(array2) << endl
         << endl; // 16 byte di memoria occupati 4*4 byte (intero occupa 4 byte)

    cout << "Numero di elementi dell'array2: " << n_array2 << endl;

    cout << "Array2: [ ";
    for (int c = 0; c < n_array2; c++)
    {
        array2[c] = c;
        cout << array2[c] << ", ";
    }

    cout << "]";

    cout << endl
         << endl;

    // Inizializzazione dinamica

    int *array3 = new int[100];

    cout << "Dimensione dell'array3 (parola di memoria): " << sizeof(array3) << endl
         << endl; // 8 byte perchè essendo array3 un puntatore, sizeof() ci restituisce la lunghezza della parola di memoria

    cout << "Dimensione di un singolo elemento dell'array3: " << sizeof(*array3) << endl
         << endl; // 4 byte perchè è un intero

    cout << "Dimensione dell'array3: " << sizeof(*array3) * 100 << endl
         << endl; // Dimensione di un singolo elemento * numero di elementi

    cout << "Array3: [ ";
    for (int c = 0; c < 100; c++)
    {
        array3[c] = c;
        cout << array3[c] << ", ";
    }

    cout << "]";

    delete array3; // Permette di sovrascrivere la memoria occupata dal primo elemento di array3

    delete[] array3; // éermette di sovrascrivere la meoria occupata da tutto l'array3

    // Deallocare evita il problema del memory leak in caso di programmi molto grandi
}