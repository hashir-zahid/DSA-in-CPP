#include <iostream>
#include "CLL.h"
#include "Course.h"
using namespace std;

int main(int argc, char** argv) 
{
	CLL<Course*> courses;
	int choice;
	string code;
	string name;
	int hours;
	string co;
	string c;
	do
	{
	cout<<"\n\nPress 1 to insert a new course"<<endl;
	cout<<"Press 2 to display all course"<<endl;
	cout<<"Press 3 to search a course"<<endl;
	cout<<"Press 4 to delete a course"<<endl;
	cout<<"Press 0 to exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Provide Course Code : ";
			cin>>code;
			cout<<"\nProvide Course Name : ";
			cin>>name;
			cout<<"\nProvide Course Credit hours : ";
			cin>>hours;
			courses.addToTail(new Course(code,name,hours));
			break;
		case 2:
			courses.traversing();
			break;
		case 3:
			cout<<"\nEnter code of course that you want to search: ";
			cin>>co;
			courses.searchElement(co);
            break; 
		case 4:
			cout<<"\nEnter code of course that you want to delete : ";
			cin>>c;
			courses.remove(c);
			break;
		case 0:
			exit(0);
	}
	
    }
    while(true);  
	return 0;
}
