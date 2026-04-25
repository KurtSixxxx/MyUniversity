#include <iostream>

using namespace std;

template <class H> class Node{
	
	private:
		H key;
		Node<H> *next, *prev;

	public:
		Node(H k, Node<H> *n=0, Node<H> *p=0) : key(k), next(n), prev(p) {}

		void setKey(H k){
			key=k;
		}

		void setNext(Node<H>* n){
			next=n;
		}

		void setPrev(Node<H> *p){
			prev=p;
		}

		H getKey() const{
			return key;
		}

		Node<H>* getNext() const{
			return next;
		}

		Node<H>* getPrev() const{
			return prev;
		}
};

template <class H> class DoubleList{
	
	private:
		Node<H> *head, *tail;

		Node<H>* _search(H x){
			Node<H>* aux=head;
			while(aux && x >= aux->getKey()){
				if(x == aux->getKey()){
					return aux;
				}
				aux=aux->getNext();
			}
			return 0;
		}

	public:
		DoubleList(){
			head=tail=0;
		}

		DoubleList<H>* ins(H x){
			Node<H>* aux=new Node<H>(x);
			
			//lista vuota
			if(!head){
				head=aux;
				tail=head;
				return this;
			}

			//inserimento in testa
			if(x < head->getKey()){
				aux->setNext(head);
				head->setPrev(aux);
				head=aux;
				return this;
			}

			//inserimento in coda
			if(x > tail->getKey()){
				aux->setPrev(tail);
				tail->setNext(aux);
				tail=aux;
				return this;
			}

			//inserimento standard
			Node<H>* current=head;
			while(current && x > current->getKey()){
				current=current->getNext();
			}
			if(current){
				aux->setNext(current);
				current->getPrev()->setNext(aux);
				aux->setPrev(current->getPrev());
				current->setPrev(aux);
			}
			return this;
		}

		H* search(H x){
			Node<H>* aux=_search(x);
			return aux ? new H(aux->getKey()) : 0;
		}

		DoubleList<H>* del(H x){
			Node<H>* aux=_search(x);

			if(!aux){
				return this;
			}

			//cancellazione in testa
			if(aux == head){
				head=head->getNext();
				if(head) head->setPrev(0);
				delete aux;
				return this;
			}

			//cancellazione in coda
			if(aux == tail){
				tail=tail->getPrev();
				tail->setNext(0);
				delete aux;
				return this;
			}

			//cancellazione standard
			aux->getPrev()->setNext(aux->getNext());
			aux->getNext()->setPrev(aux->getPrev());
			delete aux;
			return this;
		}

		void print(){
			Node<H>* aux=head;
			while(aux){
				cout<<aux->getKey()<<" ";
				aux=aux->getNext();
			}
			cout<<endl;
		}


};


int main(){
	DoubleList<int>* l=new DoubleList<int>();
	l->ins(100)->ins(99)->print();
	l->del(99)->del(100);
	//l->del(100);
	l->print();
	/*l->ins(6)->ins(8)->ins(1)->ins(3)->ins(5)->ins(10)->ins(9)->print();
	cout<<*l->search(8)<<endl;
	cout<<l->search(11)<<endl;
	l->del(6)->del(1)->del(10)->del(6)->ins(7)->print();*/
}