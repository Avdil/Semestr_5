#include <iostream>
using namespace std;
const int n = 5;

class Stack{
private: int S[n];
		 bool is_full();
		 int top = 0;
public: Stack();
		void Push(int x);
		void Pop();
		void Print();
};

class Queue {
private: int Q[n];
		 int tail = 0;
		 int head = 0;
public: void Enqueue(int x);
		void Dequeue();
		void PrintQ();
};



void main(){
	Stack S;
	Queue Q;
	S.Push(5); S.Push(6); S.Push(8);
	S.Pop();
	S.Print();
	Q.Enqueue(6); Q.Enqueue(7); Q.Enqueue(17); Q.Enqueue(3);
	Q.Dequeue();
	Q.Dequeue();
	Q.PrintQ();
	cin.get();
	cin.get();
}



bool Stack::is_full(){
	if (top == n - 1)
		return true;
	else
		return false;
}
Stack::Stack(){
	top = -1;
}
void Stack::Push(int x){
	if (is_full())
		cout << "Stack overflow";
	else{
		top++;
		S[top] = x;
	}
}
void Stack::Pop(){
	if (top == -1)
		cout << "Stack underflow";
	else
		top--;
}
void Stack::Print(){
	cout << "Top element to stack: " << S[top] << "\n";
}

void Queue::Enqueue(int x) {
	if (head == 0 && tail == n)
		cout << "Queue overflow";
	else {
		Q[tail] = x;
		if (tail == n)
			tail = 0;
		else tail++;
	}
}
void Queue::Dequeue() {
	if (head == tail)
		cout << "Queue underflow";
	else {
		if (head == n)
			tail = 0;
		else head++;
	}
}
void Queue::PrintQ() {
	cout << "First element to queue: " << Q[head];
}