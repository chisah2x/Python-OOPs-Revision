#include "2_constructor.cpp"

Node *deleteNode(Node *head, int pos){
    if(head == NULL)
        return head;

    int count=0;
    Node* prevNode=head, *a = NULL;
    
    if(pos == 0){
        a=prevNode;
        head = prevNode -> next;
        delete a;
        return head;
    }

    while ( prevNode != NULL && count < pos-1){
        prevNode = prevNode -> next;
        count += 1;
    }
    if(prevNode -> next == NULL || prevNode == NULL) //point to be noted
        return head;
    a=prevNode -> next;
    Node* b= a->next;
    delete a;
    
    prevNode -> next =b;
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
    if(pos<0)
        return head;

    //by dry run only u will understand the pos of this line
    //also we are not adding any node at last like in insertatIth
    if(head == NULL) 
        return NULL;
    if(pos==0){
        Node* a = head -> next;
        delete head;
        return a;
    }
    
    Node* prevHead = deleteNodeRec(head -> next , pos-1);
    head -> next = prevHead;
    return head;
}

int main(){
	Node *head = takeInput();
	int pos;
	cin >> pos;
    printLL(head);
	head = deleteNode(head, pos);
	printLL(head);
	return 0;
}