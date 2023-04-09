//i!=0 && j!=0
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
    p2->next=c1;
    Node* temp=c1->next;
    c1->next=c2->next;
    c2->next=temp;
    return head;
}
int main(){
    Node* head= takeInput();
    printLL(head);
    head = swap2Node(head,4,2);
    printLL(head);
    head = swap2Node(head,1,5);
    printLL(head);
    return 0;
}