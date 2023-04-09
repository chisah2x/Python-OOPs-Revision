import aclss

head = aclss.takeInput()
aclss.printLL(head)

def reverseListI(head):
    if head is None or head.next is None:
        return head
        
    prev = None
    curr = head
    
    while curr is not None:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
        
    return prev

head = reverseListI(head)
aclss.printLL(head)

def reverseLinkedListRec(head) :
    if head is None or head.next is None:
        return head
    smallH=reverseLinkedListRec(head.next)
    tail=head.next
    tail.next=head
    head.next=None
    return smallH

def reverse1(head):
    if head is None or head.next is None:
        return head
    smallHead=reverse1(head.next)
    curr=smallHead
    while curr.next is not None:
        curr=curr.next
    curr.next=head
    head.next=None
    return smallHead

def reverse2(head):
    if head is None or head.next is None:
        return head,head
    smallHead,smallTail=reverse2(head.next)
    smallTail.next=head
    head.next=None
    return smallHead,head
    
