#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Nodo
{
public:
    Nodo(string in, string mac) : indirizzo_IP(in), indirizzo_MAC(mac) , stato(true) {}
    virtual ~Nodo() {}
    string getInidirizzo_IP() const {return indirizzo_IP;}
    string getIndirizzo_MAC() const {return indirizzo_MAC;}
    bool getStato() const {return stato;}

    void setStato(bool s) {stato = s;}

    virtual void print() const 
    {
        cout << "indirizzo IP: " << indirizzo_IP << " indirizzo MAC " << indirizzo_MAC << endl;
    }

private:
    string indirizzo_IP;
    string indirizzo_MAC;
    bool stato;
};

class Client : public Nodo
{
public:
    Client(string in, string mac, int lvl) : Nodo(in,mac), livello_Sicurezza(lvl) {}

    int getLivelloSicurezza() const {return livello_Sicurezza;}

    void print() const override
    {
        cout << "Client -> ";
        Nodo::print();
        cout << "Livello di permesso: " << livello_Sicurezza << endl;
    }

private:
    int livello_Sicurezza;
};

class Server : public Nodo
{
public:
    Server(string in, string mac, string t, int cap) : Nodo(in,mac), tipo_server(t), capacita_massima(cap) , connessioni_attuali(0) {}

    int getCapacita_massima() const {return capacita_massima;}
    int getConnessioni_attuali() const {return connessioni_attuali;}
    string getTipo_server() const {return tipo_server;}

    void nuova_connessione() {connessioni_attuali++;}
    void chiudi_connessione() {connessioni_attuali--;}

    void print() const override
    {
        cout << "Server -> ";
        Nodo::print();
        cout << "Limite di capacita': " << capacita_massima << " connessioni attuali: " << connessioni_attuali << endl;
    }

private:
    int capacita_massima;
    int connessioni_attuali;
    string tipo_server;
};

class Pacchetto
{
public:
    Pacchetto(string s, string d, double dim) : sorgente(s), destinazione(d), dimensione(dim) {}
    ~Pacchetto(){}

    string getSorgente() const {return sorgente;}
    string getDestinazione() const {return destinazione;}
    double getDimensione() const {return dimensione;}

    void print() const 
    {
        cout << "Pacchetto -> sorgente: " << sorgente << " destinazione: " << destinazione << " dimensione: " << dimensione << " mb " << endl;
    }

private:
    string sorgente;
    string destinazione;
    double dimensione;
};

class Connessione
{
public:
    Connessione(Client* c, Server* s, double d=0) : client(c), server(s), durata(d) {}
    ~Connessione() {}

    Client* getClient() const {return client;}
    Server* getServer() const {return server;}
    double getDurata() const {return durata;}

    void print() const 
    {
        cout << "Connessione attiva: " << client->getInidirizzo_IP() << " <--> " << server->getInidirizzo_IP() << " (" << durata << " ms)" << endl;
    }

private:
    Client* client;
    Server* server;
    double durata;
};

class NetworkController
{
public:
    NetworkController() : contatore_nodi(0), capienza_nodi(10), contatore_connessione(0), capienza_connessione(10)
    {
        nodi = new Nodo* [capienza_nodi];

        connessioni = new Connessione* [capienza_connessione];
    }

    ~NetworkController()
    {
        for(int i=0; i<contatore_nodi; i++)
        {
            delete nodi[i];
        }

        for(int i=0; i<contatore_connessione; i++)
        {
            delete connessioni[i];
        }

        delete [] nodi;
        delete [] connessioni;
    }

    bool limite_size_nodi()
    {
        return contatore_nodi >= capienza_nodi;
    }

    bool limite_size_connessioni()
    {
        return contatore_connessione >= capienza_connessione;
    }

    bool addNode(Nodo *n)
    {
        if(!n)
            return false;

        if(limite_size_nodi())
            resize_array_nodi();

        nodi[contatore_nodi++] = n;
        return true;
    }

    bool addConnessione(Connessione* s)
    {
        if(!s)
            return false;

        if(limite_size_connessioni())
            resize_array_connessione();

        connessioni[contatore_connessione++] = s;
        return true;
    }


    bool startConnection(Client* c, Server* s)
    {
    
        if(!c || !s) return false;

    
        if(c->getStato() == false || s->getStato() == false)
        {
            cout << "Errore: Uno dei nodi e' Offline." << endl;
            return false; 
        }

    
        if(s->getConnessioni_attuali() >= s->getCapacita_massima())
        {
            cout << "Errore: Server saturo." << endl;
            return false;
        }

        if(s->getTipo_server() == "DATABASE")
        {
        
            if(c->getLivelloSicurezza() < 4)
            {
                cout << "Errore: Accesso negato (Livello sicurezza insufficiente)." << endl;
                return false;
            }
        }
        
        double latenza = 10.0 + (double)rand() / RAND_MAX * (200.0 - 10.0);
        Connessione* nuovaConn = new Connessione(c, s, latenza);

        addConnessione(nuovaConn);

        s->nuova_connessione();

        cout << "Connessione stabilita con successo!" << endl;
        return true;
    }

    bool stopConnection(Client* c)
    {
        if(!c) return false;

        for(int i=0; i < contatore_connessione; i++)
        {
        
            if(connessioni[i]->getClient() == c) 
            {
            
                connessioni[i]->getServer()->chiudi_connessione(); 

            
                delete connessioni[i];

            
                for(int j=i; j < contatore_connessione - 1; j++)
                {
                    connessioni[j] = connessioni[j+1];
                }

            
                connessioni[contatore_connessione - 1] = nullptr;
                contatore_connessione--; 

                cout << "Connessione terminata per il client " << c->getInidirizzo_IP() << endl;
                return true;
            }
        }   

        cout << "Nessuna connessione attiva trovata per questo client." << endl;
        return false;
    }

    bool loadBalancer(string tipoRichiesto)
    {
        Server* bestServer = nullptr;
        int minConnessioni = 999999;

        for(int i=0; i < contatore_nodi; i++)
        {
            Server* s = dynamic_cast<Server*>(nodi[i]);

            if(s != nullptr)
            {
                if(s->getTipo_server() == tipoRichiesto && s->getStato() == true)
                {
                    if(s->getConnessioni_attuali() < minConnessioni)
                    {
                        minConnessioni = s->getConnessioni_attuali();
                        bestServer = s;
                    }
                 }
            }
        }

        if (bestServer != nullptr)
        {
            cout << "Server libero consigliato: ";
            bestServer->print();
             cout << endl;
            return true;
        }
        else
        {
            cout << "Nessun server " << tipoRichiesto << " disponibile al momento." << endl;
            return false;
        }

    }

    bool sendPacket(Client* c, Pacchetto *p)
    {
        if(!c) return false;

        for(int i = 0; i < contatore_connessione; i++)
        {
        
            if(connessioni[i]->getClient() == c)
            {
                cout << "--- Invio Pacchetto ---" << endl;
                cout << "Da: " << c->getInidirizzo_IP() << " Verso Server: " << connessioni[i]->getServer()->getInidirizzo_IP() << endl;

                p->print(); 
            
                return true;
            }
        }

        cout << "Errore invio: Il client " << c->getInidirizzo_IP() << " non e' connesso alla rete." << endl;
        return false;
    }

    void print_all() const
    {
        cout << "Elenco Server e Client registrati nell sistema" << endl;

        for(int i=0; i<contatore_nodi; i++)
        {
            nodi[i]->print();
            cout << endl;
        }

        cout << "Elenco delle connessioni attive nel sistema" << endl;
        for(int i=0; i<contatore_connessione; i++)
        {
            if(connessioni[i]->getClient()->getStato() && connessioni[i]->getServer()->getStato())
            connessioni[i]->print();
        }
    }




private:
    Nodo** nodi;
    int contatore_nodi;
    int capienza_nodi;

    Connessione** connessioni;
    int contatore_connessione;
    int capienza_connessione;

    void resize_array_nodi()
    {
        int newcapienza = capienza_nodi * 2;
        Nodo** newarray = new Nodo*[newcapienza];

        for(int i=0; i<contatore_nodi; i++)
        {
            newarray[i] = nodi[i];
        }

        for(int i=contatore_nodi; i<newcapienza; i++)
        {
            newarray[i] = nullptr;
        }

        delete [] nodi;
        nodi = newarray;
        capienza_nodi = newcapienza;
    }

    void resize_array_connessione()
    {
        int newcapienza = capienza_connessione * 2;
        Connessione** newarray = new Connessione*[newcapienza];

        for(int i=0; i<contatore_connessione; i++)
        {
            newarray[i] = connessioni[i];
        }

        for(int i=contatore_connessione; i<newcapienza; i++)
        {
            newarray[i] = nullptr;
        }

        delete [] connessioni;
        connessioni = newarray;
        capienza_connessione= newcapienza;
    }
};

int main(){

    srand(time(nullptr));

    NetworkController network;

    //CREAZIONE SERVER
    Server* server_data = new Server("192.168.0.15","00:1A:2B:3C:4D:5E","DATABASE",5);

    Server* server_web1 = new Server("172.16.254.12","52:54:00:6B:82:10","WEB",2);
    Server* server_web2 = new Server("198.367.3.21","00:50:56:C0:00:08","WEB",2);

    //CREAZIONE CLIENT
    Client* client_admin = new Client("192.168.1.145","52:54:00:AB:CD:EF",5);

    Client* client_guest1 = new Client("192.168.1.102","A4:5E:60:D4:33:99",1);
    Client* client_guest2 = new Client("192.168.1.10","00:1A:2B:88:99:01",1);

    //SALVATAGGIO IN UN ARRAY DI NODO*
    network.addNode(server_data);
    network.addNode(server_web1);
    network.addNode(server_web2);
    network.addNode(client_admin);
    network.addNode(client_guest1);
    network.addNode(client_guest2);

    //Tentare di connettere un Guest al Database (Deve fallire per vincolo sicurezza).
    cout << "==== TEST CONNESSIONE GUEST -> DATABASE ====" << endl;
    network.startConnection(client_guest1,server_data);
    cout << endl;

    //Connettere l'Admin al Database (Deve riuscire). 
    cout << "==== TEST CONNESSIONE ADMIN -> DATABASE ====" << endl;
    network.startConnection(client_admin,server_data);
    cout << endl;

    //Simulare un picco di traffico: Connettere molteplici client al primo Server WEB fino a saturarlo. 
    cout << "==== TEST SATURAZIONE CLIENT -> WEB ====" << endl;
    network.startConnection(client_guest1,server_web1);
    network.startConnection(client_guest2,server_web1);
    network.startConnection(client_admin,server_web1);
    cout << endl;

    //Utilizzare il metodo loadBalancer per trovare un server libero per un nuovo client.
    cout << "==== TEST RICERCA DI UN SERVER LIBERO ====" << endl;
    network.loadBalancer("WEB");
    cout <<endl;

    //Chiusura di una connessione tra client e server.
    cout << "==== TEST CHIUSURA CONNESSIONE ====" << endl;
    network.stopConnection(client_guest2);
    cout << endl;

    //Invio pacchetto tra Client e Server
    Pacchetto* p1 = new Pacchetto("192.168.1.145", "192.168.0.15", 10.5);
    cout << "==== TEST INVIO DI UN PACCHETTO TRA CLIENT -> SERVER" << endl;
    network.sendPacket(client_guest1,p1);
    cout << endl;
    delete p1;

    //Stampare la lista delle connessioni attive con i dettagli (IP Client -> IP Server).
    cout << "==== STAMPA DELLE CONNESSIONI ATTIVE ====" << endl;
    network.print_all();

    return 0;

}