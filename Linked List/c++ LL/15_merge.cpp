#include "2_constructor.cpp"

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1 == NULL && head2 == NULL){
        return head1;
    }
    else if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    
    Node* finalH=NULL , *tail=NULL;
    if(head2 ->data > head1 ->data){
        finalH = head1;
        tail=head1;
        head1 = head1 -> next;
    }
    else{
        finalH = head2;
        tail=head2;
        head2 = head2 -> next;
    }
    while( head1 != NULL && head2 != NULL ){
        if(head2 ->data > head1 ->data){
            tail -> next = head1;
            head1 = head1 -> next;
            tail = tail -> next;
        }
        else{
            tail -> next = head2;
            head2 = head2 -> next;
            tail = tail -> next;
        }
    }
	while( head1 != NULL ) {
        tail -> next = head1;
        head1 = head1 -> next;
        tail = tail -> next;
    } 
    while( head2 != NULL ) {
        tail -> next = head2;
        head2 = head2 -> next;
        tail = tail -> next;
    }  
    return finalH;    
}

// int main(){
// 	int t;
// 	cin >> t;
// 	while (t--)	{
// 		Node *head1 = takeInput();
// 		Node *head2 = takeInput();
// 		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
// 		printLL(head3);
// 	}
// 	return 0;
// }