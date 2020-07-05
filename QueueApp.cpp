#include <iostream>
#include <fstream>
using namespace std;

ifstream in ("input.txt");

struct node
{
	int item;
	node *next;
	bool check;
};

typedef struct node node;

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


void enqueue(int item, bool check, struct node *&front, struct node*&rear)
{
    struct node *newNode=new node;
   
    newNode->item=item;
    newNode->check=check;
	newNode->next=NULL;  
    if (rear)
	{          
		rear ->next=newNode;  
      	rear =newNode;        
   	}
   	else
        front = rear =newNode;   
}

void dequeue(struct node *& front, struct node *& rear)
{
    struct node *temp;

    if(front)
	{  
        temp= front;  
        front = front->next;
		temp->next=NULL;  
        delete temp;
	    if (!front)
       		rear=NULL;
 	}
}

void Traverse (node *front)
{
	node *curr;
	curr=front;
	while(curr)
	{
		cout<<"Number is: "<<curr->item<<"  curr->check: "<<curr->check<<endl;
		curr=curr->next;
	}	
}

void Refine (node *&front, node *&rear, node *&curr)
{
	//node * curr;
	int num, i=0,j=100000000;
	bool x;
	while (curr && curr->check)
	{
		if(curr->item<0)
		{
			curr=curr->next;
			dequeue(front, rear);
		}
		else
		{
			num=curr->item;
			curr->check=false;
			x=curr->check;
			cout<<"curr->item: "<<curr->item<<" - curr->check: "<<curr->check<<endl;
			curr=curr->next;
			dequeue(front, rear);
			enqueue(num, x, front, rear);
		}
	}
}

int main(){
    struct node * front, * rear, * curr;
    front = rear =NULL;
    int item;
    while (clean() && in.good())
    {
    	in>>item;
    	enqueue(item, true, front, rear);
	}
	
	Traverse(front);
	
	curr=front;
	
	Refine (front ,rear, curr);
	cout<<endl<<"After Refine: "<<endl;
//	dequeue(front, rear);
	Traverse(front);
	
		
}
