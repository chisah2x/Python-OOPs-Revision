#include "2_constructor.cpp"

Node* insertNode(Node* head,int i,int data){
    Node* newNode = new Node(data);
    if(i==0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    int count=0;
    Node* prevNode=head;
    //prevNode != NULL covers len>i  && at end as well
    while ( prevNode != NULL && count < i-1){
        prevNode = prevNode -> next;
        count += 1;
    }
    if( prevNode != NULL){
        Node* a = prevNode -> next;
        prevNode -> next = newNode;
        newNode -> next = a;
    }
    return head;
}
Node* insertNodeRec(Node *head, int i, int data) {
	// Write your code here
    if(i<0)
        return head;
    if(i==0){
        Node* newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }
    //for len>i , i=2 and head == NULL one case
    if(head == NULL) //so no need to calculate length, 
        return NULL;
    Node* prevHead = insertNode(head -> next , i-1, data);
    head -> next = prevHead;
    return head;
}
int main(){
    Node* head= takeInput();
    printLL(head);
    int i,data;
    cin >>i >>data;
    head=insertNode(head,i,data);
    printLL(head);
    return 0;
}