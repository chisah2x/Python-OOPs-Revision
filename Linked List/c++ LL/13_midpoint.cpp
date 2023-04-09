#include "2_constructor.cpp"
Node *midPoint(Node *head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* slow = head , * fast = head -> next;
    while ( fast != NULL && fast -> next != NULL ){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;   
}
Node *reverseLinkedListRec(Node *head){
    if(head== NULL || head->next == NULL)
        return head;
    Node* smallH = reverseLinkedListRec( head->next );
    Node* tail = head -> next;
    head -> next = NULL;
    tail -> next = head;
    return smallH;   
}