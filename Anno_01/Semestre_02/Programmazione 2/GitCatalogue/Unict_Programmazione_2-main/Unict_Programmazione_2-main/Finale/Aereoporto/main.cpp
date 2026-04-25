#include <iostream>

using namespace std;

class Passeggero
{
public:
    Passeggero(int i, string n, string s, bool st) : id(i), name(n), surname(s), status(st) {}
    ~Passeggero(){}
    
    int getId() const {return id;}
    string getName() const {return name;}
    string getSurname() const {return surname;}
    bool getStatus() const {return status;}

    void print() const 
    {
        if(!status)
            cout << "Passeggero - " << "Id: " << id << " Nome: " << name << " Cognome: " << surname << endl;
        else
            cout << "Passeggero Speciale - " << "Id: " << id << " Nome: " << name << " Cognome: " << surname << endl;
    }   

private:
    string name;
    string surname;
    int id;
    bool status;
};

class Volo
{
public:
    Volo(string id, string dest, int capienza_tot) : id_volo(id), destinazione(dest), posti_disponibili(capienza_tot), contatore_passeggeri(0), capienza_passeggeri(capienza_tot)
    {
        passeggeri = new Passeggero* [contatore_passeggeri];
    }

    ~Volo()
    {
        delete [] passeggeri;
    }

    string getId_volo() const {return id_volo;}
    string getDestinazione() const {return destinazione;}
    int getPosti_disponibli() const {return posti_disponibili;}

    bool add_passeggero(Passeggero* p)
    {
        if(!p)
            return false;

        if(contatore_passeggeri >= capienza_passeggeri)
            return false;

        passeggeri[contatore_passeggeri++] = p;
        posti_disponibili--;
        return true;
    }

    bool remove_passeggero(Passeggero* p)
    {
        for(int i=0; i<contatore_passeggeri; i++)
        {
            
            if(passeggeri[i]->getId() == p->getId())
            {
                for(int j=i; j<contatore_passeggeri-1; j++)
                {
                    passeggeri[j] = passeggeri[j+1];
                }

                passeggeri[contatore_passeggeri-1] = nullptr; 
                contatore_passeggeri--;
                posti_disponibili++;
                return true;
            }
        }

        return false;
    }

    void print() const 
    {
        cout << "Volo - Id: " << id_volo << " - Destinazione: " << destinazione << "- Posti Disponibili: " << posti_disponibili << endl; 
    }


private:
    string id_volo;
    string destinazione;
    int posti_disponibili;

    Passeggero** passeggeri;
    int contatore_passeggeri;
    int capienza_passeggeri;
};

class Prenotazione
{
public:
    Prenotazione(int id, Passeggero* _p, Volo* _v) : id_prenotazione(), p(_p), v(_v) {}

    int getId_prenotazione() const{return id_prenotazione;}
    Volo* getVolo() const {return v;}
    Passeggero* getPasseggero() const {return p;}

    bool richiesta_prenotazione()
    {
        if(!p || !v)
            return false;

        v->add_passeggero(p);
        return true;
    }

    bool richiesta_annullamento_prenotazione()
    {
        if(!p || !v)
            return false;

        v->remove_passeggero(p);
        return true;
    }


private:
    int id_prenotazione;
    Volo* v;
    Passeggero* p;
};

class Sistema_Prenotazione
{
public:
    Sistema_Prenotazione(string n, string c) : name(n), company(c), contatore_prenotazioni(0), capienza_prenotazioni(10), contatore_voli(0), capienza_voli(10)
    {
        prenotazioni = new Prenotazione* [capienza_prenotazioni];

        voli = new Volo* [capienza_voli];
    }

    ~Sistema_Prenotazione()
    {
        for(int i=0; i<contatore_voli; i++)
        {
            delete voli[i];
        }

        for(int i=0; i<contatore_prenotazioni; i++)
        {
            delete prenotazioni[i];
        }

        delete [] voli;
        delete [] prenotazioni;
    }

    string getName() const {return name;}

    void add_prenotazioni(Prenotazione* p)
    {
        if(!p)
            return;

        if(contatore_prenotazioni >= capienza_prenotazioni)
            resize_array(prenotazioni,contatore_prenotazioni,capienza_prenotazioni);

        prenotazioni[contatore_prenotazioni++] = p;
    }

    bool add_voli(Volo* v)
    {
        if(!v)
            return false;

        if(contatore_voli >= capienza_voli)
            resize_array(voli,contatore_voli,capienza_voli);

        voli[contatore_voli++] = v;
        return true;
    }


    bool remove_voli(Volo* v)
    {
        for(int i=0; i<contatore_voli; i++)
        {
           if(voli[i]->getId_volo() == v->getId_volo())
           {
                for(int j=0; j<contatore_prenotazioni; j++)
                {
                    if(prenotazioni[j]->getVolo() == v)
                    {
                        remove_prenotazione(prenotazioni[j]);
                        j--;
                    }
                }
    
                delete voli[i];

                for(int j=i ; j<contatore_voli-1; j++)
                {
                    voli[j] = voli[j+1];
                }

                voli[contatore_voli-1] = nullptr;
                contatore_voli--;
                cout << "Volo Rimosso: ";
                v->print();
                cout << endl;
                return true;
            }
        }

        cout << "ERRORE: Volo non registrato" << endl;
        return false;
    }


    bool remove_prenotazione(Prenotazione* p)
    {
        for(int i=0; i<contatore_prenotazioni; i++)
        {
            if(prenotazioni[i]->getId_prenotazione() == p->getId_prenotazione())
            {
                delete prenotazioni[i]; 

                for(int j=i ; j<contatore_prenotazioni-1; j++)
                {
                    prenotazioni[j] = prenotazioni[j+1];
                }

                prenotazioni[contatore_prenotazioni-1] = nullptr;
                contatore_prenotazioni--;
                return true;
            }
        }

        return false;
    }

    bool conferma_prenotazione(Prenotazione* p)
    {
        if(!p)
            return false;

        bool success = p->richiesta_prenotazione();

        if(success)
        {
            add_prenotazioni(p);
            cout << "\nPrenotazione effettuata con successo!" << endl;
            p->getPasseggero()->print();
            p->getVolo()->print();
            return true;
        }
        else
        {
            cout << "Errore: prenotazione non andata a buon fine" << endl;
            return false;
        }

        cout << "Errore: prenotazione inesistente nel databese" << endl;
        return false;
    }

    bool annulla_prenotazione(Prenotazione* p)
    {
         if(!p)
            return false;

        bool success = p->richiesta_annullamento_prenotazione();

        if(success)
        {
            remove_prenotazione(p);
            cout << "Prenotazione annullata!" << endl;
            p->getPasseggero()->print();
            p->getVolo()->print();
            cout << endl;
            return true;
        }
        else
        {
            cout << "Errore: annullamento prenotazione non andata a buon fine" << endl;
            cout << endl;
            return false;
        }

        cout << "Errore: impossibile annullare la prenotazione inesistente nel databese" << endl;
        cout << endl;
        return false;
    }

    bool ricerca_volo_disp(string destinazione)
    {
        for(int i=0; i<contatore_voli; i++)
        {
            if(voli[i]->getDestinazione() == destinazione)
            {
                if(voli[i]->getPosti_disponibli() > 0)
                {
                    cout << "Conferma posti disponibili per il seguente volo: "<< endl;
                    voli[i]->print();
                    cout << endl;
                    return true;
                }
                else
                {
                    cout << "ERRORE: Nessun posto disponibile per il seguente volo: " << endl;
                    voli[i]->print();
                    cout << endl;
                    return false;
                }
            }
        }

        cout << "ERRORE: Nessuno volo per la seguente destinazione" << endl;
        return false;
    }

    void ricerca_passeggero_speciale(Volo* v)
    {
        for(int i=0; i<contatore_prenotazioni; i++)
        {
            if(prenotazioni[i]->getVolo() == v)
            {
                if(prenotazioni[i]->getPasseggero()->getStatus())
                {
                    prenotazioni[i]->getPasseggero()->print();
                }
            }
        }
        cout << endl;
    }

    void print_passeggero(Passeggero* p) const 
    {

        p->print();
        cout << "Elenco delle sue prenotazioni: "<<endl;
        bool success = false;


        for(int i=0; i<contatore_prenotazioni; i++)
        {
            if(prenotazioni[i]->getPasseggero() == p)
            {
                prenotazioni[i]->getVolo()->print();
                success = true;
            }
        }

        if(!success)
            cout << "Nessuna prenotazione effettuata" << endl;
    }



private:
    string name;
    string company;

    Prenotazione** prenotazioni;
    int contatore_prenotazioni;
    int capienza_prenotazioni;

    Volo** voli;
    int contatore_voli;
    int capienza_voli;

    template <typename T>
    void resize_array(T**& array, int contatore, int& capienza)
    {
        int newcapienza = capienza * 2;
        T** newarray = new T* [newcapienza];

        for(int i=0; i<contatore; i++)
        {
            newarray[i] = array[i];
        }

        for(int i=contatore; i<newcapienza; i++)
        {
            newarray[i] = nullptr;
        }

        delete [] array;
        array = newarray;
        capienza = newcapienza;
    }
};

int main()
{
    //CREAZIONE PASSEGGERI

    Passeggero* p1 = new Passeggero(100,"Mike","Mason",false);
    Passeggero* p2 = new Passeggero(101,"Joshua","Taison",false);

    Passeggero* p3 = new Passeggero(102,"Hannibal","Lecter",true);
    Passeggero* p4 = new Passeggero(103,"Dexter","Morgan",true);
    Passeggero* p5 = new Passeggero(104,"Brian","Moiser",true);

    //CREAZIONE VOLI
    Volo* v1 = new Volo("RA145","Torino",2);
    Volo* v2 = new Volo("RA178","Catania",5);
    Volo* v3 = new Volo("RA198","Milano",6);

    //CREAZIONE PRENOTAZIONI

    Prenotazione* pr1 = new Prenotazione(7007,p1,v1);   // p1 -> v1
    Prenotazione* pr2 = new Prenotazione(7112,p1,v2);   // p1 -> v2
    Prenotazione* pr3 = new Prenotazione(7563,p1,v3);   // p1 -> v3

    Prenotazione* pr4 = new Prenotazione(7217,p2,v1);   // p2 -> v1

    Prenotazione* pr5 = new Prenotazione(7147,p3,v2);   // p3 -> v2
    Prenotazione* pr6 = new Prenotazione(7217,p2,v3);   // p3 -> v3

    Prenotazione* pr7 = new Prenotazione(7200,p4,v3);   // p4 -> v3

    Prenotazione* pr8 = new Prenotazione(7127,p5,v3);   // p5 -> v3

    Sistema_Prenotazione Aereoporto("Fontana Rossa","Ryanair");

    cout << "\n===== BENVENUTI ALL'AEREOPORTO: " << Aereoporto.getName() << " =====" << endl;

    //INSERIMENTO VOLI
    Aereoporto.add_voli(v1);
    Aereoporto.add_voli(v2);
    Aereoporto.add_voli(v3);

    cout << "===== TEST CONFERMA PRENOTAZIONE =====" << endl;
    Aereoporto.conferma_prenotazione(pr1);
    Aereoporto.conferma_prenotazione(pr2);
    Aereoporto.conferma_prenotazione(pr3);
    Aereoporto.conferma_prenotazione(pr4);
    Aereoporto.conferma_prenotazione(pr5);
    Aereoporto.conferma_prenotazione(pr6);
    Aereoporto.conferma_prenotazione(pr7);
    Aereoporto.conferma_prenotazione(pr8);

    cout << "===== TEST ANNULLA PRENOTAZIONE =====" << endl;
    Aereoporto.annulla_prenotazione(pr2);

    cout << "===== TEST RICERCA DI POSTI DISPONIBILI PER UN SPECIFICO VOLO =====" << endl;
    Aereoporto.ricerca_volo_disp("Milano");

    cout << "===== TEST RIMOZIONE VOLO =====" << endl;
    Aereoporto.remove_voli(v2);

    cout << "===== TEST INDIVIDUAZIONE PASSEGGERI SPECIALE IN UN SPECIFICO VOLO =====" << endl;
    Aereoporto.ricerca_passeggero_speciale(v3);
    
    cout << "===== TEST STAMPA DI PRENOTAZIONI REGISTRATI NEL DATABASE =====" << endl;
    Aereoporto.print_passeggero(p1);
    cout << endl;
    Aereoporto.print_passeggero(p2);
    cout << endl;
    Aereoporto.print_passeggero(p3);
    cout << endl;
    Aereoporto.print_passeggero(p4);
    cout << endl;
    Aereoporto.print_passeggero(p5);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;


    return 0;
}
