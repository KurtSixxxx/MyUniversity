#include <iostream>
#include <string>

using namespace std;

// Classe base Item
class Item {
public:
    Item(string t, string pd, int i) : title(t), publicationDate(pd), id(i), isBorrowed(false) {}
    virtual ~Item() {}
    
    string getTitle() const { return title; }
    int getId() const { return id; }
    bool getIsBorrowed() const { return isBorrowed; }

    void setIsBorrowed(bool status) { isBorrowed = status; }
    
    virtual void print(ostream& os) const = 0;
    
    friend ostream& operator<<(ostream& os, const Item& item) {
        item.print(os);
        return os;
    }

protected:
    string title;
    string publicationDate;
    int id;
    bool isBorrowed;

};

// Classe Book derivata da Item
class Book : public Item {
private:
    string author;

public:
    Book(string t, string a, string pd, int i) : Item(t, pd, i), author(a) {}
    
    string getAuthor() const { return author; }
    
    void print(ostream& os) const override {
        os << "Book - " << title << " - " << author << " - " << id;
    }
};

// Classe DVD derivata da Item
class DVD : public Item {
private:
    double duration; // in minuti

public:
    DVD(string t, double d, string pd, int i) : Item(t, pd, i), duration(d) {}
    
    double getDuration() const { return duration; }
    
    void print(ostream& os) const override {
        os << "DVD - " << title << " - " << duration << " min - " << id;
    }
};

// Classe astratta Person
class Person {
public:
    Person(string n, string s, int max) : name(n), surname(s), maxItems(max), borrowedCount(0), capacity(10) {
        borrowedItems = new Item*[capacity];
    }
    
    virtual ~Person() {
        delete[] borrowedItems;
    }
    
    string getName() const { return name; }
    string getSurname() const { return surname; }
    int getBorrowedCount() const { return borrowedCount; }
    int getMaxItems() const { return maxItems; }
    
    bool canBorrow() const {
        return borrowedCount < maxItems;
    }
    
    void borrowItem(Item* item) {
        if (canBorrow() && item && !item->getIsBorrowed()) {
            if (borrowedCount >= capacity) {
                resizeArray();
            }
            borrowedItems[borrowedCount++] = item;
            item->setIsBorrowed(true);
        }
    }
    
    bool returnItem(int itemId) {
        for (int i = 0; i < borrowedCount; i++) {
            if (borrowedItems[i]->getId() == itemId) {
                borrowedItems[i]->setIsBorrowed(false);
                // Sposta tutti gli elementi successivi di una posizione
                for (int j = i; j < borrowedCount - 1; j++) {
                    borrowedItems[j] = borrowedItems[j + 1];
                }
                borrowedCount--;
                return true;
            }
        }
        return false;
    }
    
    virtual void printBorrowedItems(ostream& os) const {
        os << "Prodotti in prestito a " << name << " " << surname << ":" << endl;
        
        if (borrowedCount == 0) {
            os << "Nessun prodotto in prestito" << endl << endl;
            return;
        }
        
        for (int i = 0; i < borrowedCount; i++) {
            borrowedItems[i]->print(os);
            os << endl;
        }
        os << endl;
    }

protected:
    string name;
    string surname;
    Item** borrowedItems;
    int borrowedCount;
    int maxItems;
    int capacity;

    void resizeArray() {
        int newCapacity = capacity * 2;
        Item** newArray = new Item*[newCapacity];
        for (int i = 0; i < borrowedCount; i++) {
            newArray[i] = borrowedItems[i];
        }

        for (int i = borrowedCount; i < newCapacity; i++) {
        newArray[i] = nullptr;  // Inizializza i nuovi elementi
        }

        delete[] borrowedItems;
        borrowedItems = newArray;
        capacity = newCapacity;
    }
};

// Classe Student derivata da Person
class Student : public Person {
public:
    Student(string n, string s) : Person(n, s, 5) {}

    void printBorrowedItems(ostream& os) const
    {
        os << "Studente: " << endl;
        Person::printBorrowedItems(os);
    }
};

// Classe Professor derivata da Person
class Professor : public Person {
public:
    Professor(string n, string s) : Person(n, s, 10) {}

    void printBorrowedItems(ostream& os) const
    {
        os << "Docente: " << endl;
        Person::printBorrowedItems(os);
    }
};

// Classe Library
class Library {
public:
    Library(string n) : name(n), studentCount(0), professorCount(0), itemCount(0), 
                       studentCapacity(10), professorCapacity(10), itemCapacity(20) {
        students = new Student*[studentCapacity];
        professors = new Professor*[professorCapacity];
        items = new Item*[itemCapacity];
    }
    
    ~Library() {

        for(int i=0; i<studentCount; i++)
        {
            delete students[i];
        }

        for(int i=0; i<professorCount; i++)
        {
            delete professors[i];
        }

        for(int i=0; i<itemCount; i++)
        {
            delete items[i];
        }


        delete[] students;
        delete[] professors;
        delete[] items;
    }
    
    void addStudent(Student* s) {
        if (studentCount >= studentCapacity) {
            resizeStudentArray();
        }
        students[studentCount++] = s;
    }
    
    void addProfessor(Professor* p) {
        if (professorCount >= professorCapacity) {
            resizeProfessorArray();
        }
        professors[professorCount++] = p;
    }
    
    void addItem(Item* item) {
        if (itemCount >= itemCapacity) {
            resizeItemArray();
        }
        items[itemCount++] = item;
    }
    
    bool borrowItem(string personType, int personIndex, int itemId) {
        Item* itemToBorrow = findItem(itemId);
        if (!itemToBorrow || itemToBorrow->getIsBorrowed()) {
            cout << "Prodotto non disponibile o gia' in prestito" << endl;
            return false;
        }
        
        if (personType == "Studente") { // Studente
            if (personIndex < 0 || personIndex >= studentCount) {
                cout << "Studente non trovato" << endl;
                return false;
            }
            Student* student = students[personIndex];
            if (student->canBorrow()) {
                student->borrowItem(itemToBorrow);
                cout << "Prestito effettuato con successo - Studente: " << student->getName() << " " << student->getSurname() << endl;
                return true;
            }
        } else if (personType == "Professore") { // Professore
            if (personIndex < 0 || personIndex >= professorCount) {
                cout << "Docente non trovato" << endl;
                return false;
            }
            Professor* professor = professors[personIndex];
            if (professor->canBorrow()) {
                professor->borrowItem(itemToBorrow);
                cout << "Prestito effettuato con successo - Docente: " << professor->getName() << " " << professor->getSurname() << endl;
                return true;
            }
        }
        
        cout << "Impossibile effettuare il prestito" << endl;
        return false;
    }
    
    bool returnItem(string personType, int personIndex, int itemId) {
        if (personType == "Studente") { // Studente
            if (personIndex < 0 || personIndex >= studentCount) {
                cout << "Studente non trovato" << endl;
                return false;
            }
            Student* student = students[personIndex];
            bool success = student->returnItem(itemId);
            if (success) {
                cout << "Restituzione effettuata con successo - Studente: " << student->getName() << " " << student->getSurname() << endl;
            } else {
                cout << "Prodotto non trovato tra quelli in prestito" << endl;
            }
            return success;
        } else if (personType == "Professore") { // Professore
            if (personIndex < 0 || personIndex >= professorCount) {
                cout << "Docente non trovato" << endl;
                return false;
            }
            Professor* professor = professors[personIndex];
            bool success = professor->returnItem(itemId);
            if (success) {
                cout << "Restituzione effettuata con successo - Docente: " << professor->getName() << " " << professor->getSurname() << endl;
            } else {
                cout << "Prodotto non trovato tra quelli in prestito" << endl;
            }
            return success;
        }
        
        cout << "Tipo persona non valido" << endl;
        return false;
    }
    
    void printAllBorrowedItems(ostream& os) const {
        os << "=== SITUAZIONE PRESTITI ===" << endl;
        
        // Iterare attraverso gli studenti
        for (int i = 0; i < studentCount; i++) {
            students[i]->printBorrowedItems(os);
        }
        
        // Iterare attraverso i professori
        for (int i = 0; i < professorCount; i++) {
            professors[i]->printBorrowedItems(os);
        }
    }

private:
    string name;
    Student** students;
    Professor** professors;
    Item** items;
    int studentCount;
    int professorCount;
    int itemCount;
    int studentCapacity;
    int professorCapacity;
    int itemCapacity;

    Item* findItem(int id) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getId() == id) {
                return items[i];
            }
        }
        return nullptr;
    }

    void resizeStudentArray() {
        int newCapacity = studentCapacity * 2;
        Student** newArray = new Student*[newCapacity];
        for (int i = 0; i < studentCount; i++) {
            newArray[i] = students[i];
        }

        for (int i = studentCount; i <newCapacity; i++) {
            newArray[i] = nullptr;
        }

        delete[] students;
        students = newArray;
        studentCapacity = newCapacity;
    }

    void resizeProfessorArray() {
        int newCapacity = professorCapacity * 2;
        Professor** newArray = new Professor*[newCapacity];
        for (int i = 0; i < professorCount; i++) {
            newArray[i] = professors[i];
        }

        for (int i = professorCount; i<newCapacity; i++) {
            newArray[i] = nullptr;
        }

        delete[] professors;
        professors = newArray;
        professorCapacity = newCapacity;
    }

    void resizeItemArray() {
        int newCapacity = itemCapacity * 2;
        Item** newArray = new Item*[newCapacity];
        for (int i = 0; i < itemCount; i++) {
            newArray[i] = items[i];
        }

        for (int i = itemCount; i <newCapacity; i++) {
            newArray[i] = nullptr;
        }

        delete[] items;
        items = newArray;
        itemCapacity = newCapacity;
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
    biblioteca.borrowItem("Studente", 0, 1); // Studente 0 prende libro 1
    biblioteca.borrowItem("Studente", 0, 2); // Studente 0 prende libro 2
    biblioteca.borrowItem("Studente", 1, 3); // Studente 1 prende libro 3
    biblioteca.borrowItem("Studente", 1, 7); // Studente 1 prende DVD 7
    
    // Prestiti ai professori (indice 0 per il primo professore)
    biblioteca.borrowItem("Professore", 0, 4); // Professore 0 prende libro 4
    biblioteca.borrowItem("Professore", 0, 8); // Professore 0 prende DVD 8
    biblioteca.borrowItem("Professore", 1, 5); // Professore 1 prende libro 5
    biblioteca.borrowItem("Professore", 1, 9); // Professore 1 prende DVD 9
    
    cout << "\n=== TEST RESTITUZIONI ===" << endl;
    
    // Restituzioni
    biblioteca.returnItem("Studente", 0, 1); // Studente 0 restituisce libro 1
    biblioteca.returnItem("Professore", 0, 4); // Professore 0 restituisce libro 4
    
    cout << "\n=== TEST LIMITE PRESTITI ===" << endl;
    
    // Tentativo di superare il limite per lo studente
    biblioteca.borrowItem("Studente", 0, 3); // Studente 0 prende libro 3
    biblioteca.borrowItem("Studente", 0, 4); // Studente 0 prende libro 4
    biblioteca.borrowItem("Studente", 0, 5); // Studente 0 prende libro 5
    biblioteca.borrowItem("Studente", 0, 6); // Studente 0 prova a prendere libro 6 (supera limite)
    
    // Tentativo di superare il limite per il professore
    biblioteca.borrowItem("Professore", 0, 10); // Professore 0 prende DVD 10
    biblioteca.borrowItem("Professore", 0, 2);  // Professore 0 prende libro 2
    biblioteca.borrowItem("Professore", 0, 3);  // Professore 0 prende libro 3
    biblioteca.borrowItem("Professore", 0, 5);  // Professore 0 prende libro 5
    biblioteca.borrowItem("Professore", 0, 6);  // Professore 0 prende libro 6
    biblioteca.borrowItem("Professore", 0, 1);  // Professore 0 prende libro 1
    biblioteca.borrowItem("Professore", 0, 7);  // Professore 0 prova a prendere DVD 7 (supera limite)
    
    cout << "\n=== SITUAZIONE FINALE ===" << endl;
    biblioteca.printAllBorrowedItems(cout);
    
    return 0;
}