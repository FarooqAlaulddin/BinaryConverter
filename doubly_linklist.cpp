#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <stack>   
using namespace std;

 struct node{
	int data;
	node *next;
	node *prev;
};

ifstream in("input.txt");		//input.txt is the file that we read from
ofstream out("output.txt");	//output.txt is the file that we write into

int clean()
{
    string comments;  
    while (in.peek()=='\n' || in.peek()=='/' || in.peek()==' ' || in.peek()=='\t')
	{
        if (in.peek()=='/' )
            getline(in, comments);  
        else
            in.get();    
    }
      return 1;
}


int numOfNode(struct node * &head){
	struct node * curr;
	int numOfNod;
	curr=head;
	while(curr){
		++numOfNod;
		curr=curr->next;
	}
	return(numOfNod);
	
}

void insertToFront(int data,struct node * &head, struct node * &tail){       // function that adds node to the front
	
	struct node * nn=new node;
		nn->data=data;
		
		if(head){
			nn->next=head;
			head->prev=nn;
			nn->prev=NULL;
			head=nn;
			
		}else{
			nn->next=NULL;
			nn->prev=NULL;
			head=nn;
			tail=nn;	
		}
}

void insertToEnd(int data,struct node * &head, struct node * &tail){       // function that adds node to the end
	
	struct node * nn=new node;
		nn->data=data;
		if(head!=NULL){
			nn->prev=tail;
			tail->next=nn;
			nn->next=NULL;
			tail=nn;
			
		}else{
			nn->next=NULL;
			nn->prev=NULL;
			head=nn;
			tail=nn;	
		}
}

void insertToMed(int data,int selcNode /* where you want to put it after */,struct node * &head, struct node * &tail){
	
		struct node * nn, * curr;
		nn=new node;
		curr=head;
		int numNode;
		numNode=numOfNode(head); 
		nn->data=data;

		while(selcNode>1){
			curr=curr->next;
			--selcNode;
		}
				
		nn->next=curr;
		nn->prev=curr->prev;
		curr->prev=nn;
		nn->prev->next=nn;
		
		
		
	
}

void deleteFromEnd(int itemDelete,int numNode, struct node * &head, struct node * &tail){
		
		struct node *curr, *temp;
		curr=tail;
		int item=itemDelete;
		if(head){	
			if(item==numNode)
			{	
				temp=head;
				head=temp->next;
				temp->next->prev=NULL;
				temp->next=NULL;
				delete temp;
					
			}
			else if(item==1)
			{
				temp=tail;
				tail=temp->prev;
				temp->prev->next=NULL;
				temp->prev=NULL;
				delete temp;	
			}
			else
			{
				while(itemDelete>1)
				{
					curr=curr->next;
					--itemDelete;
				}
				//cout<<"curr is :"<<curr->data<<endl;
				//cout<<"head is :"<<head->data<<endl;
				
				temp=curr;
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				temp->next=NULL;
				temp->prev=NULL;
				delete temp;
	
			}
		
		}
		else
		{
			cout<<"Empty"<<endl;
		}
		
}



void deleteFromBeg(int itemDelete,int numNode, struct node * &head, struct node * &tail){
		
		struct node *curr, *temp;
		curr=head;
		int item=itemDelete;
		if(head){	
			if(item==1)
			{	
				temp=head;
				head=temp->next;
				temp->next->prev=NULL;
				temp->next=NULL;
				delete temp;
					
			}
			else if(item==numNode)
			{
				temp=tail;
				tail=temp->prev;
				temp->prev->next=NULL;
				temp->prev=NULL;
				delete temp;	
			}
			else
			{
				while(itemDelete>1)
				{
					curr=curr->prev;
					--itemDelete;
				}
				//cout<<"curr is :"<<curr->data<<endl;
				//cout<<"head is :"<<head->data<<endl;
				
				temp=curr;
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				temp->next=NULL;
				temp->prev=NULL;
				delete temp;
	
			}
		
		}
		else
		{
			cout<<"Empty"<<endl;
		}
		
}


int main()
{
	struct node * head, *tail, *curr,* tre;
	head=tail=curr=tre=NULL;
	curr=head;
	int numNod;
	int num;
	
	//insertToFront(6,head,tail);						// functions that adds node to the front
	//insertToFront(4,head,tail);
	//insertToFront(3,head,tail);
	//insertToFront(1,head,tail);
	
	//cout<<"head is :"<<head->data<<endl;
	//cout<<"curr is :"<<curr->data<<endl;

	//insertToEnd(1,head,tail);						
	//insertToEnd(2,head,tail);						// functions that adds node to the end
	//insertToEnd(3,head,tail);
	//insertToEnd(4,head,tail);
	//insertToEnd(6,head,tail);
	
	
	//insertToMed(2,2,head,tail);
	//insertToMed(5,5,head,tail);
	
	//numNod=numOfNode(head);
	
	//deleteFromEnd(1,numNod,head,tail);
	//deleteFromEnd(6,numNod,head,tail);
	//deleteFromEnd(4,numNod,head,tail);
	

	while (clean() && in.good())
	{
		
		in >> num;
		insertToEnd(num,head,tail);
		
	}
	
	//cout<<"head "<<head->data<<endl;
	//cout<<"tail "<<tail->data<<endl;
	
	numNod=numOfNode(head);
	cout<<"hello"<<endl;
	

	tre=head;  										// trevarse forwords  1
	//curr=tail;    								// trevarse backwords 2
	cout<<"yourList is :";
	while(tre){
		 											
		//curr=curr->prev; 							// 2 trevarse from tail to head
		cout<<tre->data;
		tre=tre->next;								// 1 trevarse from head to tail
	}
	
	int d1;
	cout<<"\ndo you want to delete from 1) beginning or 2) end? or 0 to EXIT "<<endl;
	cin>>d1;
	
	switch(d1){
	
	case 1:
		int delete1;
		cout<<"Which item do you want to delete from the beginning? "<<endl;
		cin>>delete1;
		deleteFromBeg(delete1,numNod,head,tail);
		break;	
	case 2:		
		int delete2;
		cout<<"Which item do you want to delete from the end? "<<endl;
		cin>>delete2;
		deleteFromEnd(delete2,numNod,head,tail);
		break;
		
	default:
		cout<<"please select 1 or 2";	
		break;
	
	}	
	
	curr=head;
	while(curr)
	{
		out<<curr->data;
		curr=curr->next;
	}
	
	in.close();
	out.close();
	
   	/*
   	cout<<"\ntrevasre: "<<endl;
	tre=head;  										// trevarse forwords  1
	//curr=tail;    								// trevarse backwords 2
	while(tre){
		cout<<tre->data<<endl;
		tre=tre->next;  							// 1 trevarse from head to tail
		//curr=curr->prev; 							// 2 trevarse from tail to head
	}
   */
}






