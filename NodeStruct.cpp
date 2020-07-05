#include <iostream>
#include <fstream>

using namespace std;

ifstream in("input.txt");

struct node {
    string item;
    node *next;
    node *prev;
};

void addNode(string item, node *&head, node *&tail){
    node *nn=new node;
    nn->item=item;
    nn->next=NULL;
    nn->prev=NULL;
    if (!head){
        head=tail=nn;
    }
    else if(head==tail){
        tail=nn;
        tail->prev=head;
        tail->next=head;
        head->next=tail;
        head->prev=tail;
    }
    else{
        nn->prev=tail;
        nn->next=head;
        head->prev=nn;
        tail->next=nn;
        tail=nn;
    }
}

void removeNodes(int x,node *&head, node*&tail){
    node *cur;

    for (int i=1;i<=x;i++){
        if (head!=tail){
            cur=head;
            head=head->next;
            delete cur;
            head->prev=tail;
            tail->next=head;
        }
        else{
            cur=head;
            delete cur;
            head=tail=NULL;
        }
    }
}

void traverse(node*head){
    node * cur=head;
    if (head){
        while (cur->next!=head){
            cout<<cur->item<< endl;
            cur=cur->next;
        }
        cout << cur->item << endl;
    }
}

int main(){
    node *head,*tail;
    head=tail=NULL;
    int num;

    string item;

    while (in.good()){
        in>>item;
        addNode(item,head,tail);
    }
    cout<< "Contents of the list: \n";
    traverse(head);
    cout << endl;
    cout << "Enter the amount of nodes you would like to be removed.\n";
    cin >> num;
    removeNodes(num,head,tail);
    cout << endl;
    cout << "Contents of the list is now: \n";
    traverse(head);
    return 0;
}
