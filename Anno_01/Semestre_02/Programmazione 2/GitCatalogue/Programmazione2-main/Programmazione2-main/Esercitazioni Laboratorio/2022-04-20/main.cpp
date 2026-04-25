#include <iostream>
#include <fstream>
using namespace std;

class Utente
{
private:
    int ID;
    string cognome;
    string nome;
    double popolarita;

    inline int compareTo(const Utente &other)
    {
        if (this->popolarita > other.popolarita)
            return 1;
        else if (this->popolarita < other.popolarita)
            return -1;
        else
            return 0;
    }

public:
    Utente(int ID, string cognome, string nome, double popolarita) : ID(ID), cognome(cognome), nome(nome), popolarita(popolarita){};

    Utente() : ID(0), cognome(""), nome(""), popolarita(0.0){};

    friend std::ostream &operator<<(std::ostream &output, const Utente &user)
    {
        output << "ID: " << user.ID << ", " << user.cognome << " " << user.nome << ", Popularity: " << user.popolarita;
        return output;
    }

    bool operator<(const Utente &other)
    {
        return this->compareTo(other) < 0;
    }

    bool operator>(const Utente &other)
    {
        return this->compareTo(other) > 0;
    }

    bool operator==(const Utente &other)
    {
        return this->compareTo(other) == 0;
    }
};

void swap(Utente &a, Utente &b)
{
    Utente temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Utente *vec[], int dim)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (vec[i] < vec[c])
            {
                swap(vec[c], vec[i]);
            }
        }
    }
}

void insertionSort(Utente *vec[], int dim)
{
    Utente *temp;
    int j = 0;

    for (int i = 0; i < dim; i++)
    {
        temp = vec[i];

        for (j = i; j > 0; j--)
        {
            if (temp < vec[j - 1])
            {
                vec[j] = vec[j - 1];
            }
            else
            {
                break;
            }
        }

        vec[j] = temp;
    }
}

int main()
{
    Utente *users[2000];
    ifstream file("utenti.txt");

    string ID, nome, cognome, popolarita;
    int ID_cast = 0, popolarita_cast = 0, i = 0;

    while (file.good())
    {
        getline(file, ID, ';');

        getline(file, cognome, ';');

        getline(file, nome, ';');

        getline(file, popolarita);

        ID_cast = stoi(ID);
        popolarita_cast = stod(popolarita);

        users[i] = new Utente(ID_cast, nome, cognome, popolarita_cast);
        i++;
    }

    bubbleSort(users, 2000);
    insertionSort(users, 2000);

    for (int i = 0; i < 2000; i++)
    {
        cout << *users[i] << endl;
    }

    file.close();
}