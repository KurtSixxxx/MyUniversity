#include <iostream>

using namespace std;

template <class H> class Node{
	
	private:
		H key;
		Node<H> *next;

	public:
		Node(H k, Node<H> *n=0) : key(k), next(n) {}

		void setKey(H k){
			key=k;
		}

		void setNext(Node<H> *n){
			next=n;
		}

		H getKey() const{
			return key;
		}

		Node<H>* getNext() const{
			return next;
		}
};


template <class H> class CircularList{
	
	private:
		Node<H> *head, *tail;

	public:
		CircularList(){
			head=tail=0;
		}

		CircularList<H>* ins(H x){
			if(!head){
				head=new Node<H>(x);
				tail=head;
				return this;
			}

			//inserimento in testa
			if(x < head->getKey()){
				head=new Node<H>(x, head);
				tail->setNext(head);
				return this;
			}

			//inserimento in coda
			if(x > tail->getKey()){
				Node<H>* aux=new Node<H>(x, head);
				tail->setNext(aux);
				tail=aux;
				return this;
			}

			//inserimento standard
			Node<H>* back=head;
			Node<H>* forward=head->getNext();
			while(forward && x>=forward->getKey()){
				back=forward;
				forward=forward->getNext();
			}
			if(forward){
				Node<H>* aux=new Node<H>(x, forward);
				back->setNext(aux);
			}
			return this;
		}

		CircularList<H>* del(H x){
			if(!head){
				return this;
			}

			//eliminazione in testa
			if(x==head->getKey()){
				Node<H>* aux=head;
				head=aux->getNext();
				if(head){
					if(tail!=head) tail->setNext(head);
					else tail->setNext(0);
				}
				else tail=head=0;
				delete aux;
				return this;
			}

			//eliminazione standard e in coda
			Node<H>* back=head;
			Node<H>* forward=head->getNext();
			do{
				if(x == forward->getKey()){
					back->setNext(forward->getNext());
					if(forward==tail){
						tail=back;
						if(tail==head) tail->setNext(0);
					}
					delete forward;
					return this;
				}
				back=forward;
				forward=forward->getNext();
			}
			while(forward!=head && x >= forward->getKey());
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

	CircularList<int>* l=new CircularList<int>();
	l->ins(100)->ins(99)->print();
	l->del(100);//->del(99);
	l->print();
	/*l->ins(10)->ins(5)->ins(12)->ins(7)->ins(2)->ins(3);
	l->print();
	l->del(2)->del(12)->del(7)->del(9)->ins(9)->ins(15);
	l->print();
	l->del(100);*/
}