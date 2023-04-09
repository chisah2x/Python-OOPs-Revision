#include "2_constructor.cpp"

Node *kReverse(Node *head, int k){
    if(k<=1)
        return head;
    Node* curr = head;
    Node* prev = NULL;
    Node* frwd = NULL;
    int c=0;
    while(c<k && curr != NULL){
        frwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = frwd;
        c+=1;
    }
    //head->next is very important logic here
    if(frwd != NULL)
        head -> next = kReverse(frwd , k);
    return prev;
}

int main(){
	Node *head = takeInput();
	int k;
	cin >> k;
	head = kReverse(head, k);
	printLL(head);	
	return 0;
}