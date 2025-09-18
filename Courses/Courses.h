#include<iostream>
using namespace std;
class Course
{
	private:
		string courseCode;
		string courseName;
		int creditHours;
	public:
		Course(string courseCode , string courseName , int creditHours)
		{
			this->courseCode = courseCode;
			this->courseName = courseName;
			this->creditHours = creditHours;
		}
		
		void setCourseCode(string courseCode);
		string getCourseCode();
		void setCourseName(string courseName);
		string getCourseName();
		void setCreditHours(int creditHours);
		int getCreditHours();
		void display();
	
	
};


void Course::setCourseCode(string courseCode) 
{
	this->courseCode = courseCode;
}
string Course::getCourseCode()
{
	return this->courseCode;
}
		
		
void Course::setCourseName(string courseName)
{
	this->courseName = courseName;
}
string Course::getCourseName()
{
	return this->courseName;
}

		
void Course::setCreditHours(int creditHours)
{
	this->creditHours = creditHours;
}
int Course::getCreditHours()
{
	return this->creditHours;
}


void Course::display()
{
	cout<<endl;
	cout<<"Course Code : "<<this->courseCode<<endl;
	cout<<"Course Name : "<<this->courseName<<endl;
	cout<<"Credit hours : "<<this->creditHours<<endl;
}
