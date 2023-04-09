#include "2_constructor.cpp"

Node *removeDuplicates(Node *head){
    if(head == NULL || head -> next == NULL)
        return head;
    Node* t1=head, *t2 = head -> next;
    while(t2 != NULL){ //when t2 =NULL 
        if(t1 -> data == t2 -> data){
            Node* temp =t2 ;
            t2 = t2 -> next;
            t1 -> next =t2; // t2 - next = null it go up
            delete temp;           
        }
        else{
            t1=t2;
            t2 = t2 -> next;
        }
    }    
    return head;
}

int main(){
	Node *head = takeInput();
    printLL(head);
	head = removeDuplicates(head);
	printLL(head);
	return 0;
}