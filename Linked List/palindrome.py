from sys import setrecursionlimit
setrecursionlimit(10**5)

def isPalindrome(head) :
    if(head==None) or head.next is None:
        return True
    slow,fast=head,head
    while fast.next !=None and fast.next.next != None :
        slow=slow.next
        fast=fast.next.next
    mid = slow
    half2=mid.next
    mid.next=None
    
    curr=half2
    prev=None
    while curr is not None:
        next=curr.next
        curr.next=prev
        prev=curr
        curr=next
        
    half2=prev
    while half2 is not None:
        if half2.data != head.data:
            return False
        half2=half2.next
        head=head.next
    return True
