#include <iostream>
#include <string>
#include <cctype>
#include "C:\Users\hashir\Desktop\DSA\LinkedList.h"  //use yourn own path

using namespace std;


int precedence(char optr);
string reverseString(string str); 

string infixToPostfix(string infix);
string infixToPrefix(string infix);
string postfixToPrefix(string postfix);
string prefixToPostfix(string prefix);
string prefixToInfix(string prefix);
string postfixToInfix(string postfix); 


int main() 
{
          int choice;
          string expression;

   	 do 
	 {
        		cout << "\nEnter 1 for Infix-to-Postfix";
        		cout << "\nEnter 2 for Infix-to-Prefix";
        		cout << "\nEnter 3 for Postfix-to-Prefix";
        		cout << "\nEnter 4 for Prefix-to-Postfix";
        		cout << "\nEnter 5 for Prefix-to-Infix";
        		cout << "\nEnter 6 for Postfix-to-Infix";  
        		cout << "\nEnter 0 for  Exit";
        		cout << "\nEnter your choice: ";
        		cin >> choice; 

        		switch (choice) 
		{
            		case 1:
            			cout << "\n--------------------------------------------------";
            			cout << "\nInfix Expression : "<<expression;
                			cout << "\nPostfix Expression : " << infixToPostfix(expression) << endl;
                			cout << "--------------------------------------------------";
                			break;
            		case 2:
            			cout << "\n--------------------------------------------------";
            			cout << "\nInfix Expression : "<<expression;
                			cout << "\nPrefix Expression: " << infixToPrefix(expression) << endl;
            			cout << "\n--------------------------------------------------";
                			break;
            			case 3:
            			cout << "\n--------------------------------------------------";
            			cout << "\nPostfix Expression : "<<expression;
                			cout << "\nPrefix Expression: " << postfixToPrefix(expression) << endl;
                			cout << "\n--------------------------------------------------";
                			break;
            		case 4:
            			cout << "\n--------------------------------------------------";
            			cout << "\nPrefix Expression : "<<expression;
                			cout << "\nPostfix Expression: " << prefixToPostfix(expression) << endl;
                			cout << "\n--------------------------------------------------";
                			break;
            		case 5:
            			cout << "\n--------------------------------------------------";
            			cout << "\nPrefix Expression : "<<expression;
                			cout << "\nInfix Expression: " << prefixToInfix(expression) << endl;
                			cout << "\n--------------------------------------------------";
                			break;
            		case 6:
            			cout << "\n--------------------------------------------------";
            			cout << "\nPostfix Expression : "<<expression;
                			cout << "\nInfix Expression: " << postfixToInfix(expression) << endl;  
                			cout << "\n--------------------------------------------------";
            		case 0:
				exit(0);
            		default:
                			cout << "\nInvalid choice. Please try again.\n";
       		 }
   	 } 
	while (true);

   	 return 0;
}

string reverseString(string str) 
{
    	LinkedStack<char> stack;
    	string reversed="";

    	for (int i = 0; i < str.length(); i++) 
	{
        		stack.push(str[i]);
    	}
    	while(!stack.isEmpty())  
	{
        		reversed += stack.pop();
    	}

    	return reversed;
}

int precedence(char optr) 
{
    	if (optr == '^') 
		return 3;
    	else if (optr == '*' || optr == '/') 
		return 2;
    	else if (optr == '+' || optr == '-') 
		return 1;
    	return 0;
}

string infixToPostfix(string infix) 
{
    	LinkedStack<char> stack;
    	string postfix = "";

    	for (int i = 0; i < infix.length(); i++) 
	{
        		char ch = infix[i];
        		if (isalpha(ch) || isdigit(ch)) 
		{
            		postfix += ch;
        		} 
		else if (ch == '(') 
		{ 
            		stack.push(ch);
        		} 
		else if (ch == ')') 
		{ 
            		while (!stack.isEmpty() && stack.topValue() != '(') 
			{
                			postfix += stack.pop();
            		}
            		if (!stack.isEmpty()) 
				stack.pop(); 
        		} 
		else 
		{ 
            		while (!stack.isEmpty() && precedence(stack.topValue()) >= precedence(ch)) 
			{
                			postfix += stack.pop();
            		}
           		 stack.push(ch);
       		 }
   	 }

    	while (!stack.isEmpty()) 
	{
       		 postfix += stack.pop();
   	 }
    	return postfix;
}

string infixToPrefix(string infix) 
{
    	string reversed = reverseString(infix);
   	 for (int i = 0; i < reversed.length(); i++) 
	{
        		if (reversed[i] == '(') 
			reversed[i] = ')';
        		else if (reversed[i] == ')') 
			reversed[i] = '(';
   	}

    	string postfix = infixToPostfix(reversed); 
   	return reverseString(postfix); 
}

string postfixToPrefix(string postfix) 
{
	
    	string infix =postfixToInfix(postfix);
    	string  prefix =infixToPrefix(infix);
    	return prefix;
}

string prefixToPostfix(string prefix) 
{
    
    	string infix =prefixToInfix(prefix);
    	string  postfix =infixToPostfix(infix);
	return postfix;
}

string prefixToInfix(string prefix) 
{
    	LinkedStack<string> stack;

    	string reversed = reverseString(prefix); 

    	for (int i = 0; i < reversed.length(); i++) 
	{
        		char ch = reversed[i];
        		if (isalpha(ch) || isdigit(ch)) 
		{ 
            	stack.push(string(1, ch));
        		} 
		else 
		{
            		string op1 = stack.pop();
            		string op2 = stack.pop();
            		string infix = "(" + op1 + string(1, ch) + op2 + ")";
            		stack.push(infix);
        		}
    	}
    	return stack.pop();
}

string postfixToInfix(string postfix) 
{
    	LinkedStack<string> stack;
    	for (int i = 0; i < postfix.length(); i++) 
	{
        		char ch = postfix[i];
        		if (isalpha(ch) || isdigit(ch)) 
		{ 
            		stack.push(string(1,ch));
        		} 
		else 
		{
            		string op2 = stack.pop();
            		string op1 = stack.pop();
            		string infix = "(" + op1 + string(1, ch) + op2 + ")";
            		stack.push(infix);
        		}
    	}
    	return stack.pop();
}

