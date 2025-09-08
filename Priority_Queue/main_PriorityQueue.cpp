#include <iostream>
#include "PQueue.h"
using namespace std;

int main(int argc, char** argv) 
{
	PQueue<char> p1;
	p1.enqueue('a',3);
	p1.enqueue('H',1);
	p1.enqueue('s',4);
	p1.enqueue('i',8);
	p1.enqueue('r',9);
	p1.enqueue('h',6);
	
	cout<<p1.dequeue();
	cout<<"  "<<p1.dequeue();
	cout<<"  "<<p1.dequeue()<<"\n\n";
	
	p1.traversing();
	return 0;
}
