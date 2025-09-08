#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char** argv) 
{
	BST<int> t1;
	t1.insert(75);
	t1.insert(15);
	t1.insert(30);
	t1.insert(85);
	t1.insert(51);
	t1.insert(35);
	t1.insert(77);
//	t1.preOrderTraversal(t1.getRoot());
//	cout<<"\n";
//	t1.postOrderTraversal(t1.getRoot());
//	cout<<"\n";
	t1.inOrderTraversal(t1.getRoot());
	
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	t1.deleteNode(85);
    t1.deleteNode(77);
	t1.inOrderTraversal(t1.getRoot());
	
	return 0;
}
