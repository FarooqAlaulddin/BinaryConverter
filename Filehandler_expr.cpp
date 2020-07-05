
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

 struct node{
	char data;
	node *next;
};

ifstream in ("input.txt");

int clean()
{
    string comments;  //store the comments in this variable
    while (in.peek()=='\n' || in.peek()=='/' || in.peek()==' ' || in.peek()=='\t')
	{
        if (in.peek()=='/' )
            getline(in, comments);  //read the entire line because it is a comment
        else
            in.get();    //eat the newline, space and tab characters
    }
      return 1;
}

void push(int data, struct node * &top){
	
	struct node *nn=new node;
		if(top)
		{
			nn->data=data;
			nn->next=top;
			top=nn;
		}
		else
		{
			nn->data=data;
			nn->next=NULL;
			top=nn;
		}
	
}
void pop(struct node * &top){
	struct node *temp;
	if(top){
	temp=top;
	top=top->next;
	delete temp;
	}
}

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
 
// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s)
{	
	int l = s.length();
	cout<<"the leng is :"<<l<<endl;
	struct node * curr, *top;
	curr=top=NULL;
    string ns;
    for(int i = 0; i < l; i++)
    {
    	cout<<"the begining of the loop"<<endl;
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= '1' && s[i] <= '9'))
		{
		
        	ns+=s[i];
        	cout<<"it is number :"<<s[i]<<endl;
 		
		}

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')
        	{
        	push('(',curr);
        	cout<<"("<<endl;
        	}
        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
        	cout<<")"<<endl;
            while(curr && curr->data != '(')
            {
                char c = curr->data;
                pop(curr);
               	ns += c;
               	cout<<") while"<<endl;
            }
            if(curr->data == '(')
            {
                char c = curr->data;
                pop(curr);
                cout<<"("<<endl;
            }
        }
         
        //If an operator is scanned
        else
		{
        	cout<<"inside operator "<<endl;
            while(curr && prec(s[i]) <= prec(curr->data))
            {
                char c = curr->data;
                pop(curr);
                ns += c;
            }
            push(s[i],curr);
        }
 	
    }
    
    //Pop all the remaining elements from the stack
    while(curr)
    {
        char c= curr->data;
        pop(curr);
        ns += c;
    }
     
    cout << ns << endl;

}
 
int main()
{
	string myArray[5];
	string exp="";
    if(in.is_open())
    {
        

        for(int i = 0; i < 5; ++i)
        {
            in >> myArray[i];
        }
    }
    for(int i = 0; i < 5; ++i)
        {
            exp+=myArray[i];
        }
    

    //string exp = "1+2";
    infixToPostfix(exp);
     
}
