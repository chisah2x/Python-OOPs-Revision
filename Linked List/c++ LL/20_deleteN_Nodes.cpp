#include "2_constructor.cpp"

Node *skipMdeleteN(Node *head, int M, int N){
    if(M == 0 || head == NULL)
        return NULL;
    if(N==0)
        return head;
    Node* curr = head, *temp = NULL;
    while(curr!=NULL){
        int take=0,skip=0;
        while(curr!=NULL && take<M){
            if(temp == NULL)
                temp = curr;
            else{
                temp -> next = curr;
                temp = curr;
            }
            curr=curr->next;
            take++;
        }
        while(curr!=NULL && skip<N){
            Node* newNode = curr;
            delete curr;
            curr=newNode->next;
            skip++;
        }
        /* for me this is better
        while(curr!=NULL && skip<N){
            Node* newNode = curr->next;
            delete curr;
            curr=newNode;
            skip++;
        }
        */
    }
    if(temp!=NULL)
        temp -> next = NULL;
    return head;
}

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		printLL(head);
	}
	return 0;
}