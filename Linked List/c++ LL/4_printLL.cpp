#include<iostream>
using namespace std;
#include "0_constructor.cpp"

void printLL(Node *head){ //printLL.head=copy of main.head add
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

//recursive
int lengthRec(Node *head) {
    // Write your code here
    if(head == NULL)
        return 0;
    int smallLen=lengthRec( head -> next);
    return 1+smallLen;  
}

int main(){
    //statically
    Node n1(1);
    Node *head=&n1; //dynamic

    Node n2(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node n5(5);

    n1.next=&n2;
    n2.next=n3;
    n3->next=n4;
    n4->next=&n5;

    printLL(head);//main.head
    int l=lengthRec(head);
    cout<<l<<endl;

    l=length(head);
    cout<<l<<endl;
}