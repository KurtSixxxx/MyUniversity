#include<iostream>
using namespace std;


template <class T>
class NodeDl{
	NodeDl<T>* prev;
	NodeDl<T>* next;
	T value;
	
	public:
		NodeDl(NodeDl<T>* prev, NodeDl<T>* next, T value) : prev(prev), next(next), value(value){}
		NodeDl(T value) : NodeDl(NULL, NULL, value){}
		NodeDl() : NodeDl(NULL, NULL, 0){}
	
		void setNext(NodeDl<T>* newNext){
			this->next = newNext;
		}
		void setPrev(NodeDl<T>* newPrev){
			this->prev = newPrev;
		}
		NodeDl<T>* getNext() const{
			return this->next;
		}
		NodeDl<T>* getPrev() const{
			return this->prev;
		}
		T getValue() const{
			return this->value;
		}
		friend ostream& operator << (ostream& stream, const NodeDl& n){
			stream << n.getValue();
			return stream;
		}
};

template <class T>
class ListDl{
	NodeDl<T>* head;
	NodeDl<T>* tail;

	public:
		ListDl(NodeDl<T>* head, NodeDl<T>* tail) : head(head), tail(tail){}
		ListDl() : ListDl(NULL, NULL){}
		

		void addHead(T value){
			NodeDl<T>* newNode = new NodeDl<T>(value);
			if(head == NULL && tail == NULL){
				 this->head = newNode;
				 this->tail = newNode;
			}
			else{
				newNode->setNext(head);
				head->setPrev(newNode);
				head = newNode;
			}
		}
		void addTail(T value){
			NodeDl<T>* newNode = new NodeDl<T>(value);
			if(head == NULL && tail == NULL){
				 this->head = newNode;
				 this->tail = newNode;
			}
			else{
				newNode->setPrev(tail);
				tail->setNext(newNode);
				tail = newNode;
			}
		}
		void add(T value){
			NodeDl<T>* newNode = new NodeDl<T>(value);
			if(head == NULL && tail == NULL){
				addHead(value);
				return;	
			}
			if(tail->getValue() <= value){
				addTail(value);
				return;
			}
			if(head->getValue() > value){
				addHead(value);
				return;
			}
			NodeDl<T>* currentNode = head;
			NodeDl<T>* prevNode = head->getPrev();
			while(currentNode->getValue() <= value){
				prevNode = currentNode;
				prevNode = currentNode->getPrev();
			}
			newNode->setPrev(prevNode);
			newNode->setNext(currentNode);
			prevNode->setNext(newNode);
			currentNode->setPrev(newNode);
		}
		bool search(T value){
			NodeDl<T>*  currentNode = head;
			while(currentNode != NULL){
				if(currentNode->getValue() == value) return true;
				currentNode = currentNode->getNext();
			}
			return false;
		}
		void remove(T value){
			if(search(value)){
				if(value == head->getValue()){ //Se il valore da togliere è la testa
					head = head->getNext();
					return;
				}
				if(value == head->getValue()){ //Se il valore da togliere è la coda
					tail = tail->getPrev();
					return;
				}
				//Se il valore da togliere non è ne in testa ne in coda ma è un nodo al centro
				NodeDl<T>* currentNode = head;
				NodeDl<T>* prevNode = head;
				while(currentNode->getValue() != value) {
					prevNode = currentNode;
					currentNode = currentNode->getNext();
				}
				prevNode->setNext(currentNode->getNext());
				currentNode->getNext()->setPrev(prevNode);
			}
			return;
		}
		friend ostream& operator << (ostream& stream, const ListDl& l){
			NodeDl<T>* currentNode = l.head;
			while(currentNode != NULL){
				stream << *currentNode << " ";
				currentNode = currentNode->getNext();
			}
			return stream;
		}

};


int main(){
	ListDl<int> l;
	for(int i=0; i<5; i++){
		l.add(i);
	}
	l.remove(2);
	cout << l << endl;
}