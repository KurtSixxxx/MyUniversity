# Lezione del 06 aprile 2022

### Object Oriented Programming (OOP):

* Principi base che regolano la OOP

1. Astrazione
2. Incapsulamento
3. Ereditarietà
4. Polimorfismo

### Astrazione

Significa generalizzare, ovvero
ottenere interfacce comuni a tutti gli oggetti di un determinato tipo.

### Incapsulamento (Information Hiding)

Significa utilizzare dei modificatori di accesso in base ai dati che vogliamo rendere visibili o meno.

I principali modificatori di accesso sono:
* Private (-)
* Public (+)
* Protected (*)

### Ereditarietà

Meccanismo che consente livelli di astrazione gerarchici che consente di derivare classi da altre classi in modo da conservare le proprietà della classe base nelle classi derivate.

### Polimorfismo

Funzioni che hanno lo stesso nome ma assumono comportamenti diversi a seconda del chiamante 

### Membri di una struttura dati

* Dati: Variabili di qualunque tipo (Attributi di una classe)
* Funzioni: Metodi di una classe

### Struct (Default: public)

Parola chiave che identifica una collezione di dati e funzioni all'interno di un programma C++.

Tutti i dati e le funzioni definite all'interno di una struct, sono SEMPRE accessibili pubblicamente.

### Classi (Default: private)

Forniscono la possibilità di modificare i livelli di accesso ai membri della classe stessa.

Ha sempre bisogno di un costruttore per essere istanziata.

### Oggetto di una classe e definzione di Costruttore

Rappresenta l'istanza di una classe all'interno del main del nostro programma C++ che avviene grazie ad un metodo particolare chiamato COSTRUTTORE con le seguenti caratteristiche:

* Stesso nome della classe
* Nessun tipo di ritorno (nemmeno void)
* Responsabile dell'inizializzazione dei valori degli attributi

### Principali tipi di costruttori

* Default: Costruttore senza parametri
* Completo: Costruttore che prende tutti i parametri da istanziare
* Copy Construct: Costruttore che copia bit a bit

```C++
class Persona
{
private:
    string nome;
    string cognome;
    int age;
    string email;

public:
    // Costruttore di default
    Persona(){};

    // Costruttore completo
    Persona(string n, string c, int e, string em) : nome(n), cognome(c), age(e), email(em){};

    // Costruttore copy construct
    Persona(const Persona &p)
    {
        nome = p.nome;
        cognome = p.cognome;
        age = p.age;
        email = p.email;
    }

    void print()
    {
        cout << "Mi chiamo " << nome << " " << cognome << ", ho " << age << " anni e la mia email è: " << email << endl;
    }
};
```

### Allocazione statica o dinamica

* Allocazione statica: dati allocati nello stack
* Allocazione dinamica: dati allocati nell'heap

Quando allochiamo dinamicamente è sempre necessario implementare un distruttore per evitare il memory leak.

```C++
 ~Persona() // ALT+126
    {
        delete[] temp;
    }
```

### Ereditarietà e modificatori di accesso

Class B : **public** A

* private A -> B non accessibile
* protected A -> B protected
* public A -> B public

Class B : **protected** A

* private A -> B non accessibile
* protected A -> B protected
* public A -> B protected

Class B : **private** A

* private A -> B non accessibile
* protected A -> B private
* public A -> B private