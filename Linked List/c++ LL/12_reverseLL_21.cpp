#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data =data;
        next=NULL;
    }
};
class Pair{
    public:
    Node* head;
    Node* tail;
};

Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    while(data!=-1){
        //Node n(data);//scope of static n deallocate after }
        Node* newNode = new Node(data);
        if(head==NULL)
            head=newNode;
        else{
            Node* currNode=head;
            while(currNode -> next !=NULL)
                currNode = currNode -> next;
            currNode -> next = newNode;
        }
        cin>>data;
    }
    return head;
}

void printLL(Node *head){ //printLL.head=copy of main.head add
    Node * temp=head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp =  temp -> next;
    }
    cout<<endl;
}

Pair reverseLinkedListRec(Node *head){
    if(head== NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallH = reverseLinkedListRec( head->next );
    smallH.tail -> next = head;
    head -> next = NULL;
    Pair ans ;
    ans.head = smallH.head;
    ans.tail = head;
    return ans;   
}

Node* reverseLL(Node* head){
    return reverseLinkedListRec(head).head;
}

int main(){
    Node* head= takeInput();
    printLL(head);
    head = reverseLL(head);
    printLL(head);
    return 0;
}