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

template <class H> class Queue{
	
	private:
		Node<H> *front, *rear;

	public:
		Queue(){
			front=rear=0;
		}

		Queue<H>* enqueue(H x){
			if(!front){
				front=new Node<H>(x, front);
				rear=front;
				return this;
			}

			Node<H>* aux=new Node<H>(x);
			rear->setNext(aux);
			rear=aux;
			return this;
		}

		Queue<H>* dequeue(){
			if(!front){
				cout<<"Queue is Empty"<<endl;
				return this;
			}

			Node<H>* aux=front;
			front=front->getNext();
			delete aux;
			return this;
		}

		void print(){
			Node<H>* aux=front;
			while(aux){
				cout<<aux->getKey()<<" ";
				aux=aux->getNext();
			}
			cout<<endl;
		}

		void clear(){
			front=0;
			rear=0;
		}
};

int main(){
	Queue<int>* q=new Queue<int>();
	q->print();
	q->dequeue();
	q->enqueue(10)->enqueue(1)->enqueue(5)->enqueue(8)->enqueue(4)->print();
	q->dequeue()->dequeue()->dequeue()->dequeue()->dequeue()->enqueue(11)->print();
	q->clear();
	q->print();
}