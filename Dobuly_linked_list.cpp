#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prv;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prv=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for value: "<<val<<endl;
    }

};

void insertAtHead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prv=temp;
        head=temp;
    }
    
}

void insterAtTail(Node* &tail,Node* &head,int d){

    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
        Node* temp= new Node(d);
        tail->next=temp;
        temp->prv=tail;
        tail=temp;
    }  
    }


void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    // when user want to insert at first position 
    if(position==1){
        insertAtHead(head,tail,d);
        return; // we write return here bcz if i dont write then below code will run and same value insertes at 2nd position also
    }
    // when user insert any element at any position excluding 1st position
    Node* temp=head;
    int cnt=1; // we assume that we are intially on the 1st node
    
    //we have to traverse to position-1
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }

    // if we inset a element at the end then everyting is fine but we have to update the value of tail
    if(temp->next==NULL){
        insterAtTail(tail,head,d);
        return;
    }

    //create a new node
    Node* NodeToInsert=new Node(d);

    NodeToInsert->next=temp->next;
    temp->next->prv=NodeToInsert;
    NodeToInsert->prv=temp;
    temp->next=NodeToInsert;
}

void deleteNode(int position,Node* &head,Node* &tail){

    //deleting first node
    if(position==1){
     //head next node pe le jana hn and 1st position ki memory free krva deni hn
     Node* temp=head;
     temp->next->prv=NULL;
     head=temp->next;
     temp->next=NULL;
     delete temp;

    }
    else{
        //deleting any middle or last node
        Node* curr=head;
        Node* prev=head;

        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        //need to modify the below code for doubly linkedlist
        // if we delete the last element then this code will modify the value of tail
        // if(curr->next==NULL){
        //      tail=prev;
        //      delete curr;
        // }

        //for last node or middle
        curr->prv=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;


    }
}
// find the length of a linked list
void lengthOfLinkedlist(Node* &head){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    cout<<"Length of linkedlist is: "<<cnt<<endl;
}
// travesing through a linked list
void Print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}
int main(){

    // Node* node1=new Node(10);

    // Node* head= node1;
    // Node* tail= node1;

    // starting with 0 node
     Node* head= NULL;
     Node* tail= NULL;


    insertAtHead(head,tail,10);
    Print(head);
    cout<<"Head is:"<<head->data<<endl;
    cout<<"Tail is:"<<tail->data<<endl;

    lengthOfLinkedlist(head);

    insertAtHead(head,tail,20);
    Print(head);
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,90);
    Print(head);
    lengthOfLinkedlist(head);


    insterAtTail(tail,head,12);
    insterAtTail(tail,head,14);
    insterAtTail(tail,head,15);
    Print(head);
    lengthOfLinkedlist(head);
    cout<<"Head is:"<<head->data<<endl;
    cout<<"Tail is:"<<tail->data<<endl;

    insertAtPosition(head,tail,4,56);
     Print(head);
    lengthOfLinkedlist(head);
    cout<<"Head is:"<<head->data<<endl;
    cout<<"Tail is:"<<tail->data<<endl;

    return 0;
}
