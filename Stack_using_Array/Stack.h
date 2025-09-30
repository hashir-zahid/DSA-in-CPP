#include <iostream>
using namespace std;
template <class T>
class Stack
{
private:
	int top;

public:
	Stack()
	{
		this->top = -1;
	}
	bool isEmpty();
	bool isFull();
	T topValue();
	void push(T element);
	T pop();
};

template <class T>
bool Stack<T>::isEmpty()
{
	return top == -1;
}
template <class T>
bool Stack<T>::isFull()
{
	top == 4;
}
template <class T>
T Stack<T>::topValue()
{
	return arr[top];
}
template <class T>
void Stack<T>::push(T element)
{
	if (top == size - 1)
	{
		cout << "Satck overflow";
	}
	else
	{
		top++;
		arr[top] = element;
	}
}
template <class T>
T Stack<T>::pop()
{
	if (top == -1)
	{
		cout << "Stack underflow";
		return 0;
	}
	else
	{
		T element = arr[top];
		top--;
		return top;
	}
}
