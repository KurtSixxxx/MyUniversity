#include <iostream>
#include "static_stack.h"
#include "static_queue.h"
#include <ctime>
#include <cmath>
using namespace std;

class OperazioneAritmetica
{
protected:
    double opSinistro;
    double opDestro;
    char symbol;

public:
    OperazioneAritmetica(double opSinistro = 0.0, double opDestro = 0.0) : opSinistro(opSinistro), opDestro(opDestro){};

    virtual double eseguiCalcolo() = 0;

    void setOpSinistro(double op)
    {
        opSinistro = op;
    }

    void setOpDestro(double op)
    {
        opDestro = op;
    }

    friend std::ostream &operator<<(std::ostream &out, const OperazioneAritmetica &op)
    {
        out << op.opSinistro << " " << op.symbol << " " << op.opDestro;
        return out;
    }
};

class Addizione : public OperazioneAritmetica
{
public:
    Addizione() : OperazioneAritmetica() { symbol = '+'; };
    Addizione(double opSinistro, double opDestro) : OperazioneAritmetica(opSinistro, opDestro) { symbol = '+'; };

    double eseguiCalcolo()
    {
        return this->opSinistro + this->opDestro;
    }
};

class Sottrazione : public OperazioneAritmetica
{
public:
    Sottrazione() : OperazioneAritmetica() { symbol = '-'; };
    Sottrazione(double opSinistro, double opDestro) : OperazioneAritmetica(opSinistro, opDestro) { symbol = '-'; };

    double eseguiCalcolo()
    {
        return this->opSinistro - this->opDestro;
    }
};

class Prodotto : public OperazioneAritmetica
{
public:
    Prodotto() : OperazioneAritmetica() { symbol = '*'; };
    Prodotto(double opSinistro, double opDestro) : OperazioneAritmetica(opSinistro, opDestro) { symbol = '*'; };

    double eseguiCalcolo()
    {
        return this->opSinistro * this->opDestro;
    }
};

class Divisione : public OperazioneAritmetica
{
public:
    Divisione() : OperazioneAritmetica() { symbol = '/'; };
    Divisione(double opSinistro, double opDestro) : OperazioneAritmetica(opSinistro, opDestro) { symbol = '/'; };

    double eseguiCalcolo()
    {
        return this->opSinistro / this->opDestro;
    }
};

int main()
{
    srand(time(NULL));

    int n = 0, random = 0;

    cout << "Inserire un valore intero: ";
    cin >> n;

    StaticStack<OperazioneAritmetica *> stack(n);
    for (int i = 0; i < n; i++)
    {
        OperazioneAritmetica *operazione = nullptr;
        random = rand() % 4;

        switch (random)
        {
        case 0:
        {
            operazione = new Addizione();
            break;
        }
        case 1:
        {
            operazione = new Sottrazione();
            break;
        }
        case 2:
        {
            operazione = new Prodotto();
            break;
        }
        case 3:
        {
            operazione = new Divisione();
            break;
        }
        }

        stack.push(operazione);
    }

    // cout << stack;

    StaticQueue<double> queue(2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
        double r = ((double)std::rand() / RAND_MAX) * 100.0;
        queue.enqueue(r);
    }

    // cout << queue << endl;

    for (int i = 0; i < n; i++)
    {
        OperazioneAritmetica *op = stack.pop();
        double n1 = queue.dequeue();
        double n2 = queue.dequeue();
        op->setOpSinistro(n1);
        op->setOpDestro(n2);
        cout << *op << " = " << op->eseguiCalcolo() << std::endl;
    }
}