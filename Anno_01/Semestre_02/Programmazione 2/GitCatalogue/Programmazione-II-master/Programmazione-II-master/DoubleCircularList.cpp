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

		void setNext(Node<H> *n){
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

template <class H> class DoubleCL{
	
	private:
		Node<H> *head, *tail;

		Node<H>* _search(H x){
			if(!head){
				return 0;
			}

			Node<H>* aux=head;
			do{
				if(x == aux->getKey()){
					return aux;
				}
				aux=aux->getNext();
			}
			while(aux!=head && aux && x >= aux->getKey());
			return 0;
		}

	public:
		DoubleCL(){
			head=tail=0;
		}

		DoubleCL<H>* ins(H x){
			if(!head){
				head=new Node<H>(x);
				tail=head;
				return this;
			}

			//inserimento in testa
			if(x < head->getKey()){
				Node<H>* aux=new Node<H>(x, head, tail);
				tail->setNext(aux);
				head->setPrev(aux);
				head=aux;
				return this;
			}

			//inserimento in coda
			if(x > tail->getKey()){
				Node<H>* aux=new Node<H>(x, head, tail);
				head->setPrev(aux);
				tail->setNext(aux);
				tail=aux;
				return this;
			}

			//inserimento standard
			Node<H>* current=head->getNext();
			while(current && x >= current->getKey()){
				current=current->getNext();
			}
			if(current){
				Node<H>* aux=new Node<H>(x, current, current->getPrev());
				aux->getPrev()->setNext(aux);
				current->setPrev(aux);
			}
			return this;
		}

		DoubleCL<H>* del(H x){
			Node<H>* aux=_search(x);

			if(!aux){
				return this;
			}

			//eliminazione in testa
			if(aux==head){
				if(!head->getNext()){
					head=0;
					tail=0;
					delete aux;
					return this;
				}
				if(aux->getNext()==tail){
					head=tail;
					head->setNext(0);
					head->setPrev(0);
					delete aux;
					return this;
				}
				head=head->getNext();
				tail->setNext(head);
				head->setPrev(tail);
				delete aux;
				return this;
			}

			//eliminazione in coda
			if(aux==tail){
				if(aux->getPrev()==head){
					tail=head;
					head->setNext(0);
					head->setPrev(0);
					delete aux;
					return this;
				}
				tail=tail->getPrev();
				tail->setNext(head);
				head->setPrev(tail);
				delete aux;
				return this;
			}

			
			//standard
			Node<H>* back=aux->getPrev();
			Node<H>* forward=aux->getNext();
			back->setNext(forward);
			forward->setPrev(back);
			delete aux;
			return this;

		}

		void print(){
			if(head){
				Node<H>* aux=head;
				do{
					cout<<aux->getKey()<<" ";
					aux=aux->getNext();
				}
				while(aux && aux!=head);
			}
			cout<<endl;
		}
};


int main(){
	DoubleCL<int>* l=new DoubleCL<int>();
	l->ins(100)->ins(99)->print();
	l->del(100)->del(99)->print();
	l->ins(8)->ins(10)->ins(5)->ins(6)->ins(7)->ins(13);
	l->print();
	l->del(8)->del(13)->del(5)->del(7)->del(6)->del(11)->ins(11)->ins(9)->ins(1)->del(10);
	l->print();
	cout<<"ok";
}