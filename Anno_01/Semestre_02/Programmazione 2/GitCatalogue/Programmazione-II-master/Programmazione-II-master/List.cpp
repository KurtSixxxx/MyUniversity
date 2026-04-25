#include <iostream>

using namespace std;


template <class H> class Node{
	
	private:
		H key;
		Node<H>* next;

	public:
		Node(H k, Node<H>* n=0){
			key=k;
			next=n;
		}

		void setKey(H k){
			key=k;
		}

		void setNext(Node<H>* n){
			next=n;
		}

		H getKey() const{
			return key;
		}

		Node<H>* getNext() const{
			return next;
		}
};


template <class H> class List{
	
	private:
		Node<H> *head, *tail;
		int n;

		void _recPrint(Node<H>* aux){
			if(!aux){
				return;
			}
			cout<<aux->getKey()<<" ";
			_recPrint(aux->getNext());
		}

		void _RevRecPrint(Node<H>* aux){
			if(!aux){
				return;
			}
			_RevRecPrint(aux->getNext());
			cout<<aux->getKey()<<" ";
		}

	public:
		List(){
			head=tail=0;
			n=0;
		}

		int getN() const{
			return n;
		}

		List<H>* insHead(H val){
			head=new Node<H>(val, head);
			if(!tail){
				tail=head;
			}
			n++;
			return this;
		}

		List<H>* insTail(H val){
			Node<H>* back=0;
			Node<H>* forward=head;
			while(forward){
				back=forward;
				forward=forward->getNext();
			}
			Node<H>* aux=new Node<H>(val);
			if(back){
				back->setNext(aux);
			}
			else{
				head=aux;
			}
			tail=aux;
			n++;
			return this;
		}

		List<H>* insAt(H val, int pos){
			if(pos==0){
				insHead(val);
				return this;
			}

			if(pos==(n-1)){
				insTail(val);
				return this;
			}

			Node<H>* back=0;
			Node<H>* forward=head;
			for(int i=0; i<pos && forward; i++){
				back=forward;
				forward=forward->getNext();
			}
			if(forward){
				Node<H>* aux=new Node<H>(val, forward);
				back->setNext(aux);
				n++;
			}
			return this;
			
		}

		List<H>* del(H x){
			
			if(!head){
				return this;
			}

			Node<H>* aux=head;

			//cancellazione in testa
			if(x == head->getKey()){
				head=head->getNext();
				delete aux;
				n--;
				return this;
			}

			//cancellazione standard e in coda
			Node<H>* forward=head->getNext();
			while(forward){
				if(x == forward->getKey()){
					aux->setNext(forward->getNext());
					if(x == tail->getKey()){
						tail=aux;
					}
					delete forward;
					n--;
					return this;
				}
				aux=forward;
				forward=forward->getNext();
			}
			return this;
		}

		List<H>* delAt(int pos){
			if(!head){
				return this;
			}

			Node<H>* back=head;

			//cancellazione in testa
			if(pos==0){
				head=head->getNext();
				delete back;
				n--;
				return this;
			}

			//cancellazione standard e in coda
			Node<H>* forward=head->getNext();
			for(int i=1; i<pos && forward; i++){
				back=forward;
				forward=forward->getNext();
			}
			if(forward){
				back->setNext(forward->getNext());
				if(pos == (n-1)){
					tail=back;
				}
				delete forward;
				n--;
				return this;
			}
			return this;
		}

		List<H>* print(){
			Node<H>* aux=head;
			while(aux){
				cout<<aux->getKey()<<" ";
				aux=aux->getNext();
			}
			cout<<endl;
			return this;
		}

		void recPrint(){
			_recPrint(head);
			cout<<endl;
		}

		void RevRecPrint(){
			_RevRecPrint(head);
			cout<<endl;
		}

};



int main(){

	List<int>* l=new List<int>();
	l->print();
	l->recPrint();
	l->RevRecPrint();
	l->del(8)->print();
	l->insAt(15, 5)->print();
	l->insTail(2)->insTail(3)->insTail(4)->print();
	l->insHead(8)->insHead(9)->insHead(10)->print();
	l->insAt(1, 0)->insAt(0, 6)->insAt(5, 3)->insAt(7, 2)->insAt(15, 20)->print();
	l->del(1)->del(0)->del(5)->del(9)->del(12)->print();
	l->delAt(0)->delAt(4)->delAt(8)->insTail(9)->print();
	l->recPrint();
	l->RevRecPrint();
}