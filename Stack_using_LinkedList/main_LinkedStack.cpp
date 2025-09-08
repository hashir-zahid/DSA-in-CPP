#include <iostream>
#include<stdlib.h>
#include "cmath"
#include "LinkedStack.h"

string stringReversal(string text);
int precedence(char optr);
string infixToPostfix(string infix);
string infixToPretfix(string infix);

int main(int argc, char** argv) 
{
	int choice;
	string infix;
	string text;
	
	do
	{
		cout<<"\nEnter 1 for Infix-to-Postfix";
		cout<<"\nEnter 2 for Postfix-to-Infix";
		cout<<"\nEnter 3 for Infix-to-Prefix";
		cout<<"\nEnter 4 for Prefix-to-Infix";
		cout<<"\nEnter 5 for Postfix-to-Prefix";
		cout<<"\nEnter 6 for Prefix-to-Postfix";
		cout<<"\nEnter 0 for Exit\n";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"\nEnter Infix : ";
				cin>>infix;
				cout<<"\n---------------------------------------------";
				cout<<"\nInfix : "<<infix;
				cout<<"\nPostfix : "<<infixToPostfix(infix);
				cout<<"\n---------------------------------------------";
				break;
			case 2:
			
				cout<<"Enter : ";
				cin>>text;
                cout<<"   "<<stringReversal(text);
				break;
//			case 3:
//				break;
//			case 4:
//				break;
//			case 5:
//				break;
//			case 6:
//				break;
			case 0:
				exit(0);
		}
	}
	while(true);
	return 0;
}



string stringReversal(string text)
{
	LinkedStack<char> s;
	string st="";
	for(int i=0;i<text.length();i++)
	{
		s.push(text[i]);
	}
	while(!s.isEmpty())
	{
	  	st+= s.pop();	
	}
	return st;
}

int precedence(char optr)
{
	if(optr=='^')
	    return 3;
	else if(optr=='/' || optr=='*')
	    return 2;
	else if(optr=='+' || optr=='-')
	    return 1;
}





string infixToPostfix(string infix)
{
	LinkedStack<char> s1;
	string postfix="";
	
	for(int i=0;i<infix.length();i++)
	{
		if(isalpha(infix[i]))//2.1 operand
		{
			postfix+=infix[i];
		}
		
		else if(infix[i]=='(')//2.2 opening symbol
		{
			s1.push(infix[i]);
		}
		
		else if(infix[i]=='*' || infix[i]=='/' || infix[i]=='+' || infix[i]=='-' || infix[i]=='^')//2.3 operator
		{
			if(s1.isEmpty())//2.3.1 empty
			{
				s1.push(infix[i]);
			}
			else //2.3.2 non-empty
			{
				while(!s1.isEmpty() && s1.topValue()!='(' && precedence(s1.topValue()) >= precedence(infix[i]))// 1 >= 1
				{
					postfix+=s1.pop();
				}
				//poping is done
				s1.push(infix[i]);
			}
			
		}
		
		else if(infix[i]==')')//2.4 closing bracket
		{
			while(s1.topValue()!='(')
			{
				postfix+=s1.pop();
			}
			s1.pop();
		}
	}

	while(!s1.isEmpty())
	{
		postfix+=s1.pop();
	}
	return postfix;
}//in-to-post
