#include "13_midpoint.cpp"

bool isPalindrome(Node *head){
    if(head== NULL || head->next == NULL)
        return true;
    Node* mid = midPoint(head);
    Node* head2 = mid -> next;
    mid -> next = NULL;
    head2 = reverseLinkedListRec ( head2 );
    while ( head2 != NULL){
        if( head -> data != head2 -> data )
            return false;
        head = head -> next ;
        head2 = head2 -> next ;
    }
    return true;
}
int main(){
	Node *head = takeInput();
	bool ans = isPalindrome(head);

	if (ans) cout << "true";
	else cout << "false";

	cout << endl;
return 0;
}