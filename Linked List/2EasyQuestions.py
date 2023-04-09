class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

def takeInput1(): #TC = O(N^2)
    inputList=[int (ele) for ele in input().split()]
    head=None
    for currData in inputList:
        if currData==-1:
            break
        newNode=Node(currData)
        if head is None:
            head=newNode
        else:
            curr=head
            while curr.next is not None:
                curr=curr.next
            curr.next=newNode
    return head

def takeInput():
    inputList=[int (ele) for ele in input().split()]
    head=None
    tail=None
    for currData in inputList:
        if currData==-1:
            break
        newNode=Node(currData)
        if head is None:
            head=newNode
            tail=newNode
        else:
            tail.next=newNode
            tail=newNode
    return head

head=takeInput()

def printLL(head):
    while head is not None:
        print(str(head.data)+"->",end='')
        head=head.next
    print("None")
    return

printLL(head)

def length(head) :
    count=0
    while head is not None:
        #-1 wrong bcz it hasnt consider during takrInput()
        count+=1
        head=head.next
    return count
        
print(length(head))

def printIthNode(head, i):
    #Note : Assume that the Indexing for the singly linked list always starts from 0.
    c=0
    while head is not None:
        if c == i:
            print(head.data)
            return
        else:
            c+=1
            head=head.next
    return

printIthNode(head, 2)

def insertAtIRec(head,i,data):
    if i<0:
        return head
    if i==0:
        newNode=Node(data)
        newNode.next=head
        return newNode
    if head is None:
        return None
    smallHead=insertAtIRec(head.next,i-1,data)
    head.next=smallHead
    return head

def insertAtI(head,i,data):
    if i<0 or i>length(head):
        return head
    count=0
    prev=None
    curr=head
    while count<i:
        prev=curr
        curr=curr.next
        count=count+1
    newNode=Node(data)
    if prev is not None:
        prev.next=newNode
    else:
        head=newNode
    
    newNode.next=curr
    return head

head=insertAtI(head,2,6)
printLL(head)
head=insertAtI(head,0,9)
printLL(head)
head=insertAtI(head,7,10)
printLL(head)

def deleteNode(head, pos) :
    if pos<0 or pos>=length(head):
        return head
    c=0
    prev=None
    curr=head
    while c<pos:
        prev=curr
        curr=curr.next
        c+=1
    if prev is None:
        head=curr.next
        return head
    prev.next=curr.next
    return head

def findNode(head, x) :
    index=0
    while head is not None:
        if head.data==x:
            return index
        
        head=head.next
        index+=1
    return -1

def appendLastNToFirst(head, n) :
    l=length(head)
    if n==0 or head is None:
        return head
    curr=head
    c=0
    while c<l-n:
        tail=curr
        curr=curr.next
        c+=1
    newHead=curr
    tail.next=None
    temp=newHead
    c=0
    while c<n-1:
        temp=temp.next
        c+=1
    tail=temp
    tail.next=head
    head=newHead
    return head

def appendLastNToFirst(head, k) :
    
    if k==0 or head is None:
        return head
    
    fast = head
    slow = head

    for i in range(k):
        fast = fast.next
    while fast.next is not None:
        slow = slow.next #slow = reach at n-1 th node => new tail
        fast = fast.next #fast = original tail
    fast.next = head
    head = slow.next
    slow.next = None
    return head

def removeDuplicates(head) :
    if head is None:
        return head
    curr,temp=head,head.next
    while temp is not None:
        if curr.data!=temp.data:
            curr.next=temp
            curr=temp
        temp=temp.next
    curr.next=None
    return head

def printReverse(head) :
    if head is None:
        return
    printReverse(head.next)
    print(head.data,end=' ')