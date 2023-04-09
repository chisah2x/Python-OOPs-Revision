#include<iostream>
using namespace std;
#include "0_constructor.cpp"

int main(){
    //statically
    Node n1(1);
    Node *head1=&n1;
    Node n2(2);
    n1.next=&n2;

    cout<<n1.data<<"  "<<head1 -> data<<"  "<<n2.data<<"  "
    <<n1.next<<"  "<<&n2<<endl;

    //dynamically
    Node* n10=new Node(10);
    Node* head2=n10;
    Node* n11=new Node(12);
    n10 -> next = n11;

    cout<<(*n10).data<<"  "<<head2 -> data<<"  "<<n11 -> data<<"  "
    <<n10 -> next<<"  "<<n11<<endl;
}