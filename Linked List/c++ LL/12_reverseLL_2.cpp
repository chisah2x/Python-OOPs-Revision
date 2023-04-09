#include "2_constructor.cpp"

Node *reverseLinkedListRec(Node *head){
    if(head== NULL || head->next == NULL)
        return head;
    Node* smallH = reverseLinkedListRec( head->next );
    Node* tail = head -> next;
    head -> next = NULL;
    tail -> next = head;
    return smallH;   
}

int main(){
    Node* head= takeInput();
    printLL(head);
    head = reverseLinkedListRec(head);
    printLL(head);
    return 0;
}