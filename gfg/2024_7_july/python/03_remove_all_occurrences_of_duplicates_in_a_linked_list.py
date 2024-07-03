# CODE

class Node :
        def __init__(self, val):
            self.data = val
            self.next = None

class Solution:
    def removeAllDuplicates(self, head):
        parent = dummy = Node(0)
        dummy.next = head
        
        while head and head.next:
            if head.data == head.next.data:
                curr_data = head.data
                while head and head.data == curr_data:
                    head = head.next
                parent.next = head
            else:
                parent, head = head, head.next
            
        return dummy.next