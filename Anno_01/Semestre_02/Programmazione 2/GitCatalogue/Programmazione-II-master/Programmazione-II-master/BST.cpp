#include <iostream>

using namespace std;

template <class H> class Node{
	
	private:
		H key;
		Node<H> *parent, *left, *right;

	public:
		Node(H k, Node<H> *p=0, Node<H> *l=0, Node<H> *r=0) : key(k), parent(p), left(l), right(r) {}

		void setKey(H k){
			key=k;
		}

		void setParent(Node<H>* p){
			parent=p;
		}

		void setLeft(Node<H>* l){
			left=l;
		}

		void setRight(Node<H>* r){
			right=r;
		}

		H getKey() const{
			return key;
		}

		Node<H>* getParent() const{
			return parent;
		}

		Node<H>* getLeft() const{
			return left;
		}

		Node<H>* getRight() const{
			return right;
		}

		bool isLeaf() const{
			return !left && !right;
		}
};

template <class H> class BST{
	
	private:
		Node<H> *root, *counter;

		void _inOrder(Node<H>* aux){
			if(aux){
				_inOrder(aux->getLeft());
				cout<<aux->getKey()<<" ";
				_inOrder(aux->getRight());
			}
		}

		void _preOrder(Node<H>* aux){
			if(aux){
				cout<<aux->getKey()<<" ";
				_preOrder(aux->getLeft());
				_preOrder(aux->getRight());
			}
		}

		void _postOrder(Node<H>* aux){
			if(aux){
				_postOrder(aux->getLeft());
				_postOrder(aux->getRight());
				cout<<aux->getKey()<<" ";
			}
		}

		Node<H>* _search(H x){
			Node<H>* aux=root;
			while(aux){
				if(x < aux->getKey()){
					aux=aux->getLeft();
				}
				else if(x > aux->getKey()){
					aux=aux->getRight();
				}
				else{
					return aux;
				}
			}
			return 0;
		}

		Node<H>* _minimum(Node<H>* aux){
			while(aux && aux->getLeft()){
				aux=aux->getLeft();
			}
			return aux;
		}

		Node<H>* _maximum(Node<H>* aux){
			while(aux && aux->getRight()){
				aux=aux->getRight();
			}
			return aux;
		}

		void _del(Node<H>* aux){
			if(aux){

				//case 1: the node is a leaf
				if(aux->isLeaf()){
					Node<H>* parent=aux->getParent();

					//if it is root
					if(!parent){
						root=0;
					}
					else{
						if(parent->getLeft() == aux){
							parent->setLeft(0);
						}
						else{
							parent->setRight(0);
						}
					}
					delete aux;
				}

				//case 2: the node has one son
				else if(aux->getLeft()==0 ^ aux->getRight()==0){
					Node<H>* son;
					if(aux->getLeft()){
						son=aux->getLeft();
					}
					else{
						son=aux->getRight();
					}
					Node<H>* parent=aux->getParent();

					//if it is root
					if(!parent){
						root=son;
					}
					else{
						if(parent->getLeft() == aux){
							parent->setLeft(son);
						}
						else{
							parent->setRight(son);
						}
						son->setParent(parent);
					}
					delete aux;
				}

				//case 3: the node has two sons
				else{
					Node<H>* min=_minimum(aux->getRight());
					aux->setKey(min->getKey());
					_del(min);
				}
			}
		}

		Node<H>* _successor(Node<H>* aux){
			if(!aux){
				return 0;
			}

			if(aux->getRight()){
				return _minimum(aux->getRight());
			}

			Node<H>* parent=aux->getParent();
			while(parent && parent->getRight() && parent->getRight()==aux){
				aux=parent;
				parent=parent->getParent();
			}
			return parent;
		}

		Node<H>* _predecessor(Node<H>* aux){
			if(!aux){
				return 0;
			}

			if(aux->getLeft()){
				return _maximum(aux->getLeft());
			}

			Node<H>* parent=aux->getParent();
			while(parent && parent->getLeft() && parent->getLeft()==aux){
				aux=parent;
				parent=parent->getParent();
			}
			return parent;
		}

		int _height(Node<H>* aux){
			if(!aux){
				return -1;
			}

			int h1=_height(aux->getLeft());
			int h2=_height(aux->getRight());

			return (h1 > h2 ? h1 : h2)+1;
		}

	public:
		BST(){
			root=0;
			counter=0;
		}

		H* begin(){
			counter=_minimum(root);
			return counter ? new H(counter->getKey()) : 0;
		}

		H* next(){
			counter=_successor(counter);
			return counter ? new H(counter->getKey()) : 0;
		}

		bool hasNext(){
			return _successor(counter) ? true : false;
		}

		BST<H>* ins(H x){
			if(!root){
				root=new Node<H>(x);
				return this;
			}

			Node<H>* aux=root;
			while(true){
				if(x < aux->getKey()){
					if(!aux->getLeft()){
						Node<H>* current=new Node<H>(x, aux);
						aux->setLeft(current);
						return this;
					}
					else{
						aux=aux->getLeft();
					}
				}
				else{
					if(!aux->getRight()){
						Node<H>* current=new Node<H>(x, aux);
						aux->setRight(current);
						return this;
					}
					else{
						aux=aux->getRight();
					}
				}
			}
		}

		void inOrder(){
			_inOrder(root);
			cout<<endl;
		}

		void preOrder(){
			_preOrder(root);
			cout<<endl;
		}

		void postOrder(){
			_postOrder(root);
			cout<<endl;
		}

		H* search(H x){
			Node<H>* aux=_search(x);
			return aux ? new H(aux->getKey()) : 0;
		}

		H* minimum(){
			Node<H>* aux=_minimum(root);
			return aux ? new H(aux->getKey()) : 0;
		}

		H* maximum(){
			Node<H>* aux=_maximum(root);
			return aux ? new H(aux->getKey()) : 0;
		}

		BST<H>* del(H x){
			_del(_search(x));
			return this;
		}

		H* successor(H x){
			Node<H>* aux=_successor(_search(x));
			return aux ? new H(aux->getKey()) : 0;
		}

		H* predecessor(H x){
			Node<H>* aux=_predecessor(_search(x));
			return aux ? new H(aux->getKey()) : 0;
		}

		int height(){
			return _height(root);
		}

		int deep(H x){
			Node<H>* aux=_search(x);
			if(!aux){
				return -1;
			}

			int count=0;
			while(aux){
				aux=aux->getParent();
				count++;
			}

			return count;
		}

		void delAll(H x){
			Node<H>* aux=_search(x);
			while(aux){
				_del(aux);
				aux=_search(x);
			}
		}

		friend BST<H> operator + (const BST<H> &t, H x){
			BST<H> nt=t;
			nt.ins(x);
			return nt;
		}

		friend BST<H> operator + (const BST<H> &t1, const BST<H> &t2){
			BST<H> nt=t1;
			BST<H> t3=t2;

			H *e=t3.begin();
			while(e){
				nt=nt+*e;
				e=t3.next();
			}
			return nt;
		}

		friend BST<H> operator - (const BST<H> &t, H x){
			BST<H> nt=t;
			nt.del(x);
			return nt;
		}

};

int main(){

	BST<int>* b=new BST<int>();
	cout<<"Minimo: "<<b->minimum()<<endl;
	cout<<"Massimo: "<<b->maximum()<<endl;
	b->ins(12)->ins(5)->ins(14)->ins(7)->ins(2)->ins(20)->ins(13);
	b->inOrder();
	b->preOrder();
	b->postOrder();
	cout<<*b->search(5)<<endl;
	cout<<b->search(19)<<endl;
	cout<<"Minimo: "<<*b->minimum()<<endl;
	cout<<"Massimo: "<<*b->maximum()<<endl;
	b->del(12)->del(2)->del(14)->del(21)->ins(21);
	b->ins(8)->ins(1)->ins(22);
	b->inOrder();
	cout<<*b->successor(8)<<endl;
	cout<<*b->predecessor(8)<<endl;
	cout<<b->successor(23)<<endl;
	cout<<b->predecessor(23)<<endl;
	cout<<"Altezza albero: "<<b->height()<<endl;
	cout<<"Altezza nodo: "<<b->deep(10)<<endl;
	b->ins(7)->ins(7);
	b->delAll(7);
	b->inOrder();
	*b+17;
	*b-8;
	b->inOrder();

	int *e=b->begin();
	while(e){
		cout<<*e<<" ";
		e=b->next();
	}
	cout<<endl;

	BST<int>* t=new BST<int>();
	t->ins(5)->ins(54)->ins(2)->ins(8)->ins(1);
	*t+7;
	*t+1;
	*t-5;
	e=t->begin();
	while(e){
		cout<<*e<<" ";
		e=t->next();
	}
	cout<<endl;

	*b=*b+*t;
	b->inOrder();
}