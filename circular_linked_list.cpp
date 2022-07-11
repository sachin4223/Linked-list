#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=next;
    }

    ~Node(){
        int val= this->data;
        if(this->next!=NULL){
            delete next;
            next= NULL;
        }
        cout<<"Memory free for value: "<<val<<endl;

    }


};

void insertNode(Node* &tail,int element,int d){

   // this for empty list
    if(tail==NULL){
        Node* temp= new Node(d);
        tail=temp;
        temp->next=temp;
    }
    else{
        //Non-empty list
        //assume that the element is present in the list
        Node* cur=tail;

        while(cur->data!=element){
            cur=cur->next;
        }

        //element found --cur representing element wala node
        Node* temp=new Node(d);
        temp->next=cur->next;
        cur->next=temp;
        

    }
   // cout<<"tail ka data:"<<tail->data<<endl;


}

void deleteNode(Node* &tail,int value){

    //empty list
    if(tail==NULL){
        cout<<"List is empty, please check again"<<endl;
        return;
    }

    else{
        //non-empty
        //assumeing thatt the "value" is present in the linked list
        Node* pre=tail;
        Node* cur=pre->next;

        while(cur->data!=value){
           pre=cur;
           cur=cur->next;
           
        }
        // cur ab value ko point kr rha hn aur pre just 1 node piche cur se

        pre->next=cur->next;
         // when 1 node in the linkedlist
         if(pre==cur){
             tail=NULL;
         }
         //>=2 node in linkedlist
        else if(tail==cur){
            tail=pre;
        }
        cur->next=NULL;
        delete cur;


    }

}
void Print(Node* tail){

    Node* temp=tail;
    //empty
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    //both sol based on call by reference

    // cout<<temp->data<<" ";
    // temp=temp->next;
    // while(temp!=tail){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    // cout<<endl;

    //another way to travese with do- while loop

    // do{
    //     cout<<temp->data<<" ";
    //     temp=temp->next;

    // }while(temp!=tail);
    // cout<<endl;
   
   //call by pointer
    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    }while(tail!=temp);
    cout<<endl;
}
   
int main(){

    Node* tail=NULL;
    //this time our list is empty

    insertNode(tail,4,3);
    Print(tail);

    insertNode(tail,3,5);
    Print(tail);

    insertNode(tail,5,7);
    Print(tail);

    insertNode(tail,7,9);
    Print(tail);

    insertNode(tail,3,4);
    Print(tail);

    insertNode(tail,5,6);
    Print(tail);

    deleteNode(tail,3);
    Print(tail);





    return 0;
}