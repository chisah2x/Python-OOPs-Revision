#include<iostream>
using namespace std;
#include "0_constructor.cpp"

class Pair{
    public:
    Node* head;
    Node* tail;
};

Node* takeInput(){
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

void printLL(Node *head){ 
    Node * temp=head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp =  temp -> next;
    }
    cout<<endl;
}

Node *reverseLinkedList(Node *head) {
    
    if(head == NULL || head -> next == NULL)
        return head;
    Node* curr = head , *prev = NULL;
    while( curr != NULL){
        Node* nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;
}

int main(){
    Node* head= takeInput();
    printLL(head);
    head = reverseLinkedList(head);
    printLL(head);
    return 0;
}