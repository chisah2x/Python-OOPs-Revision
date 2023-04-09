#include "2_constructor.cpp"

Node *bubbleSort(Node *head){
    int length = len(head);
    /* for optimization
    for(int i=0;i<length-1;i++){
        
        Node* curr = head, *prev = NULL;
        
        for(int j=0; j<length-1-i; j++){
    */
    for(int i=0;i<length;i++){
        Node* curr = head, *prev = NULL;
        while(curr->next != NULL){
            if(curr->data > curr->next->data){
                if(prev!=NULL){
                    Node* temp = curr->next->next;
                    curr->next->next =curr;
                    prev->next = curr->next;
                    curr->next=temp;
                    prev = prev->next;
                }
                else{
                    head = curr->next;
                    curr->next=head->next;
                    head -> next = curr;
                    prev = head;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}
int main(){
	Node *head = takeInput();
	head = bubbleSort(head);
	printLL(head);
}