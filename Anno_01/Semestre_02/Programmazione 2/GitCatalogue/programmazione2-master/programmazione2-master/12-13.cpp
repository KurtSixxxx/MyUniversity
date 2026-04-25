
/*

CODE (o QUEUE)
Una coda è un'organizzazione dati in cui il dato che arriva per primo viene servito
per primo (fila alle poste ad esempio).Questa caratteristica è comunemente detta "First in, First out" (FIFO).
->Quando inseriamo un elemento nella coda facciamo un operazione di ENQUEUE 
->Quando togliamo un elemento dalla coda facciamo un operazione di DEQUEUE

Le code possono essere implementate in varie modo, tra le alternative:
1) Array -> ENQUEUE avrà complessità O(1). DEQUEUE O(1) per l'estrazione e O(n) per lo shift successivo ce dovrà essereci per mantenere consistenza  
2) List -> ENQUEUE avraà complessità O(n) devo scorrere tutta la lista infatti. DEQUEUE O(1) perchè è l'estrazione della testa
3) ListDL -> ENQUEUE avrà complessità O(1) se ha tail, O(n) altrimenti. DEQUEUE O(1) per lo stesso motivo della List

In base alla struttura dati che scegliamo per implementare la lista, cambierà la complessità del nostro algoritmo
L'algoritmo più efficiente lo otteniamo con una ListDL, ma vedremo che ottimizzando alcune procedure, riusciamo ad ottenere buoni risultati anche con gli array

Esempio
Supponiamo adesso di avere un array di lunghezza 

--------------------------------------------------------------------------------------------------------------------------------------------------------------

PILE (o STACK)
Le pile sono strutture dati in cui il primo dato che è arrivato, viene processato per ultimo.
Un esempio di pila potrebbe essere un autobus, il primo che  sale scende per ultimo.
La pila segue cioè l'organizzazione Last in first out (LIFO). Nelle pile abbiamo due possibili azioni:
->Aggiungo un elemento in cima alla pila. (PUSH)
->Estraggo un elemento sempre dalla cima. (POP) 

L'elemento in cima alla lista si chiama top. Come per code anche le pile possono essere implementate in maniere differenti.
1) Array -> PUSH avrà complessità O(1). POP avrà complessità O(1)
2) List -> PUSH avrà complessità O(1). POP avrà complessità O(1)
3) ListDL -> PUSH avrà complessità O(1). POP avrà complessità O(1)
Sia il POP che il PUSH avrà sempre tempo costante a prescindere dall'implementazione
*/

#include <iostream>
using namespace std;

template <class T>
class Queue{
	int head, tail = -1;
	int nElements = 0;
	int length;
	T* queue;

	public:
		Queue(int length): length(length) {
			queue = new T[length];
		}
		Queue() : Queue(5) {}

		void enqueue(T value){
			if(isFull()){
				return;
			}
			if(isEmpty()){
				head = 0;
			}
			tail = ((tail+1) % length); //inserisco questo perchè devo prendere in considerazione l'eventualità in cui la coda sia piena, questa condizione di accesso funziona bene in tutti i casi, sia in una coda piena che in una coda vuota o semi vuota
			this->queue[tail] = value; 
			nElements++;
		}
		bool dequeue(){
			if(isEmpty()) return false;
			head = (head+1) % length;
			nElements--;
			return true;
		}
		bool isFull(){
			if((head - (tail+1)) % length == 0) return true;
			return false;
		}
		bool isEmpty(){
			if(nElements == 0) return true;
			return false;
		}
		int getLength() const{
			return length;
		}
		friend ostream& operator << (ostream& stream, const Queue& queue){
			for(int i=0; i<queue.length; i++){
				stream << queue.queue[i] <<  ((i==queue.head) ? " <-- head" : (i == queue.tail) ? " <-- tail" : " ") << endl;
			}
			return stream;
		}


};


int main(){
	Queue<int> queue;

	for(int i=1; i<queue.getLength()+1; i++){
		queue.enqueue(i);
		cout << queue << endl;
		cout << ".............................." << endl << endl;
	}

	queue.dequeue();
	cout << queue << endl;

	cout << ".............................." << endl << endl;

	queue.enqueue(11);
	cout << queue << endl;

	cout << ".............................." << endl << endl;

	queue.dequeue();
	cout << queue << endl;

	return 0;
}