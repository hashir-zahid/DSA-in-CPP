#include <iostream>
#include"QueueArray.h"
using namespace std; 

int main(int argc, char** argv) 
{
	QueueArray<int> q1(4);
	q1.enqueue(30);
	q1.enqueue(20);
	q1.enqueue(30);
	cout<<q1.dequeue();
	return 0;
}
