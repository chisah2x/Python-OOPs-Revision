#include "2_constructor.cpp"

Node *evenAfterOdd(Node *head){
    if(head == NULL)
        return head;
    Node *eH=NULL, *oH=NULL, *eT=NULL, *oT=NULL;
    
    while ( head!=NULL ){
        if(head->data % 2 != 0){
            if(oH == NULL){
                oH = head;
                oT = head;
            }
            else{
                oT -> next = head;
                oT = oT -> next;
            }
        }
        else{
            if(eH == NULL){
                eH = head;
                eT = head;
            }
            else{
                eT -> next = head;
                eT = eT -> next;
            }            
        }
        head = head -> next;
    }

    //important points to be noted
    if(oH == NULL)
        return eH;
    else{
        oT->next = eH;
    }
    if(eH!=NULL){
        eT->next = NULL;
    }
    return oH;
}

int main(){
	Node *head = takeInput();
	head = evenAfterOdd(head);
	printLL(head);
	return 0;
}