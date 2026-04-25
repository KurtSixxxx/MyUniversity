#include<iostream>
using namespace std;

/*
Spiegazione dei primi due concetti di Astrazione e Incapsulamento

1) Astrazione

Ci consente di modellare un'entità in modo che sia 
la pià vicina possibile alla realtà (ad un oggetto concreto)
Ogni oggetto concreto à sempre caratterizzato:

(Una bottiglia ad esempio)

-->Dalle sue PROPRIETA' [materiale, contenuto, tappo, capienza, colore]
-->Dai sui COMPORTAMENTI [fornire informazioni sul suo stato(meotodi get), modificare informazioni sul suo stato(metodi set)]

(Una gatto ad esempio)

-->PROPRIETA [razza, peso, colore, età, ...]
-->COMPORTAMENTI [cammina(), mangia(), beve(), ..., getRazza(), getEtà(), getColore(), getPeso(), setRazza(), setEtà(), setColore(), setPeso()]

Per ogni oggetto che andiamo ad astrarre tra i comportamenti ci saranno sempre metodi get e metodi set.
Nel caso della bottiglia che era un oggetto statico avevamo solo questi due metodi, nel caso del gatto
che à un oggetto dinamico abbiamo altri comportamenti legati alla natura dell'oggetto (cammina, mangia, beve ...)

Le proprietà saranno sempre implementate come variabili (caratteristiche dell'oggetto), le proprietà saranno sempre implementate come procedure 
o funzioni (azioni che compie l'oggetto).

Tecnicamente (e pià correttamente) in C++ le proprietà prendono il nome di ATTRIBUTI, mentre i comportamenti prendono il nome di METODI
(attenzione alla domanda a trabocchetto, per C++ proprietàe comportamenti non esistono, ma solo ATTRIBUTI e METODI.)
______________________________________________________________________________________________________________________________

2) Incapsulamento e information hiding

L'incapsulamento à il modo o i permessi con cui accediamo alle caratteristiche di una determinata classe.
Come faccio a garantire protezione (gestire visibilità) per metodi e attributi della classe?
Uso i cosiddetti modificatori di accesso che definisco le "autorizzazioni" per accedere ai membri (attributi e metodi) della classe.
I principali modificatori di accesso sono:

	1. public --> Consente pienamente l'accesso (lettura e scrittura) ai membri dichiarati tali anche esternamente alla classe
	2. protected --> Si comporta come un provate per altre classi, come public per classi speciali dette figlie (concetto di ereditarietà)
	3. private --> Non consente l'accesso (lettura e scrittura) ai membri dichiarati tali esternamente alla classe

Il modificatore di accesso di default à private. Significa che se non specificato il compilatore tende a nascondere tutti i membri di una classe.
___________________________________________________________________________________________________________________________________________________________________________

3) Polimorfismo

Estendere la classe madre con una figlia e ridefinire uno stesso metodo significa applicare il polimorfismo dei metodi

___________________________________________________________________________________________________________________________________________________________________________

4) Ereditarietà

La caratteristica di poter avere classi figlie (child) specializzate rispetto a classi madri (baseClass, parent), di specializzare le classi e definire permessi di accesso public, private o 
protected per le classi figlie.

class A : public B {...} --> eredito da A membri public e protected. I membri protected che eredito restano nella classe B protected, i membri public ereditati restano public anche questi
class A : private B {...} --> eredito da A membri public e protected. I membri protected che eredito restano nella classe B protected, mentre i membri public ereditati diventano protected anche questi nella nuova classe B
class A : protected B {...} --> tutti gli elementi ereditati diventano private nella nuova classe
___________________________________________________________________________________________________________________________________________________________________________

*/


class Mammifero {	
	private:	
		string nomeSpecie; //private di default
		int numeroArti;
		int eta;
	
	protected: //sara accessibile anche dalla classe Gatto in quanto figlia
		string sesso;
	
	public:
		string nome;
		
		Mammifero(string _nomeSpecie, int _numeroArti, int _eta){ //Costruttore che sovrascrive quello di default
			nomeSpecie = _nomeSpecie;
			numeroArti = _numeroArti;
			eta = _eta;
		}
		
		void setSesso(string _sesso){ //I metodi set permettono di settare valori anche a membri privati
			sesso = _sesso;
		}
		
		void print(){
			cout << "il mammifero di specie '" << nomeSpecie << "' con " << numeroArti << " arti e di anni' " << eta << endl;
			cout << "Il mammifero si chiama " << nome << endl;
			cout << "il mammifero e di sesso " << sesso << endl;
		}
}; 

class Gatto: public Mammifero { //Classe figlia di Mammifero
	public:	
		Gatto(int _eta) : Mammifero("gatto", 4, _eta){ //Seppur la classe Gatto deriva da Mammifero, abbiamo comunque bisogno di specificare un costruttre, il costruttore eredita dal costruttore Mammifero c a cui passiamo di defaul alcuni valori e ne modifica alti come il parametro eta
			
		}
		
		void miagola(){
			cout << "MEOW" << endl;
		}
		
		void print(){ //Sovrascriviamo il metodo print della classe madre, in questo caso chiamando print() per la classe figlia andremo a visualizzare il comportamento sovrascritto alla quello della classe madre. Se ridefinisco un metodo presente nella classe madre, quello che verrà chiamato per Gatto non à pià il vecchio metodo ma il nuovo.
			cout << "Il gatto e di sesso " << sesso << endl;
		}
};


class Cane : public Mammifero{
	private:
		string coloreCollare;
		
	public:
		Cane(int _eta, string _coloreCollare) : Mammifero("cane", 4, _eta){ //Aggiunto un nuovo parametro nel costruttore che à il coloreCollare
			coloreCollare = _coloreCollare;
		}
		
		void setColoreCollare(string _coloreCollare){
			coloreCollare = _coloreCollare;
		}
		
		string getColoreCollare(){
			return coloreCollare;
		}
		
		void seduto(){
			cout << "Mi sono seduto" << endl;
		}
		
		void abbaia(){
			cout << "BAU" << endl;
		}	
};

int main(){
	Mammifero mammifero = Mammifero("Homo Sapiens", 4, 12); //Istanza della classe Mammifero
	mammifero.nome = "Patrick"; //Possibile cambiare il valore perchà l'attributo nome à stato dichiarato come pubblico
	mammifero.setSesso("Maschile"); //Chiamo il metodo set
	mammifero.print();
		
	cout << endl << endl; 
	
	Gatto gatto = Gatto(12);
	gatto.setSesso("Maschile"); //Funzione definita in Mammifero ma richiamabile da Gatto perchà dichiarata nella parte public di Mammifero
	gatto.miagola();
	gatto.print();
	
	
	cout << endl << endl; 
	
	Cane cane = Cane(10, "rosso");
	cane.nome = "Fuffi";
	cane.setSesso("Maschile");
	cane.print();
	cane.seduto();
	cane.abbaia();
}
