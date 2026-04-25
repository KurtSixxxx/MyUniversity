#include <iostream>
#define DIM 50

using namespace std;


template <class H> class Stack{
	
	private:
		H *v;
		int n;

		bool _isFull(){
			return n==DIM ? true : false;
		}

		bool _isEmpty(){
			return n==0 ? true : false;
		}

	public:
		Stack(){
			v=new H(DIM);
			n=0;
		}

		int getN() const{
			return n;
		}

		Stack<H>* push(H x){
			if(!_isFull()){
				v[DIM-1-n]=x;
				n++;
				return this;
			}
			cout<<"Stack Overflow"<<endl;
			return this;
		}

		Stack<H>* pop(){
			if(!_isEmpty()){
				n--;
				return this;
			}

			cout<<"Stack Underflow"<<endl;
			return this;
		}

		void print(){
			if(!_isEmpty()){
				for(int i=DIM-n; i<DIM; i++){
					cout<<v[i]<<" ";
				}
			}
			cout<<endl;
		}

		void clear(){
			n=0;
		}
};



int main(){
	Stack<int>* s=new Stack<int>();
	s->print();
	s->pop();
	s->push(5)->push(10)->push(8)->push(14)->push(1)->push(4)->print();
	cout<<s->getN()<<endl;
	s->pop()->pop()->pop()->push(3)->pop()->push(7)->pop()->pop()->pop()->pop()->print();
	cout<<s->getN()<<endl;
	s->push(8)->push(9)->push(1)->push(34)->push(4)->push(3)->print();
	s->clear();
	s->print();
}