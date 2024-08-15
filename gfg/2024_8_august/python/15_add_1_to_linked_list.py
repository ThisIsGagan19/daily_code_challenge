# NOTE: In python, there is recursion limit so you can't go over 
#       that. Hence, you have to go with iterative solution only.


# CODE

class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

class Solution:
    def reverseList(self, head):
        if not head:
            return
        curNode = head
        prevNode = head
        nextNode = head.next
        curNode.next = None
     
        while(nextNode):
            curNode = nextNode
            nextNode = nextNode.next
            curNode.next = prevNode
            prevNode = curNode
     
        return curNode
     
    def addOne(self, head):
        head = self.reverseList(head)
        k = head
        carry = 0
        prev = None
        head.data += 1
        
        while(head != None) and (head.data > 9 or carry > 0):
            prev = head
            head.data += carry
            carry = head.data // 10
            head.data = head.data % 10
            head = head.next
     
        if carry > 0:
            prev.next = Node(carry)
            
        return self.reverseList(k)