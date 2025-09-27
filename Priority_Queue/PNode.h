#include<iostream>
using namespace std;
template <class T>

class PNode
{
	private:
		T info;
		int prior;
        PNode<T> *next;
	public:
		PNode(T info=0, int prior=0, PNode<T>* next=0)
		{
			this->info=info;
			this->prior=prior;
			this->next=next;
		}
		
		void setInfo(T info);
		void setPrior(int prior);
        void setNext(PNode<T> *next);
        
        T getInfo();  
        int getPrior();
        PNode<T>* getNext();
        
        void display(); 
		
};


template <class T>
void PNode<T>::setInfo(T info)
{
    this->info=info;
}
 
template <class T>
void PNode<T>::setPrior(int prior)
{
	this->prior=prior;
}
 
template <class T>
void PNode<T>::setNext(PNode<T> *next)
{
    this->next=next;
}
 
 
template <class T>
T PNode<T>::getInfo()
{
    return info;  
}
 
template <class T>
int PNode<T>::getPrior()
{
	return prior;
}
 
template <class T>
PNode<T>* PNode<T>::getNext()
{
    return next;
}


template <class T>
void PNode<T>::display()
{
    cout<<"\n|("<<this<<")|"<<this->info<<"|\""<<this->prior<<"\"|"<<this->next <<"|"<<endl;
}
