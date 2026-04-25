#include <iostream>
using namespace std;


template <class T>
class Node{
    Node* next;
    T value;
    
    public:
        Node(T value, Node<T> * next) : value(value), next(next) {}
        Node(T value) : Node(value, NULL) {}
        
        T getValue() const {
            return this->value;
        }
        Node* getNext() const{
            return this->next;
        }
        void setNext(Node* newNode){
            this->next = newNode;
            return;
        }
        friend ostream& operator<< (ostream& stream, const Node& node){
            stream << "Prossimo nodo =  " << node.next << ", di valore = " << node.getValue();
            return stream;
        }
};


template <class T>
class List{
    Node<T>* head;
    int length;
    bool isAscending = true;
    
    public:
        List(Node<T>* head, int length, bool isAscending) : head(head), length(length), isAscending(isAscending){}
        List(bool isAscending) : List(NULL, 0, isAscending){}
        List() : List(NULL, 0, true){}
        void setAscending(bool isAscending){
        	this->isAscending = isAscending;
        	return;
        }
        void add(T value){            
            Node<T> * temp = new Node<T>(value);
            this->add(temp);
        }
        void add(Node<T>* newNode){
            if(head == NULL){
                head = newNode;
                length++;
                return;
            }
            Node<T>* currentNode = head;
            while(currentNode->getNext() != NULL){
                currentNode = currentNode->getNext();
            }
            currentNode->setNext(newNode);
            length++;
            return;
        }
		void addInOrder(T value) {
			Node<T> * newNode = new Node<T>(value);
			if(head == NULL) {
				add(newNode);
				return;
			}
			if(this->isAscending){
				if(head->getValue() > value){
					newNode->setNext(head);
					head = newNode;
					length++;
					return;
				}
			}
			else{
				if(head->getValue() < value){
					newNode->setNext(head);
					head = newNode;
					length++;
					return;
				}
			}
			Node<T> * prevNode = head;
			Node<T>	* currentNode = head->getNext();
			while(currentNode != NULL) {
				if(this->isAscending){
					if(prevNode->getValue() <= value && currentNode->getValue() > value) {
						prevNode->setNext(newNode);
						newNode->setNext(currentNode);
						length++;
						return;
					}
					else{
						prevNode = currentNode; 
						currentNode = currentNode->getNext();					
					}
				}
				else {
					if(prevNode->getValue() > value && currentNode->getValue() <= value) {
						prevNode->setNext(newNode);
						newNode->setNext(currentNode);
						length++;
						return;
					}
					else{
						prevNode = currentNode; 
						currentNode = currentNode->getNext();					
					}
				}
			}
			prevNode->setNext(newNode);
			length++;
			return;
		}
        bool search(T value){
            if(head == NULL) return false;
            Node<T>* currentNode = head;
            while(currentNode != NULL){
            	if(currentNode->getValue() == value){
            		return true;
            	}
            	currentNode = currentNode->getNext();
            }
            return false;
        }
        void remove(T value) {
            if(this->search(value) == true){ // Se il valore è presente nella lista
            	if(head->getValue() == value){
            		head == head->getNext();
            		length--;
            		return;
            	}
                Node<T>* prevNode = head;
                Node<T>* currentNode = head->getNext();
				while(currentNode != NULL){
					if(currentNode->getValue() == value){
					    prevNode->setNext(currentNode->getNext());
					    length--;
					    return;
					}
					prevNode = currentNode; //faccio scorrere entrambi
					currentNode = currentNode->getNext();
				}
            }
            return;
        }
        friend ostream& operator<< (ostream& stream, const List& list){
            Node<T>* currentNode = list.head;
            stream << "[  ";
            while(currentNode != NULL){
                stream << currentNode->getValue() << endl;
                currentNode = currentNode->getNext();
            }
            stream << "]";
            return stream;
        }
};