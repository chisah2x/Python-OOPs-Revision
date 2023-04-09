from aclss import takeInput, printLL, Node

def reverseLinkedListRec(head) :
    if head is None or head.next is None:
        return head
    smallH=reverseLinkedListRec(head.next)
    tail=head.next
    tail.next=head
    head.next=None
    return smallH

class Solution:
    def reverseList(self, head):
        if head is None or head.next is None:
            return head
            
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        
        return newHead

'''
# def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     pre, cur = None, head
    #     while cur:
    #         cur.next, pre, cur = pre, cur, cur.next
    #     return pre

    # node, head.next.next, head.next = reverseListRecu(head.next), head, None
	# return node

    def reverseList(self, head):
        return self._reverse(head)

    def _reverse(self, node, prev=None):
        if not node:
            return prev
        n = node.next
        node.next = prev
        return self._reverse(n, node)

class Solution{
    void reverse(struct Node* &head, struct Node*curr, struct Node*prev){
        if(curr == NULL){
            head = prev;    return;
        }
        
        reverse(head, curr->next, curr);
        curr -> next = prev;
    }
    public:
    
    struct Node* reverseList(struct Node *head)    {
        reverse(head, head, NULL);
        return head;
    }
};
'''

if __name__=='__main__':
    head = takeInput()
    printLL(head)
    newHead = Solution().reverseList(head)
    printLL(newHead)

    head = reverseLinkedListRec(newHead)
    printLL(head)
