#include<iostream>
#include "PNode.h"
using namespace std;
template <class T>
class PQueue
{
	private:
		PNode<T>* rear;
		PNode<T>* front;
	public:
		PQueue(PNode<T>* rear=0 , PNode<T>* front=0)
		{
			this->rear=rear;
			this->front=front;
		}
		void setRear(PNode<T>* rear);
		PNode<T>* getRear();
		void setFront(PNode<T>* front);
		PNode<T>* getFront();
		void enqueue(T element,int priority);
		T dequeue();
		void traversing();
		bool isEmpty();
		T rearValue();
		T frontValue();
};


template <class T>
void PQueue<T>::setRear(PNode<T>* rear)
{
	this->rear=rear;
}

template <class T>
PNode<T>* PQueue<T>::getRear()
{
	return this->rear;
}

template <class T>
void PQueue<T>::setFront(PNode<T>* front)
{
	this->front=front;
}

template <class T>
PNode<T>* PQueue<T>::getFront()
{
	return this->front;
}

template <class T>
void PQueue<T>::enqueue(T element,int priority)
{
	PNode<T>* n = new PNode<T>(element,priority);
	if(rear==0 && front==0)
	{
		rear=front=n;
	}
	else if(priority<front->getPrior())
	{
		n->setNext(front);
		front=n;
	}
	else if(priority>rear->getPrior())
	{
		rear->setNext(n);
		rear=n;
	}
	else
	{
		PNode<T>* ptr=front;
		while(priority>=ptr->getNext()->getPrior())
		{
			ptr=ptr->getNext();
		}
		n->setNext(ptr->getNext());
		ptr->setNext(n);
	}
}

template <class T>
T PQueue<T>::dequeue()
{
	if(rear==0 && front==0)
	{
		cout<<"Nothing to do";
	}
	else if(rear==front)
	{
		T element = front->getInfo();
		delete front;
		rear=front=0;
		return element;
	}
	else
	{
		T element = front->getInfo();
		PNode<T>* ptr=front->getNext();
		delete front;
		front=ptr;
		return element;
	}
}

template <class T>
bool PQueue<T>::isEmpty()
{
	return rear==0 && front==0;
}

template <class T>
T PQueue<T>::rearValue()
{
	return rear->getInfo();
}

template <class T>
T PQueue<T>::frontValue()
{
	return front->getInfo();
}

template <class T>
void PQueue<T>::traversing()
{
	PNode<T>* ptr=front;
	while(front!=0)
	{
		ptr->display();
		ptr=ptr->getNext();
	}
}





















