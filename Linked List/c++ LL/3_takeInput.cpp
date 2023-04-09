#include<iostream>
using namespace std;
#include "0_constructor.cpp"

Node* takeInput1(){
    int data;
    cin>>data;
    Node* head = NULL;
    while(data!=-1){
        //Node n(data);//scope of static n deallocate after }
        Node* newNode = new Node(data);
        if(head==NULL)
            head=newNode;
        else{
            Node* currNode=head;
            while(currNode -> next !=NULL)
                currNode = currNode -> next;
            currNode -> next = newNode;
        }
        cin>>data;
    }
    return head;
}

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1){
        //Node n(data);//scope of static n deallocate after } 
        //so node are delete after while loop 
        //dynamically allocated required manual deallocation
        Node* newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
            
        else{
            tail -> next = newNode;
            tail = tail -> next; //OR tail=newNode
        }
        cin>>data;
    }
    return head;
}

void printLL(Node *head){ //printLL.head=copy of main.head add
    Node * temp=head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp =  temp -> next;
    }
}

int main(){
    Node* head= takeInput();
    printLL(head);

    Node* head1= takeInput1();
    printLL(head1);
    return 0;
}