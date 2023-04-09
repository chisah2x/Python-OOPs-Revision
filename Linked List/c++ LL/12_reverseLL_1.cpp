#include "2_constructor.cpp"

Node *reverseLinkedListRec(Node *head){
    //Write your code here
    if(head== NULL || head->next == NULL)
        return head;
    Node* smallH = reverseLinkedListRec( head->next );
    Node* temp = smallH;
    while(temp -> next != NULL)
        temp = temp -> next;
    temp -> next = head;
    head -> next = NULL;
    return smallH;   
}

int main(){
    Node* head= takeInput();
    printLL(head);
    head = reverseLinkedListRec(head);
    printLL(head);
    return 0;
}