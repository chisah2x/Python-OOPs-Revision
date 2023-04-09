#include "2_constructor.cpp"

int findNode(Node *head, int x){
    int index=0;
    Node* temp = head;
    while (temp !=NULL){
        if(temp -> data == x){
            return index;
        }
        temp = temp -> next;
        index+=1;
    }
    return -1;
}
int findNodeRec(Node *head, int n){
    if(head == NULL )
        return -1;
    if(head -> data == n)
        return 0;
    int smallAns = findNodeRec ( head -> next , n );
    if(smallAns != -1)
        return 1 + smallAns;
    else 
        return -1;
}
int main(){
	Node *head = takeInput();
	int x;
	cin >> x;
    printLL(head);
	int ans = findNode(head, x);
    cout<<ans<<endl;
	return 0;
}