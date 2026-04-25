#include <iostream>
using namespace std;

template <class T>
class Stack{
	int top = -1;
	int length;
	T *stack;
	
	public:
		Stack(int length) : length(length){
			stack = new T[length];
		}
		Stack() : Stack(5){}

		void push(T value){
			if(isFull()) return;
			stack[++top] = value; //prima incremento e poi inserisco
		}
		T pop(){
			if(isEmpty()) return 0;
			return stack[top--]; //prima ritorno e dopo decremento
		}
		bool isEmpty(){
			return top == -1;
		}
		bool isFull(){
			return top == length-1;
		}
		T getTop() const {
			return stack[top];
		}
		int getLength() const {
			return length;
		}
		friend ostream& operator << (ostream& stream, const Stack& s){
			for(int i=s.top; i >= 0; i--) stream << s.stack[i] << endl;
			return stream;
		}
};

int main(){
	Stack<int> stack;
	
	
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);
	stack.push(1);


	stack.pop();


	stack.push(1);
	stack.push(1);


	cout << stack << endl;
	return 0;
}
