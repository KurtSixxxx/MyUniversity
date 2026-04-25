#include <iostream>

using namespace std;

class Item
{
public:
    Item(string t, string p, int i) : title(t), publicationDate(p), id(i), stato(true) {}
    virtual ~Item() {}

    string getTitle() const {return title;}
    string getPublicationDate() const {return publicationDate;}
    int getId() const {return id;}
    bool getStato() const {return stato;}
    
    void setStato(bool s) {stato = s;}

    virtual void print() const = 0; 

private:
    string title;
    string publicationDate;
    int id;
    bool stato;
};

class Book : public Item
{
public:
    Book(string t, string a, string p, int i) : Item(t,p,i), author(a) {}

    string getAuthor() const {return author;}

    void print() const override
    {
        cout << "Book: - " << getTitle() << " - " << author << " - " << getPublicationDate() << " - " << getId() << endl;
    }

private:
    string author;
};


class DVD : public Item
{
public:
    DVD(string t, string d, string p, int i) : Item(t,p,i), duration(d) {}

    string getDuration() const {return duration;}

    void print() const override
    {
        cout << "DVD: " << getTitle() << " - " << duration << " - " << getPublicationDate() << " - " << getId() << endl;
    }

private:
    string duration;
};


class User
{
public:
    User(string n, string s, int c) : name(n), surname(s), count_item(0), capacity_item(c)
    {
        borrowitems = new Item*[capacity_item];
    }

    virtual ~User()
    {
        delete [] borrowitems;
    }

    string getName() const {return name;}
    string getSurname() const {return surname;}
    int getCapacity_item() const {return capacity_item;}


    bool borrow_(Item* item)
    {
        if(!item)
            return false;

        if(count_item >= capacity_item)
            return false;
        
        borrowitems[count_item++] = item;
        item->setStato(false);
        return true;
    }

    bool return_(Item* item)
    {
        if(!item)
            return false;

        for(int i=0; i<count_item; i++)
        {
            if(borrowitems[i] == item)
            {
                for(int j = i; j<count_item-1; j++)
                {
                    borrowitems[j] = borrowitems[j+1];
                }

                borrowitems[count_item-1] = nullptr;
                count_item--;
                item->setStato(true);
                return true;
            }
        }

        return false;
    }

    virtual void printBorrowedItems() const 
    {
        for(int i=0; i<count_item; i++)
        {
            borrowitems[i]->print();
        }
    }
    
    virtual string status() const = 0;
 
private:
    string name;
    string surname;

    Item** borrowitems;
    int count_item;
    int capacity_item;
    
};

class Student : public User
{
public:
    Student(string n, string s) : User(n,s,5) {} 

    string status() const override {return "Studente";}

    void printBorrowedItems() const override
    {
        cout << "\nStudente: " << getName() << " " << getSurname() << " prestiti consentiti: " << getCapacity_item() << endl;
        User::printBorrowedItems(); 
    }
};

class Professor : public User
{
public:
    Professor(string n, string s) : User(n,s,10) {} 

     string status() const override {return "Professore";}

    void printBorrowedItems() const override
    {
        cout << "\nProfessore: " << getName() << " " << getSurname() << " prestiti consentiti: " << getCapacity_item() << endl;
        User::printBorrowedItems(); 
    }
};

class Library
{
public:
    Library(string n) : name(n), count_item(0), capacity_item(10), count_professor(0), capacity_professor(10), count_student(0), capacity_student(10)
    {
        items = new Item*[capacity_item];

        professors = new Professor*[capacity_professor];

        students = new Student*[capacity_student];
    }

    ~Library()
    {
        for(int i=0; i<count_item; i++)
        {
            delete items[i];
        }

        for(int i=0; i<count_professor; i++)
        {
            delete professors[i];
        }

        for(int i=0; i<count_student; i++)
        {
            delete students[i];
        }

        delete [] items;
        delete [] professors;
        delete [] students;
    }

    string getName() const {return name;}
    
    void add_item(Item* i)
    {
        if(count_item >= capacity_item)
            resize_array(items,count_item,capacity_item);

        items[count_item++] = i;
    }

    void add_professor(Professor* p)
    {
        if(count_professor >= capacity_professor)
            resize_array(professors,count_professor,capacity_professor);

        professors[count_professor++] = p;
    }

    void add_student(Student* s)
    {
        if(count_student>=capacity_student)
            resize_array(students,count_student,capacity_student);

        students[count_student++] = s;
    }


    bool borrow_item(int index_item, User* user_)
    {
        Item* item = find_item(index_item);

        if(!item)
        {
            cout << "ERRORE: Indice errato o libro inesistente" << endl;
            cout << endl;
            return false;
        }

        if(!item->getStato())
        {
            cout << "ERRORE: Il prodotto e' attualmente in prestito." << endl;
            cout << endl;
            return false;
        }

        User* user = find_user(user_);

        if(!user)
        {
            cout << "ERRORE: Utente non registrato"<<endl;
            cout << endl;
            return false;
        }
        
        bool success = user->borrow_(item);

        if(success)
        {
            cout << user->status() << " " << user->getName() << " " << user->getSurname() << endl;
            cout << "Ha preso in prestito: ";
            item->print();
            cout << endl;
            return true;
        }
        else
        {
            cout << "ERRORE: Prestito fallito (Limite raggiunto o libro non disponibile)." << endl;
            cout << endl;
            return false;
        }

    }

    bool return_item(int index_item, User* user_)
    {
        Item* item = find_item(index_item);

        if(!item)
        {
            cout << "ERRORE: Indice errato o libro inesistente" << endl;
            cout << endl;
            return false;
        }

        if(item->getStato())
        {
            cout << "ERRORE: Il prodotto non e' attualmente in prestito." << endl;
            cout << endl;
            return false;
        }

        User* user = find_user(user_);

        if(!user)
        {
            cout << "ERRORE: Utente non registrato"<<endl;
            cout << endl;
            return false;
        }

        bool success = user->return_(item);

        if(success)
        {
            cout << user->status() << " " << user->getName() << " " << user->getSurname() << endl;
            cout << "Ha restituito : ";
            item->print();
            cout << endl;
            return true;
        }
        else
        {
            cout << "ERRORE: Restituzione fallita." << endl;
            cout << endl;
            return false;
        }

    }

    void print_all()
    {
        for(int i=0; i<count_professor; i++)
        {
            professors[i]->printBorrowedItems();
        }

        for(int i=0; i<count_student; i++)
        {
            students[i]->printBorrowedItems();
        }
    }
    
private:
    string name;

    Item** items;
    int count_item;
    int capacity_item;

    Professor** professors;
    int count_professor;
    int capacity_professor;

    Student** students;
    int count_student;
    int capacity_student;

    Item* find_item(int index_item)
    {
        for(int i=0; i<count_item; i++)
        {
            if(items[i]->getId() == index_item)
            {
                return items[i];
            }
        }

        return nullptr;
    }

    User* find_user(User* user)
    {
        for(int i=0; i<count_student; i++)
        {
            if(students[i] == user)
                return students[i];
        }

        for(int i=0; i<count_professor; i++)
        {
            if(professors[i] == user)
                return professors[i];
        }

        return nullptr;
    }

    template <typename T>
    void resize_array(T** &array, int count, int &capacity)
    {
        int newcapacity = capacity * 2;
        T** newarray = new T*[newcapacity];

        for(int i=0; i<count; i++)
        {
            newarray[i] = array[i];
        }

        for(int i=count; i<newcapacity; i++)
        {
            newarray[i] = nullptr;
        }

        delete [] array;
        array = newarray;
        capacity = newcapacity;
    }

};

int main()
{
    //GENERAZIONE UTENTI

    Professor* professore_1 = new Professor("Mario","Rossi");
    Professor* professore_2 = new Professor("Stefano","Borghi");

    Student* studente_1 = new Student("Ezio","Motta");
    Student* studente_2 = new Student("Selen","Guarnera");


    //GENERAZIONE OGGETTI
    Book* book_1 = new Book("L'apocalisse","W.Furuys","10/12/2017",1);
    Book* book_2 = new Book("Viva la vita","T.Errone","12/09/2011",2);
    Book* book_3 = new Book("Il glorioso","I.Lesis","30/11/2004",3);
    Book* book_4 = new Book("La follia","E.Eclesia","05/03/2014",4);

    DVD* dvd_1 = new DVD("Fight Club","2h 17m","10/11/2001",5);
    DVD* dvd_2 = new DVD("Onore e Rispetto","2h 05m","20/06/2021",6);
    DVD* dvd_3 = new DVD("La Donna Esplosiva","1h 57m","06/10/1999",7);
    DVD* dvd_4 = new DVD("Matrix","3h 15m","03/01/2000",8);
    DVD* dvd_5 = new DVD("WW2","4h 15m","10/05/2020",9);


    //CREAZIONE LIBRERIA CON I SUOI METODI  

    Library libreria("Cavallotto");
    cout << "==== LIBRERIA: " << libreria.getName() << " ====" << endl;


    //Crea manualmente qualche studente, docente e prodotto;
    libreria.add_item(book_1);
    libreria.add_item(book_2);
    libreria.add_item(book_3);
    libreria.add_item(book_4);

    libreria.add_item(dvd_1);
    libreria.add_item(dvd_2);
    libreria.add_item(dvd_3);
    libreria.add_item(dvd_4);
    libreria.add_item(dvd_5);

    libreria.add_professor(professore_1);
    libreria.add_professor(professore_2);

    libreria.add_student(studente_1);
    libreria.add_student(studente_2);

    //Mostra come si presta qualche prodotto a docenti e studenti;

    cout << "==== TEST PRESTITO ====" << endl;
    libreria.borrow_item(1,professore_1);
    libreria.borrow_item(3,professore_1);
    libreria.borrow_item(9,professore_2);

    libreria.borrow_item(2,studente_1);   // 1 su 5
    libreria.borrow_item(8,studente_2); 

    //Mostra come si restituisce qualche prodotto;
    cout << "==== TEST RESTITUZIONE ====" << endl;
    libreria.return_item(3,professore_1);


    //Mostra come non sia possibile prestare più prodotti del consentito;
    cout << "==== TEST LIMITE CONSENTITO ====" << endl;
    libreria.borrow_item(3,studente_1);   // 2 su 5
    libreria.borrow_item(4,studente_1);   // 3 su 5
    libreria.borrow_item(5,studente_1);   // 4 su 5
    libreria.borrow_item(6,studente_1);   // 5 su 5
    libreria.borrow_item(7,studente_1);   // LIMITE SUPERATO !

    //Mostra tutti i prodotti ancora in prestito ai docenti e studenti creati
    cout << "==== TEST STAMPA ====" << endl;
    libreria.print_all();

    return 0;
    
}
