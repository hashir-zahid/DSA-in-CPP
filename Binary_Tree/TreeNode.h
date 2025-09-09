#include <iostream>
using namespace std;
template <class T>
class TreeNode
{
	private:
		T info;
		TreeNode<T>* left;
		TreeNode<T>* right;
	public:
		TreeNode(T info, TreeNode<T>* left=0, TreeNode<T>* right=0)
		{
			this->info=info;
			this->left=left;
			this->right=right;
		}
		
		void setInfo(T info);
		T getInfo();
		
		void setLeft(TreeNode<T>* left);
		TreeNode<T>* getLeft();
		
		void setRight(TreeNode<T>* right);
		TreeNode<T>* getRight();
		
		void display();
};

template <class T>
void TreeNode<T>::setInfo(T info)
{
	this->info=info;
}

template <class T>
T TreeNode<T>::getInfo()
{
	return info;
}


template <class T>
void TreeNode<T>::setLeft(TreeNode<T>* left)
{
	this->left=left;
}

template <class T>
TreeNode<T>* TreeNode<T>::getLeft()
{
	return left;
}


template <class T>
void TreeNode<T>::setRight(TreeNode<T>* right)
{
	this->right=right;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight()
{
	return right;
}


template <class T>
void TreeNode<T>::display()
{
	cout<<"\n";
	cout<<"("<<this<<")"<<" | "<<this->left<<" | "<<this->info<<" | "<<this->right;
}
