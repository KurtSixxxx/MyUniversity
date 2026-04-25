#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Utente
{
private:
    unsigned int ID;
    string nome;
    string cognome;
    double popularity;

public:
    Utente(unsigned int id, string n, string c, double p) : ID(id), nome(n), cognome(c), popularity(p){};
    Utente(){};

    friend istream &operator>>(istream &input, Utente &utente)
    {
        string id_str = "", pop_str = "";

        getline(input, id_str, ';');

        utente.ID = stoi(id_str); // stoi : string to int
        getline(input, utente.nome, ';');
        getline(input, utente.cognome, ';');
        getline(input, pop_str);
        utente.popularity = stod(pop_str); // stod : string to double

        return input;
    }

    void get()
    {
        cout << "ID: " << ID << endl;
        cout << "Nome: " << nome << endl;
        cout << "Cognome: " << cognome << endl;
        cout << "Popolarita: " << popularity << endl;
    }

    double getPopularity()
    {
        return popularity;
    }
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(Utente vec[], int p, int q)
{
    double pivot = vec[q].getPopularity(); // pivot
    int i = (p - 1);

    for (int j = p; j <= q - 1; j++)
    {
        if (vec[j].getPopularity() < pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[q]);

    return (i + 1);
}

void quickSort(Utente vec[], int p, int r)
{
    int q = 0;

    if (p < r)
    {
        q = partition(vec, p, r);
    }
    else
    {
        return;
    }

    quickSort(vec, p, q - 1);
    quickSort(vec, q + 1, r);
}

int main()
{
    Utente *utenti = new Utente[2000];

    int count = 0;
    ifstream file;
    file.open("utenti.txt");

    if (file.fail())
    {
        cerr << "Problem reading the file";
    }
    else
    {
        while (file.good())
        {
            Utente u;
            file >> u;
            utenti[count++] = u;
        }
    }

    file.close();

    for (int i = 0; i < 2000; i++)
    {
        utenti[i].get();
        cout << endl;
    }

    quickSort(utenti, 0, 1999);

    for (int i = 0; i < 2000; i++)
    {
        utenti[i].get();
        cout << endl;
    }
}
