#include "2_constructor.cpp"

//TC = O(N2) 0 <= N < M Where 'M' is the size of the singly linked list.
Node *appendLastNToFirst1(Node *head, int n){
    if(head == NULL) return NULL;

    while(n){
        Node* temp = head, *p= NULL;
        while(temp->next){
            p = temp;
            temp = temp->next;
        }
        p->next = NULL;
        temp ->next = head;
        head = temp;
        n -= 1;
    }

    return head;
}
//TC = O(2*N)
Node *appendLastNToFirst(Node *head, int n){
    if(head == NULL || n==0) return head;
    int len=1;
    Node *tail=head;
    while(tail->next != NULL){
        tail =  tail -> next;
        len+=1;
    }
    n = len - n;

    Node* nH, *nT = head;

    while(n-1){
        nT = nT->next;
        n -= 1;
    }
    nH = nT->next;
    nT->next = NULL;
    tail -> next = head;
    return nH;
}

Node *appendLastNToFirst(Node *head, int n){
    if(n==0 || head == NULL){
        return head;
    }
    
    Node* tail=head, *nTail=head, *initialHead=head;
    int i=0;
    while(i<n){
        i+=1;
        tail = tail -> next;
    }
    while(tail -> next != NULL){
        tail = tail -> next;
        nTail = nTail -> next;
    }
    
    head = nTail -> next;
    nTail -> next = NULL;
    tail -> next = initialHead;
    return head;
}
int main(){
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeInput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		printLL(head);
	}
	return 0;
}