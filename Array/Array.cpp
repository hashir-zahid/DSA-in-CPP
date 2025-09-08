#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void initialization(int arr[], int size);
void display(int arr[], int size);
int minimum(int arr[], int size);
void linearsearch(int arr[], int size);
void binarysearch(int arr[],int size);
int largest(int arr[],int size);
void selectionsort(int arr[],int size);
void bubblesort(int arr[],int size);
void insertionsort(int arr[],int size);



int main(int argc, char** argv) 
{
	int size=5;
	int choice;
	int arr[size];
	int i=1;
	do
	{
		cout<<"\nEnter 1 for Initialization";
		cout<<"\nEnter 2 for Dsiplay";
		cout<<"\nEnter 3 for Minimum";
		cout<<"\nEnter 4 for Linear search";
		cout<<"\nEnter 5 for Binary search";
		cout<<"\nEnter 6 for Selection sort";
		cout<<"\nEnter 7 for Bubble sort";
		cout<<"\nEnter 8 for Insertion sort";
		cout<<"\nEnter 0 for Exit"<<endl;
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				initialization(arr,size);
				break;
			case 2:
				display(arr,size);
				break;
			case 3:
				cout<<"\nMinimun element of array is : "<<minimum(arr,size)<<endl;
				break;
			case 4:
				linearsearch(arr,size);
				break;
			case 5:
				binarysearch(arr,size);
				break;
			case 6:
				selectionsort(arr,size);
				break;
			case 7:
				bubblesort(arr,size);
				break;
			case 8:
				insertionsort(arr,size);
				break;
			case 0:
				exit(-1);
		}
		i++;
	}
	while(true);
	return 0;
}



void initialization(int arr[], int size)
{
	cout<<"\n----Initialization----\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Enter "<<i+1<<" element of array : ";
		cin>>arr[i];
	}
	cout<<"----Initialization End----"<<endl;
}



void display(int arr[], int size)
{
	cout<<"\n----Display----";
	for(int i=0;i<size;i++)
	{
		cout<<"\n"<<i+1<<" element of array is : "<<arr[i];
	}
	cout<<"\n----Display End----"<<endl;
}



int minimum(int arr[], int size)
{
	int min=arr[0];
	for(int i=1;i<size;i++)
	{
		if(arr[i]<min)
		   min=arr[i];
	}
	return min;
}



void linearsearch(int arr[], int size)
{
	int value,k=0;
	cout<<"Enter value that you want to search in array : ";
	cin>>value;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==value)
		    k++;
	}
	if(k==1)
	  cout<<"\nValue Found"<<endl;
	else
	  cout<<"\nValue Not Found"<<endl;
}



void binarysearch(int arr[],int size)
{
	int value;
	cout<<"Enter value that you want to search in array : ";
	cin>>value;
	int b=0;
	int e=size-1;
	int m=(b+e)/2;
	while(b<=e && value!=arr[m])
	{
		if(value>arr[m])
	      b=m+1;
		else
		  e=m-1;
		m=(b+e)/2;
	}
	if(b>e)
	   cout<<"\nValue Not Found"<<endl;
	else
	  cout<<"\nValue Found"<<endl;
}



int largest(int arr[],int size)
{
	int l=0;
	for(int i=1;i<size;i++)
	{
		if(arr[i]>arr[l])
		{
		   l=i;
	    }
	}
	return l;
}
void selectionsort(int arr[],int size)
{
	int t;
	for(int e=size-1;e>0;e--)
	{
		 int l=largest(arr,e+1);
		 
		 t=arr[l];
		 arr[l]=arr[e];
		 arr[e]=t;  
	}
	cout<<"\n\nSelection Sort\n";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<"\n\n";
}



void bubblesort(int arr[],int size)
{
	for(int e=size-1;e>0;e--)
	{
		bool flag=false;
		for(int i=0;i<e;i++)
    	{
		   if(arr[i]>arr[i+1])	
	       {
	       	    int t=arr[i];
	            arr[i]=arr[i+1];
	     	    arr[i+1]=t;
	     	    flag=true;
		   }	        
    	}
		if(flag==false)
		    break;		   
	}
	cout<<"\n\nBubble Sort\n";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<"\n\n";
}



void insertionsort(int arr[],int size)
{
	for(int i=1;i<size;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	cout<<"\n\nInsertion Sort\n";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<"\n\n";
}



