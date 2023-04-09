#include "2_constructor.cpp"

Node* deleteAlternateNode(Node* head){
    Node* temp = head;
    while (temp != NULL && temp -> next != NULL)  {
        Node* temp2 = temp -> next;
        temp -> next = temp2 -> next;
        delete temp2;
        temp = temp -> next;
    }
    return head;    
}

int main(){
	Node *head = takeInput();
	printLL(head);
	head = deleteAlternateNode(head);
	printLL(head);
	return 0;
}