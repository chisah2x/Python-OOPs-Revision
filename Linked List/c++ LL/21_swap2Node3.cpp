//|j-i|=1  but i!=0 && j!=0 remaining
#include "2_constructor.cpp"

Node* swap2Node(Node* head,int i, int j){
    if(i==j || head==NULL)
        return head;
    Node* p1 = NULL,*p2 = NULL,*c1 = NULL, *c2 = NULL, *curr=head;
    int c=0;
    while(curr != NULL){
        if(c==i-1){
            p1 = curr;
            c1=curr->next;
        }
        if(c==j-1){
            p2=curr;
            c2=curr->next;
        }
        c+=1;
        curr = curr->next;
    }

    p1->next=c2;
    c1->next=c2->next;
    c2->next=c1;
    return head;
}
int main(){
    Node* head= takeInput();
    printLL(head);
    head = swap2Node(head,4,5);
    printLL(head);
    head = swap2Node(head,4,3);
    printLL(head);
    return 0;
}