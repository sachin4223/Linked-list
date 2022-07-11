#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value= this->data;
        cout<<" this ka data is:"<<value<<endl;
        cout<<" this ka next is:"<<this->next<<endl;
        //memory free
        if(this->next!= NULL){
            delete next;
            this->next=NULL;
            cout<<" this ka next is:"<<this->next<<endl;// ye chal nhi rha hn
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};
// Insert at head
void insertAtFirst(Node* &head,int d){
    //create a node
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

//Insert at tail
void insertATLast(Node* &tail,int d){
    //create a new node
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
//Insert at any position
void insertAtPositio(Node* &head,Node* &tail,int position,int d){
   // when user want to insert at first position 
    if(position==1){
        insertAtFirst(head,d);
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
        insertATLast(tail,d);
        return;
    }

    //cretaing a node for d
    Node* NodeToInsert=new Node(d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;

    


}
void deleteNode(int position,Node* &head,Node* &tail){

    //deleting first node
    if(position==1){
     //head next node pe le jana hn and 1st position ki memory free krva deni hn
     Node* temp=head;
     head=head->next;
     //memory free first node( hmne es node ko heap mai bnaya hn to memory free hm destroctor se krenge)
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
        // if we delete the last element then this code will modify the value of tail
        // if(curr->next==NULL){
        //      tail=prev;
        //      delete curr;
        // }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}

//Print function print all linked list data
void Print(Node* &head){

    Node* temp= head;//we dont want to change head position that's why we pointing head throug temp

    while(temp!=NULL){
       
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    cout<<endl;
}


int main(){
    //create a new node
    Node* node1=new Node(10);//dynamically allocated memory
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

   // head pointed to node1
    Node* head=node1;
    Print(head);// 10
    cout<<head<<endl;

    // insertAtFirst(head,12);
    // Print(head);//10 12

    // insertAtFirst(head,15);
    // Print(head);// 10 12 15

    //tail is pointing to node1
    Node* tail=node1;
    insertATLast(tail,12);
    Print(head);

    insertATLast(tail,15);
    Print(head);

    insertAtPositio(head,tail,3,22);
    Print(head);

    insertAtPositio(head,tail,1,40);
    Print(head);

    insertAtPositio(head,tail,6,90);
    Print(head);
    
    cout<<"Head"<<head->data<<endl;
    cout<<"Tail"<<tail->data<<endl;

    deleteNode(3,head,tail);
    Print(head);
   // deleteNode(5,head,tail);
    // Print(head);

    
    return 0;
}
