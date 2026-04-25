#include <iostream>
#define DIM 100

using namespace std;


template <class H> class Queue{
	
	private:
		int n;
		H *v;
		int front, rear;

		bool _isFull(){
			return n==DIM ? true : false;
		}

		bool _isEmpty(){
			return n==0 ? true : false;
		}

	public:
		Queue(){
			v=new H(DIM);
			n=0;
			front=rear=0;
		}

		int getN() const{
			return n;
		}

		Queue<H>* enqueue(H x){
			if(!_isFull()){
				v[rear]=x;
				rear=(rear+1)%DIM;
				n++;
				return this;
			}
			cout<<"Queue Overflow"<<endl;
			return this;
		}

		Queue<H>* dequeue(){
			if(!_isEmpty()){
				front=(front+1)%DIM;
				n--;
				return this;
			}
			cout<<"Queue Underflow"<<endl;
			return this;
		}

		void print(){
			if(!_isEmpty()){
                int i=front;
                while(i!=rear){
					cout<<v[i]<<" ";
				    i=(i+1)%DIM;
                }
			}
			cout<<endl;
		}

		void clear(){
			front=0;
			rear=0;
			n=0;
		}
};

int main(){

	Queue<int>* q=new Queue<int>();
	q->enqueue(2)->enqueue(3)->enqueue(12)->enqueue(4)->enqueue(9)->enqueue(5);
	q->dequeue()->dequeue();
	q->print();
	q->enqueue(2)->enqueue(3);
	q->print();

	q->enqueue(5)->enqueue(8)->enqueue(10)->enqueue(4)->enqueue(9)->enqueue(3)->print();
	q->dequeue()->dequeue()->dequeue()->enqueue(8)->enqueue(10)->enqueue(11)->dequeue()->dequeue()->enqueue(20)->dequeue()->print();
	cout<<q->getN()<<endl;
	q->clear();
	q->print();
}