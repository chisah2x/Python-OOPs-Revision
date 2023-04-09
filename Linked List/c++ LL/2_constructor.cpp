#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data =data;
        next=NULL;
    }
};

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;//point to be noted
    Node* tail = NULL;
    while(data!=-1){
        Node* newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;        }        
        else{
            tail -> next = newNode;
            tail = tail -> next;         }
        cin>>data;
    }
    return head;
}
void printLL(Node *head){ 
    Node * temp=head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp =  temp -> next;
    }
    cout<<endl;
}
int length(Node *head){
    int len=0;
    Node * temp=head;
    while(temp != NULL){
        temp =  temp -> next;
        len+=1;
    }
    return len;
}