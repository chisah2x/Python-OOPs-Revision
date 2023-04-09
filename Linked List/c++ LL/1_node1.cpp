#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

int main(){
    Node n1;
    n1.data = 5;
    
    Node n2;
    n2.data = 6;
    n1.next = &n2;

    Node n3;
    n3.data = 7;
    n2.next = &n3;

    n3.next = NULL;

    Node* head = &n1;

    //cout << head.data << endl; => error
    cout << head->data << n1.data << endl;
    cout << head->next->data << n2.data << n1.next->data<< endl;
    cout << head->next->next->data << endl;

    //dynamically
    Node* n10=new Node();
    n10->data = 11;
    Node* head2=n10;
    Node* n11=new Node;
    n11->data = 12;
    n10 -> next = n11;

    cout<<(*n10).data<<"  "<<head2 -> data<<"  "<<n11 -> data<<"  "
    <<n10 -> next<<"  "<<n11<<endl;

}