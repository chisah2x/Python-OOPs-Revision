#include "2_constructor.cpp"

Node *swap2Nodes(Node *head, int i, int j){
    if(i==j)
        return head;
    Node* p1 = NULL,*p2 = NULL,*c1 = NULL, *c2 = NULL, *curr=head,*prev = NULL;
    int c=0;
    while(curr != NULL){
        if(c==i){
            p1 = prev;
            c1=curr;
        }
        if(c==j){
            p2=prev;
            c2=curr;
        }
        c+=1;
        prev=curr;
        curr = curr->next;
    }
    if(p1 != NULL)
        p1->next=c2;
    else
        head=c2;
    if(p2 != NULL)
        p2->next=c1;
    else
        head=c1;
    Node* temp = c2->next;
    c2->next = c1->next;
    c1->next = temp;
    return head;
}
int main(){
    Node* head= takeInput();
    printLL(head);
    head = swap2Nodes(head,2,2);
    printLL(head);
    head = swap2Nodes(head,0,5);
    printLL(head);
    head = swap2Nodes(head,4,0);
    printLL(head);
    return 0;
}