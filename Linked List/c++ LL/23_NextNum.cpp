#include "2_constructor.cpp"

int add1(Node* head){
    if(head == NULL)
        return 1;
    int carry = add1(head -> next);
    int sum = head -> data + carry;
    head -> data = sum % 10;
    return sum / 10;   
}

Node* addOne(Node* head){
    int carry = add1(head);
    if(carry){
        Node* newNode = new Node(carry);
        newNode -> next = head;
        newNode -> data = carry;
        head = newNode;
    }
    return head;
}

int main(){
	Node *head = takeInput();
	printLL(head);
	head = addOne(head);
	printLL(head);
	return 0;
}