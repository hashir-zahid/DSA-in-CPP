#include<iostream>
#include "C:\Users\hashir\Desktop\DSA\LinkedList.h"   //Use your path
using namespace std;
template<class T>
class CLL:public LinkedList<T>
{
	public:
		void traversing();
		void searchElement(string element);
		Node<T>* search(string element);
		void remove(string element);
};


template <class T>
void CLL<T>::traversing()
{
	Node<T>* ptr=this->getHead();	
	while (ptr!=0)
	{
    	ptr->getInfo()->display();
	    ptr=ptr->getNext();
	}	
}

template <class T>
void CLL<T>::searchElement(string element)
{
   	 Node<T>* ptr = this->getHead();
	
	 while (ptr!=0)
  	 {
	   if(element==ptr->getInfo()->getCourseCode())
		{
		    ptr->getInfo()->display();
		}
		ptr=ptr->getNext();
	}		
}

template <class T>
Node<T>* CLL<T>::search(string element)
{
   	 Node<T>* ptr = this->getHead();
	
	 while (ptr!=0)
  	 {
	   if(element==ptr->getInfo()->getCourseCode())
		{
		    return ptr;
		}
		ptr=ptr->getNext();
	}
	return 0;		
}

template<class T>
void CLL<T>::remove(string element)
{
	if((this->getHead()==0 && this->getTail()==0) || (search(element)==0))
	{
		cout<<"Nothing to delete";
	}
	else if(this->getHead()==this->getTail())
	{
		this->deleteFromHead();
	}
	else if(search(element)==this->getHead())
	{
		this->deleteFromHead();
	}
	else if(search(element)==this->getTail())
	{
		this->deleteFromTail();
	}
	else
	{
		Node<T>* ptr=this->getHead();
		Node<T>* pre=this->getHead();
		while(ptr->getInfo()->getCourseCode()!=element)
		{
			pre=ptr;
			ptr=ptr->getNext();
		}
		pre->setNext(ptr->getNext());
		delete ptr;
	}
}
