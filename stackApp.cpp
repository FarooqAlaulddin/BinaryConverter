#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

using namespace std;

struct node
{
	int number;
	node *next;
};

typedef struct node node;

char arr[10]={'w','e'}, *arPtr;



void push(int item, node * &top){
	
	node *newNode=new node;    
	newNode->number=item;    
	newNode->next=top;    
	top=newNode;
	cout<<"top->number: "<<top->number<<endl;
}


void pop(struct node *&top,char *arPtr)
{
	struct node *temp;    
	//int i=0;
	if(top)
	{        
		temp=top;        
		top=top->next;
		itoa (temp->number,arPtr,10);
	//	cout<<"i: "<<i<<"arPtr: "<<arPtr[i]<<endl;
		//i++;        
		delete temp;    
	}
}

void popHex(struct node *&top,char *arPtr)
{
	struct node *temp;    
	//int i=0;
	if(top)
	{        
		temp=top;        
		top=top->next;
		itoa (temp->number,arPtr,16);
	//	cout<<"i: "<<i<<"arPtr: "<<arPtr[i]<<endl;
		//i++;        
		delete temp;    
	}
}


int main(){
	struct node *top=NULL;
	//char arr[10]={'w','e'}, *arPtr;
	int number, choice, remainder;
	arPtr=arr;
	cout<<"enter a number to convert it into desimal or hexadesimal"<<endl;
	cin >> number;
	
	cout << "Convert the number into:\n1 – Binary\n2 – Hexadecimal\n"<<endl;
    cin >> choice;
    
	switch (choice)
    {
        case 1:
            while (number > 0)
            {
                remainder = number % 2;
                cout<<"remainder: "<<remainder<<endl; //debuging code
                number /= 2;
                cout<<"number: "<<number<<endl; // debuging code
                push(remainder, top);
            }
            break;

	
	case 2:
            while (number > 0)
            {
                remainder = number % 16;
                number /= 16;
                if (remainder > 9 )
                        cout << char('A'  + remainder - 10);
                else
                    cout << remainder;
                push(remainder, top);
            }
            break;
            
	}
	
	node *temp=top;
	while(temp) // debuging code
	{
		cout<<"number inside push: "<<temp->number<<" "<<endl; // debuging code
		temp=temp->next;
	}

	int i=-1;
	while(top) // debuging code
	{
		if (choice == 1)
			pop(top, & arPtr[++i]);
		else if (choice == 2)
			popHex(top, & arPtr[++i]);
	//	cout<<"number inside pop: "<<top->number<<" "<<endl; // debuging code
	}
	
	
	
	for (int i=0; i<10; i++)
	cout<<arPtr[i]<<" ";
		
}



	
