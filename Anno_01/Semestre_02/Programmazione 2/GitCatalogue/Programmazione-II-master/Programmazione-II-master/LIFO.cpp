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


template <class H> class Stack{
	
	private:
		Node<H> *pointer;

	public:
		Stack(){
			pointer=0;
		}

		~Stack(){
			Node<H>* aux=pointer;
			while(pointer){
				aux=pointer;
				pointer=pointer->getNext();
				delete aux;
			}
		}

		Stack<H>* push(H x){
			pointer=new Node<H>(x, pointer);
			return this;
		}

		Stack<H>* pop(){
			if(!pointer){
				cout<<"Stack is Empty"<<endl;
				return this;
			}

			Node<H>* aux=pointer;
			pointer=pointer->getNext();
			delete aux;
			return this;
		}

		void print(){
			Node<H>* aux=pointer;
			while(aux){
				cout<<aux->getKey()<<" ";
				aux=aux->getNext();
			}
			cout<<endl;
		}

		void clear(){
			pointer=0;
		}
};

int main(){
	Stack<int>* s=new Stack<int>();
	s->push(8)->push(10)->push(3)->push(5)->push(4)->print();
	s->pop()->pop()->pop()->pop()->pop()->push(47)->print();
	s->clear();
	s->print();
	delete s;
}