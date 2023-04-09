#include "2_constructor.cpp"

void printReverse(Node *head){
    if(head == NULL)
        return ;
    printReverse(head->next);
    cout<<head -> data << " ";
}

int main(){
	Node *head = takeInput();
    printLL(head);
	printReverse(head);
	return 0;
}