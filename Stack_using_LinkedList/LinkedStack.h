#include<iostream>
#include "C:\Users\hashir\Desktop\DSA\LinkedList\Node.h"  //Use your path
using namespace std;
template<class T>

class LinkedStack
{
    private:
	    Node<T>* top;
	public:
	    LinkedStack(Node<T>* top=0)
		{
			this->top=top;
		}	
		
		bool isEmpty();
		T topValue();
		void push(T element);
		T pop();
		
};

template<class T>
bool LinkedStack<T>::isEmpty()
{
	return top==0;
}

template<class T>
T LinkedStack<T>::topValue()
{
	return top->getInfo();
}

template<class T>
void LinkedStack<T>::push(T element)
{
	Node<T>* n =new Node<T>(element);
	if(top==0)
	{
		this->top=n;
	}
	else
	{
		n->setNext(top);
		this->top=n;
	}
}

template<class T>
T LinkedStack<T>::pop()
{
	T value;
	if(top==0)
	{
		cout<<"Stack underflow";
	}
	else
	{
		Node<T>* ptr=top->getNext();
		value = top->getInfo();
		delete top;
		top=ptr;
	}
	return value;
}


