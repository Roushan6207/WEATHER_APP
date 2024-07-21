#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node* prev;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        cout << "node with value :" << this->data << " " << "deleted"  << endl;
    }

};

void print(Node * head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }

}

int getlength(Node *head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void InsertAthead(Node* &head,Node * &tail,int data){
    //empty case
    if(head==NULL){
        Node * newnode=new Node(data);
        head=newnode;
        tail=newnode;
        //return;
    }

    else{
        // non empty
        // step1:
          Node * newnode=new Node(data);
          //step2:
          newnode->next=head;
          //step3;
          head->prev=newnode;
          //step4:
          head=newnode; 
            
    }


}


void InsertAtTail(Node * & head,Node * & tail,int data){
    // empty
    if(head==NULL){
        Node * newnode= new Node(data);
        head=newnode;
        tail=newnode;
        return;
    }
    else{
        // non empty
        //step1:
        Node * newnode=new Node(data);
        //step2;
        tail->next=newnode;
        //step3:
        newnode->prev=tail;
        //step4;
        tail=newnode;
    }
}

 void InsertAtPosition(Node * & head,Node * & tail,int data,int position){
    //empty  ho to

    //int len=getlength(head);

     if(head==NULL){
        Node * newnode= new Node(data);
        head=newnode;
        tail=newnode;
        return;
    }

    else{
        //ll is not empty
        if(position==1){
            InsertAthead(head,tail,data);
            return;
        }
        int len=getlength(head);

        if(position>len){
            InsertAtTail(head,tail,data);
            return;
        }

        // insertion in middle
        int i=1;
        Node * prevNode=head;
        while(i<position-1){
            prevNode=prevNode->next;
            i++;
        }

        Node * curr=prevNode->next;

        //step2;
        Node * newnode=new Node(data);
        //step3;
        prevNode->next=newnode;
        //step4;
        newnode->prev=prevNode;
        //step5;
        curr->prev=newnode;
        //step6;
        newnode->next=curr;


    }

 }

 void deleteFromPos(Node* & head,Node*&tail,int position){
       int len=getlength(head);
    if(head==NULL){
        cout << "Linked-list is empty";
        return;
    }

    if(head->next==NULL){
        //single node
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete(temp);
        return;
    }
    //int len=getlength(head);
    if(position>len){
        cout << "enter a valid position" << endl;
        return;
    }

if(position==1){
    //want to delete the first node
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    delete(temp);
    return;

}
//int len=getlength(head);
  if(position==len){
    //delete last node
    Node* temp=tail;
    tail=tail->prev;
    temp->prev=NULL;
    tail->next=NULL;
    delete(temp);
    return;

}

//delete from middle of linked-list

//step1; find left,curr,right

int i=1;
Node* left=head;
while(i<position-1){
    left=left->next;
    i++;
}
Node* curr=left->next;
Node * right=curr->next;

//step2;
left->next=right;
//step3;
right->prev=left;
//step4:
curr->next=NULL;
curr->prev=NULL;
delete(curr);
return;


 }

int main(){

    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node * head=first;
    Node * tail=third;

    first->next=second;
    second->prev=first;

    second->next=third;
    third->prev=second;

    //print(first);
    //cout << endl;

    InsertAthead(head,tail,101);

    //cout << endl;
   // print(head);
   // cout << endl;

    InsertAtTail(head,tail,500);

   // cout << endl;
   // print(head);

     //cout << endl;

    InsertAtPosition(head,tail,200,5);

    cout << endl;
    print(head);
    cout<< endl;

    deleteFromPos(head,tail,8);

    cout << endl;
    print(head);
    cout << endl;

    

    return 0;
}







