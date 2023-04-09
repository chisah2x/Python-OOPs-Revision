#include "15_merge.cpp"
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
Node *mergeSort(Node *head){
    if(head == NULL || head -> next == NULL)
        return head;
    Node *mid = midPoint(head);
    Node *head1 = head;
    Node *head2 = mid -> next;
    mid -> next = NULL;
    Node* half1 = mergeSort(head1);
    Node* half2 = mergeSort(head2);
    Node* finalH = mergeTwoSortedLinkedLists( half1, half2 );
    return finalH;
}
int main(){
	Node *head = takeInput();
	head = mergeSort(head);
    printLL(head);
	return 0;
}