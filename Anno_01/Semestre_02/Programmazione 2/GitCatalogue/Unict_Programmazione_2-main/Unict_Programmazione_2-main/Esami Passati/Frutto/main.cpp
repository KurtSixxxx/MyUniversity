#include <iostream>
#include "Frutto.h"
#include "Coda.h"

using namespace std;

int rimuoviFruttiPerTipo(Queue<Frutto*>& queue, const string& tipo, int count = 0)
{
    // Caso base
    if (queue.isEmpty())
    {
        return count;
    }

    Frutto* rimosso = queue.dequeue();

    if(rimosso->getTipo() == tipo)
    {
        delete rimosso;
        return rimuoviFruttiPerTipo(queue,tipo,count +1);
    }
    else
    {
        int reseult = rimuoviFruttiPerTipo(queue, tipo, count);
        queue.enqueue(rimosso);
        return reseult;

    }

}


int main()
{
    Frutto *m = new Mela("Granny Smith", "Verde", "Autunno", "sapore Aspro");
    Frutto *a = new Arancia("Tarocco", "Arancione", "Inverno", "sapore Dolce");

    Frutto *m1 = new Mela("Golden Delicious", "Giallo", "Autunno", "sapore Dolce");
    Frutto *a1 = new Arancia("Navel", "Arancione", "Inverno", "sapore Dolce-Acido");

    Frutto *m2 = new Mela("Fuji", "Rosso", "Autunno", "sapore Dolce");
    Frutto *a2 = new Arancia("Valencia", "Arancione", "Estate", "sapore Acido");

    Queue<Frutto*> queue;

    queue.enqueue(m);
    queue.enqueue(a);

    queue.enqueue(m1);
    queue.enqueue(a1);

    queue.enqueue(m2);
    queue.enqueue(a2);

    cout << endl;
    cout << "Coda iniziale:" << endl;
    cout << queue << endl;


    string tipoDaRimuovere;
    cout << "Inserisci il tipo di frutti da rimuovere (Mela/Arancia): ";
    cin >> tipoDaRimuovere;

    int count;

    if(tipoDaRimuovere == "Mela" || tipoDaRimuovere == "Arancia")
    {
        count = rimuoviFruttiPerTipo(queue, tipoDaRimuovere,0);
        cout << "Sono stati rimossi " << count << " frutti dalla coda." << endl << endl;
        cout << "Frutti rimanenti nella coda:" << endl;
        cout << queue << endl;

    }
    else
        cout << "Tipo non valido" << endl;

    return 0;

}

