#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
// 1
// 4 4 7 8 3 36 8 17 26 7 7 -1
// 10

// 2
// 3 4 5 2 6 1 9 -1
// 0
// 9 8 4 0 7 8 -1
// 3
Node *takeinput(){
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)	{
		Node *newNode = new Node(data);
		if (head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}
void printIthNode(Node *head, int i){
    int c=0;
    Node *temp=head;
    while(c<i && temp != NULL){
        c+=1;
        temp = temp -> next;
    }
    if(temp != NULL){
        cout<<temp->data<<" ";
    }
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}