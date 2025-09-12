#include <iostream>
#include "TreeNode.h"
using namespace std;
template <class T>
class BST
{
	private:
		TreeNode<T>* root;
	public:
		BST()
		{
			root=0;
		}
		
		TreeNode<T>* getRoot();
		void insert(T element);
		void preOrderTraversal(TreeNode<T>* ptr);
		void postOrderTraversal(TreeNode<T>* ptr);
		void inOrderTraversal(TreeNode<T>* ptr);
		TreeNode<T>* search(T element);
		TreeNode<T>* getParent(T element);
		TreeNode<T>* getSuccessor(TreeNode<T>* ptr);
		void deleteNode(T element);
		
		
};

template <class T>
TreeNode<T>* BST<T>::getRoot()
{
	return root;
}

template <class T>
void BST<T>::insert(T element)
{
	TreeNode<T>* n = new TreeNode<T>(element);
	if(root==0)
	{
		root=n;
	}
	else
	{
		TreeNode<T>* ptr=root;
		while(ptr!=0)
		{
			if(element==ptr->getInfo())
			{
				cerr<<"Duplicate keys Not Allowed";
				return;
			}
			else if(element<ptr->getInfo())
			{
				if(ptr->getLeft()!=0)
				{
					ptr=ptr->getLeft();
				}
				else
				{
					ptr->setLeft(n);
					return;
				}
			}
			else
			{
				if(ptr->getRight()!=0)
				{
					ptr=ptr->getRight();
				}
				else
				{
					ptr->setRight(n);
					return;
				}
			}
	}
}
}

template <class T>
void BST<T>::preOrderTraversal(TreeNode<T>* ptr)
{
	if(ptr!=0)
	{
//		cout<<ptr->getInfo()<<" ";
		ptr->display();
		preOrderTraversal(ptr->getLeft());
		preOrderTraversal(ptr->getRight());
	}
}

template <class T>
void BST<T>::postOrderTraversal(TreeNode<T>* ptr)
{
	if(ptr!=0)
	{		
		postOrderTraversal(ptr->getLeft());
		postOrderTraversal(ptr->getRight());
//		cout<<ptr->getInfo()<<" ";
		ptr->display();
	}
}


template <class T>
void BST<T>::inOrderTraversal(TreeNode<T>* ptr)
{
	if(ptr!=0)
	{		
		inOrderTraversal(ptr->getLeft());
//		cout<<ptr->getInfo()<<" ";
        ptr->display();
		inOrderTraversal(ptr->getRight());		
	}
}


template <class T>
TreeNode<T>* BST<T>::search(T element)
{
	if(root==0)
	{
		return 0;
	}
	TreeNode<T>* ptr=root;
	while(ptr!=0 && ptr->getInfo()!=element)
	{
		if(element<ptr->getInfo())
		{
			ptr=ptr->getLeft();
		}
		else
		{
			ptr=ptr->getRight();
		}
	}
	return ptr;
}

template <class T>
TreeNode<T>* BST<T>::getParent(T element)
{
	if(root==0)
	{
		return 0;
	}
	TreeNode<T>* parent=0;
	TreeNode<T>* ptr=root;
	while(ptr!=0 && ptr->getInfo()!=element)
	{
		parent=ptr;
		if(element<ptr->getInfo())
		{
			ptr=ptr->getLeft();
		}
		else
		{
			ptr=ptr->getRight();
		}
	}
	return parent;
}


template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* ptr)
{
	ptr=ptr->getLeft();
	TreeNode<T>* s=0;
	while(ptr!=0)
	{
		s=ptr;
		ptr=ptr->getRight();
	}
	return s;
}


template <class T>
void BST<T>::deleteNode(T element)
{
	if(root==0)
	{
		cerr<<"\nNothimg to delete";
		return;
	}
	else
	{
		TreeNode<T>* n=search(element);
		if(n==0)
		{
			cerr<<"\nElement Not exist";
		}

		else if(n->getLeft()==0 && n->getRight()==0)
		{
			TreeNode<T>* parent=getParent(n->getInfo());
			if(n==parent->getLeft())
			{
				parent->setLeft(0);
			}
			else
			{
				parent->setRight(0);
			}
			delete n;
		}
		else if((n->getLeft()!=0&&n->getRight()==0) || (n->getLeft()==0&&n->getRight()!=0))
		{
			TreeNode<T>* parent = getParent(n->getInfo());
			TreeNode<T>* sc=0;
			if(n->getLeft()!=0 && n->getRight()==0)
			{
				sc=n->getLeft();
			}
			else
			{
				sc=n->getRight();
			}
			if(n==parent->getLeft())
			{
				parent->setLeft(sc);
			}
			else
			{
				parent->setRight(sc);
			}
			delete n;
		}
		else
		{
			TreeNode<T>* parent=getParent(n->getInfo());
			TreeNode<T>* s=getSuccessor(n);
			TreeNode<T>* sp=getSuccessor(s);
			if(s->getLeft()==0 && s->getRight()==0)
			{
				sp->setRight(0);
			}
			else
			{
				sp->setRight(s->getLeft());
			}
			s->setLeft(n->getLeft());
			s->setRight(n->getRight());
			
			if(n==parent->getLeft())
			{
				parent->setLeft(s);
			}
			else
			{
				parent->setRight(s);
			}
			
			delete n;
		}
	}
}
