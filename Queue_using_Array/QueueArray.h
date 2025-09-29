#include<iostream>
using namespace std;
template<class T>
class QueueArray
{
	private:
		int rear;
		int front;
		int size;
		T *arr;
	public:	
		QueueArray(int size=5)
		{
			this->rear=-1;
			this->front=-1;
			arr=new T(size);
		}
		bool isEmpty();
		bool isFull();
		T rearValue();
		T frontValue();
		void enqueue(T element);
		T dequeue();
		
};

template<class T>
bool QueueArray<T>::isEmpty()
{
	return rear==-1 && front==-1;
}

template<class T>
bool QueueArray<T>::isFull()
{
	return rear==size-1;
}

template<class T>
T QueueArray<T>::rearValue()
{
	return arr[rear];
}


template<class T>
T QueueArray<T>::frontValue()
{
	return arr[front];
}


template<class T>
void QueueArray<T>::enqueue(T element)
{
	if(rear==size-1)
	{
		cerr<<"\nStack is full";
	}
	else if(rear==-1 && front==-1)
	{		
		rear++;
		front++;
		arr[rear]=element;
	}
	else
	{
		rear++;
		arr[rear]=element;
	}
}


template<class T>
T QueueArray<T>::dequeue()
{
	if(rear==-1 && front==-1)
	{
		cerr<<"\nStack is Empty";
	}
	else if(rear==front)
	{	
	    T value = arr[front]; 	
		rear==front==-1;
		return value;
	}
	else
	{
		T value = arr[front]; 	
		front++;
		return value;
	}	
}





