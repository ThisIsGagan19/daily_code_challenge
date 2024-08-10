# CODE

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def rotate(self, head, k):
        start = end = head
        
        while end.next != None:
            end = end.next
        end.next = head
        
        while k:
            k -= 1
            start = start.next
            end = end.next
        
        end.next = None
        return start