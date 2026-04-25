#include <iostream>
#include <sstream>
#include <limits.h>
#include <cstdlib>
using namespace std;

/*
Implementare una classe che rappresenti una gerarchia di veicoli
Ogni veicolo ha un numero di ruote, un tipo di carburante, una velocità massima,
una marca ed un prezzo. 
Tra i veicoli distinguiamo motocicli e automobili.
Si simuli una gara tra 10 veicoli di tipo diverso, riportando posizioni iniziali, sorpassi e classifica finale 
*/

//Dalla descrizione del cliente vediamo qualche metodo che potrebbe ritornare utile
class Veicolo{
    protected:
        int numeroRuote;
        string carburante; //No definitivo
        string motorizzazione; //No definitivo
        int velocitaMax; //Velocità massima
        string marca;
        double prezzo;
    
    public:
        int velocita = 0; //Velocità istantanea
        int posizione; //La posizione attuale del veicolo
        Veicolo(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione, string _carburante, int _numeroRuote):
        velocitaMax(_velocitaMax), prezzo(_prezzo), marca(_marca), motorizzazione(_motorizzazione), carburante(_carburante), numeroRuote(_numeroRuote){}
        int getNumeroRuote(){
            return numeroRuote;
        }
        string getCarburante(){
            return carburante;
        }
        string getMotorizzazione(){
            return motorizzazione;
        }
        int getVelocitaMax(){
            return velocitaMax;
        }
        string getMarca(){
            return marca;
        }
        double getPrezzo(){
            return prezzo;
        }
        void setNumeroRuote(int _numeroRuote){
            this->numeroRuote = _numeroRuote;
            return;
        }
        void setCarburante(string _carburante){
            this->carburante = _carburante;
            return;
        }
        void setMotorizzazione(string _motorizzazione){
            this->motorizzazione = _motorizzazione;
            return;
        }
        void setVelocitaMax(int _velocitaMax){
            this->velocitaMax = _velocitaMax;
            return;
        }
        void setMarca(string _marca){
            this->marca = _marca;
            return;
        }
        void setPrezzo(double _prezzo){
            this->prezzo = _prezzo;
            return;
        }
        void accelera(){
            if(velocita <= velocitaMax){
                this->velocita++;
            }
            return;
        }
        void decelera(){
            if(velocita > 0){
                this->velocita--;
            }
            return;
        }
        virtual string toString() const = 0; //virtual perchè non puo essere richiamata da un'istanza di Veicolo ma da una sua sottoclasse
        friend ostream& operator<<(ostream& stream, const Veicolo& veicolo){
            stream << veicolo.toString(); //Per accedere a questa funzione dobbiamo dichiare const la funzione toString
            return stream;
        }
        void operator=(const Veicolo& veicolo){
            this->numeroRuote = veicolo.numeroRuote;
            this->velocitaMax = veicolo.velocitaMax;
            this->motorizzazione = veicolo.motorizzazione;
            this->carburante = veicolo.carburante;
            this->marca = veicolo.marca;
            this->prezzo = veicolo.prezzo;
        }
};



class Motociclo : public Veicolo{
    public: 
        Motociclo(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione) : 
        Veicolo (velocitaMax, _prezzo, _marca, _motorizzazione, "benzina", 2){
            velocitaMax = _velocitaMax;
        }
        string toString() const{
            stringstream stream;
            stream << "Motociclo: " << endl;
            stream << "-Velocita massima: " << velocitaMax << endl;
            stream << "-Prezzo: " << prezzo << endl;
            stream << "-Marca: " << marca << endl;
            stream << "-Motorizzazione: " << motorizzazione << endl;
            return stream.str();
        }
};

class Automobile : public Veicolo{
    public: 
        Automobile(int _velocitaMax, double _prezzo, string _marca, string _motorizzazione, string _carburante) : 
        Veicolo (velocitaMax, _prezzo, _marca, _motorizzazione, _carburante, 4){
            velocitaMax = _velocitaMax;
        }
        string toString() const{
            stringstream stream;
            stream << "Automobile: " << endl;
            stream << "-Velocita massima: " << velocitaMax << endl;
            stream << "-Prezzo: " << prezzo << endl;
            stream << "-Marca: " << marca << endl;
            stream << "-Motorizzazione: " << motorizzazione << endl;
            stream << "-Carburante: " << carburante << endl;
            return stream.str();
        }    
};


class Gara{
    Veicolo **veicoli; //Puntatore di puntatore a veicolo, questo perchè veicolo è una classe astratta
    int numeroPartecipanti;
    int numeroIscritti;
    int durata;
    void controlla();

    public:
        Gara(int _durata, int _numeroPartecipanti){
            this->durata = _durata;
            this->numeroPartecipanti = _numeroPartecipanti;
            veicoli = new Veicolo*[numeroPartecipanti];
            numeroIscritti = 0;
        }
        void aggiungiPartecipante(Veicolo& nuovoVeicolo){
            *veicoli[numeroIscritti] = nuovoVeicolo;
            numeroIscritti++;
            return;
        }
        void partenza(){
            srand(42);
            for(int i=0; i<durata; i++){
                for(int j=0; j<numeroIscritti; j++){
                    int scelta = rand()%2;
                    if(scelta==1)
                        veicoli[j]->accelera();
                    else
                        veicoli[j]->decelera();
                }
                controlla(i);
            }
            stampaClassifica();
        }
        void controlla(int istanteTempo /*utile nella formula per il calcolo dello spazio percorso*/){
            int max = 0;
            int indiceMax;
            for(int i=0; i<numeroIscritti; i++){
               if(veicoli[i]->velocita > max){
                   max = veicoli[i]->velocita;
                   indiceMax = i;
               }
            }
            cout << "Il veicolo piu veloce: " << * veicoli[indiceMax] << endl;
            return;
        }
        void stampaClassifica(){
            cout << "[ ";
            for(int i=0; i<numeroIscritti; i++) cout << veicoli[i]->getMarca() << ", ";
            cout << " ]" << endl;
            return;
        }
        void sorpassa(Veicolo& veicoloSorpassante, Veicolo& veicoloSorpassato){
            if(veicoloSorpassante.velocita > veicoloSorpassato.velocita){
                veicoloSorpassante.posizione++;
                veicoloSorpassato.posizione--;
                cout << "Il primo veicolo ha superato il secondo" << endl;
                return;   
            }
            else{
                veicoloSorpassante.posizione--;
                veicoloSorpassato.posizione++;
                cout << "Il secondo veicolo ha superato il primo" << endl;
                return;
            }
        }
        ~Gara(){ //Distruttore per svuotare la memoria dopo l'instaziamento di un oggeto
            delete [] veicoli; //Fortemente consigliato in questi casi (obbligatorio per il prof Moltisanti)
        }
};

int main(){
    Motociclo motociclo = Motociclo(50, 100.50, "Ducati", "1000cc");
    cout << motociclo << endl;
    Automobile automobile = Automobile(30, 100.50, "Scania", "1000cc", "Diesel");
    cout << automobile << endl;

    Gara gara(10,10);
    gara.aggiungiPartecipante(motociclo);
    gara.aggiungiPartecipante(automobile);
    gara.partenza();
    return 0;
}