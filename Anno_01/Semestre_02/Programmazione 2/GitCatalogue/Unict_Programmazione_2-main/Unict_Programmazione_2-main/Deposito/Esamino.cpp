#include <iostream>
#include <string>

using namespace std;

// Definizione della classe Node
template <typename T>
class Node
{
public:
    Node(T d): data(d), next(nullptr) {}
    T getData() const {return data;}
    Node<T>* getNext() const {return next;}
    void setNext(Node<T>* n) {next = n;}

private:
    Node<T>* next;
    T data;
};

// Definizione della classe Queue
template <typename T>
class Queue
{
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue() {
        while(!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void enqueue(T val) {
        Node<T>* node = new Node<T>(val);
        if(isEmpty()) {
            head = node;
            tail = node;
        } else {
            tail->setNext(node);
            tail = node;
        }
    }

    T dequeue() {
        if(isEmpty()) return T();
        
        Node<T>* curr = head;
        head = curr->getNext();
        T val = curr->getData();
        delete curr;
        
        if(isEmpty()) tail = nullptr;
        return val;
    }

    T front() const {
        if(isEmpty()) return T();
        return head->getData();
    }

    int size() const {
        int count = 0;
        Node<T>* curr = head;
        while(curr) {
            count++;
            curr = curr->getNext();
        }
        return count;
    }

    // Metodo per ottenere un elemento per indice
    T get(int index) const {
        if (isEmpty() || index < 0) return T();
        
        Node<T>* curr = head;
        for (int i = 0; i < index && curr != nullptr; i++) {
            curr = curr->getNext();
        }
        
        return curr ? curr->getData() : T();
    }

    // Metodo per creare una copia della coda (utile per iterazioni)
    Queue<T> copy() const {
        Queue<T> newQueue;
        Node<T>* curr = head;
        while(curr) {
            newQueue.enqueue(curr->getData());
            curr = curr->getNext();
        }
        return newQueue;
    }

private:
    Node<T>* head;
    Node<T>* tail;
};

// Classe base Item
class Item {
protected:
    string title;
    string publicationDate;
    int id;
    bool isBorrowed;

public:
    Item(string t, string pd, int i) : title(t), publicationDate(pd), id(i), isBorrowed(false) {}
    virtual ~Item() {}
    
    string getTitle() const { return title; }
    int getId() const { return id; }
    bool getIsBorrowed() const { return isBorrowed; }
    void setIsBorrowed(bool status) { isBorrowed = status; }
    
    virtual void print() const = 0;
    
    friend ostream& operator<<(ostream& os, const Item& item) {
        item.print();
        return os;
    }
};

// Classe Book derivata da Item
class Book : public Item {
private:
    string author;

public:
    Book(string t, string a, string pd, int i) : Item(t, pd, i), author(a) {}
    
    string getAuthor() const { return author; }
    
    void print() const override {
        cout << "Book - " << title << " - " << author << " - " << id;
    }
};

// Classe DVD derivata da Item
class DVD : public Item {
private:
    int duration; // in minuti

public:
    DVD(string t, int d, string pd, int i) : Item(t, pd, i), duration(d) {}
    
    int getDuration() const { return duration; }
    
    void print() const override {
        cout << "DVD - " << title << " - " << duration << " min - " << id;
    }
};

// Classe astratta Person
class Person {
protected:
    string name;
    string surname;
    Queue<Item*> borrowedItems;
    int maxItems;

public:
    Person(string n, string s, int max) : name(n), surname(s), maxItems(max) {}
    virtual ~Person() {}
    
    string getName() const { return name; }
    string getSurname() const { return surname; }
    int getBorrowedCount() const { return borrowedItems.size(); }
    int getMaxItems() const { return maxItems; }
    
    bool canBorrow() const {
        return borrowedItems.size() < maxItems;
    }
    
    void borrowItem(Item* item) {
        if (canBorrow() && item && !item->getIsBorrowed()) {
            borrowedItems.enqueue(item);
            item->setIsBorrowed(true);
        }
    }
    
    bool returnItem(int itemId) {
        Queue<Item*> temp;
        bool found = false;
        
        while (!borrowedItems.isEmpty()) {
            Item* current = borrowedItems.dequeue();
            
            if (current->getId() == itemId) {
                current->setIsBorrowed(false);
                found = true;
            } else {
                temp.enqueue(current);
            }
        }
        
        // Reinserire gli elementi non restituiti
        while (!temp.isEmpty()) {
            borrowedItems.enqueue(temp.dequeue());
        }
        
        return found;
    }
    
    virtual void printBorrowedItems() const {
        cout << "Prodotti in prestito a " << name << " " << surname << ":" << endl;
        
        if (borrowedItems.isEmpty()) {
            cout << "Nessun prodotto in prestito" << endl << endl;
            return;
        }
        
        // Creare una copia per iterare senza modificare la coda originale
        Queue<Item*> temp = borrowedItems.copy();
        while (!temp.isEmpty()) {
            temp.dequeue()->print();
            cout << endl;
        }
        cout << endl;
    }
};

// Classe Student derivata da Person
class Student : public Person {
public:
    Student(string n, string s) : Person(n, s, 5) {}

    void printBorrowedItems() const
    {
        cout << "Studente: " << endl;
        Person::printBorrowedItems();
    }
};

// Classe Professor derivata da Person
class Professor : public Person {
public:
    Professor(string n, string s) : Person(n, s, 10) {}

    void printBorrowedItems() const
    {
        cout << "Docente: " << endl;
        Person::printBorrowedItems();
    }
};

// Classe Library
class Library {
private:
    string name;
    Queue<Student*> students;
    Queue<Professor*> professors;
    Queue<Item*> items;

public:
    Library(string n) : name(n) {}
    
    void addStudent(Student* s) {
        students.enqueue(s);
    }
    
    void addProfessor(Professor* p) {
        professors.enqueue(p);
    }
    
    void addItem(Item* item) {
        items.enqueue(item);
    }
    
    bool borrowItem(int personType, int personIndex, int itemId) {
        Item* itemToBorrow = findItem(itemId);
        if (!itemToBorrow || itemToBorrow->getIsBorrowed()) {
            cout << "Prodotto non disponibile o gia' in prestito" << endl;
            return false;
        }
        
        if (personType == 0) { // Studente
            Student* student = findStudent(personIndex);
            if (student && student->canBorrow()) {
                student->borrowItem(itemToBorrow);
                cout << "Prestito effettuato con successo - Studente: " << student->getName() << endl;
                return true;
            }
        } else if (personType == 1) { // Professore
            Professor* professor = findProfessor(personIndex);
            if (professor && professor->canBorrow()) {
                professor->borrowItem(itemToBorrow);
                cout << "Prestito effettuato con successo - Docente: " << professor->getName() << endl;
                return true;
            }
        }
        
        cout << "Impossibile effettuare il prestito" << endl;
        return false;
    }
    
    bool returnItem(int personType, int personIndex, int itemId) {
        if (personType == 0) { // Studente
            Student* student = findStudent(personIndex);
            if (student) {
                bool success = student->returnItem(itemId);
                if (success) {
                    cout << "Restituzione effettuata con successo - Studente: " << student->getName() << endl;
                } else {
                    cout << "Prodotto non trovato tra quelli in prestito" << endl;
                }
                return success;
            }
        } else if (personType == 1) { // Professore
            Professor* professor = findProfessor(personIndex);
            if (professor) {
                bool success = professor->returnItem(itemId);
                if (success) {
                    cout << "Restituzione effettuata con successo - Docente: " << professor->getName() << endl;
                } else {
                    cout << "Prodotto non trovato tra quelli in prestito" << endl;
                }
                return success;
            }
        }
        
        cout << "Persona non trovata" << endl;
        return false;
    }
    
    void printAllBorrowedItems() const {
        cout << "=== SITUAZIONE PRESTITI ===" << endl;
        
        // Iterare attraverso gli studenti
        Queue<Student*> tempStudents = students.copy();
        while (!tempStudents.isEmpty()) {
            tempStudents.dequeue()->printBorrowedItems();
        }
        
        // Iterare attraverso i professori
        Queue<Professor*> tempProfessors = professors.copy();
        while (!tempProfessors.isEmpty()) {
            tempProfessors.dequeue()->printBorrowedItems();
        }
    }

private:
    Item* findItem(int id) {
        Queue<Item*> temp = items.copy();
        while (!temp.isEmpty()) {
            Item* current = temp.dequeue();
            if (current->getId() == id) {
                return current;
            }
        }
        return nullptr;
    }
    
    Student* findStudent(int index) {
        if (index < 0 || index >= students.size()) return nullptr;
        return students.get(index);
    }
    
    Professor* findProfessor(int index) {
        if (index < 0 || index >= professors.size()) return nullptr;
        return professors.get(index);
    }
};

// Funzione main
int main() {
    // Creazione della biblioteca
    Library biblioteca("Biblioteca Universitaria");
    
    // Creazione di studenti e docenti
    Student* studente1 = new Student("Mario", "Rossi");
    Student* studente2 = new Student("Luigi", "Verdi");
    Professor* professore1 = new Professor("Anna", "Bianchi");
    Professor* professore2 = new Professor("Marco", "Neri");
    
    biblioteca.addStudent(studente1);
    biblioteca.addStudent(studente2);
    biblioteca.addProfessor(professore1);
    biblioteca.addProfessor(professore2);
    
    // Creazione di libri e DVD
    Book* libro1 = new Book("Il nome della rosa", "Umberto Eco", "1980-01-01", 1);
    Book* libro2 = new Book("1984", "George Orwell", "1949-06-08", 2);
    Book* libro3 = new Book("Il Piccolo Principe", "Antoine de Saint-Exupery", "1943-04-06", 3);
    Book* libro4 = new Book("Divina Commedia", "Dante Alighieri", "1320-01-01", 4);
    Book* libro5 = new Book("I promessi sposi", "Alessandro Manzoni", "1827-01-01", 5);
    Book* libro6 = new Book("Orgoglio e pregiudizio", "Jane Austen", "1813-01-28", 6);
    
    DVD* dvd1 = new DVD("Inception", 148, "2010-07-16", 7);
    DVD* dvd2 = new DVD("The Shawshank Redemption", 142, "1994-09-23", 8);
    DVD* dvd3 = new DVD("Pulp Fiction", 154, "1994-05-21", 9);
    DVD* dvd4 = new DVD("The Godfather", 175, "1972-03-24", 10);
    
    biblioteca.addItem(libro1);
    biblioteca.addItem(libro2);
    biblioteca.addItem(libro3);
    biblioteca.addItem(libro4);
    biblioteca.addItem(libro5);
    biblioteca.addItem(libro6);
    biblioteca.addItem(dvd1);
    biblioteca.addItem(dvd2);
    biblioteca.addItem(dvd3);
    biblioteca.addItem(dvd4);
    
    cout << "=== TEST PRESTITI ===" << endl;
    
    // Prestiti agli studenti (indice 0 per il primo studente)
    biblioteca.borrowItem(0, 0, 1); // Studente 0 prende libro 1
    biblioteca.borrowItem(0, 0, 2); // Studente 0 prende libro 2
    biblioteca.borrowItem(0, 1, 3); // Studente 1 prende libro 3
    biblioteca.borrowItem(0, 1, 7); // Studente 1 prende DVD 7
    
    // Prestiti ai professori (indice 0 per il primo professore)
    biblioteca.borrowItem(1, 0, 4); // Professore 0 prende libro 4
    biblioteca.borrowItem(1, 0, 8); // Professore 0 prende DVD 8
    biblioteca.borrowItem(1, 1, 5); // Professore 1 prende libro 5
    biblioteca.borrowItem(1, 1, 9); // Professore 1 prende DVD 9
    
    cout << "\n=== TEST RESTITUZIONI ===" << endl;
    
    // Restituzioni
    biblioteca.returnItem(0, 0, 1); // Studente 0 restituisce libro 1
    biblioteca.returnItem(1, 0, 4); // Professore 0 restituisce libro 4
    
    cout << "\n=== TEST LIMITE PRESTITI ===" << endl;
    
    // Tentativo di superare il limite per lo studente
    biblioteca.borrowItem(0, 0, 3); // Studente 0 prende libro 3
    biblioteca.borrowItem(0, 0, 4); // Studente 0 prende libro 4
    biblioteca.borrowItem(0, 0, 5); // Studente 0 prende libro 5
    biblioteca.borrowItem(0, 0, 6); // Studente 0 prova a prendere libro 6 (supera limite)
    
    // Tentativo di superare il limite per il professore
    biblioteca.borrowItem(1, 0, 10); // Professore 0 prende DVD 10
    biblioteca.borrowItem(1, 0, 2);  // Professore 0 prende libro 2
    biblioteca.borrowItem(1, 0, 3);  // Professore 0 prende libro 3
    biblioteca.borrowItem(1, 0, 5);  // Professore 0 prende libro 5
    biblioteca.borrowItem(1, 0, 6);  // Professore 0 prende libro 6
    biblioteca.borrowItem(1, 0, 1);  // Professore 0 prende libro 1
    biblioteca.borrowItem(1, 0, 7);  // Professore 0 prova a prendere DVD 7 (supera limite)
    
    cout << "\n=== SITUAZIONE FINALE ===" << endl;
    biblioteca.printAllBorrowedItems();
    
    // Pulizia della memoria
    delete studente1;
    delete studente2;
    delete professore1;
    delete professore2;
    
    delete libro1;
    delete libro2;
    delete libro3;
    delete libro4;
    delete libro5;
    delete libro6;
    delete dvd1;
    delete dvd2;
    delete dvd3;
    delete dvd4;
    
    return 0;
}