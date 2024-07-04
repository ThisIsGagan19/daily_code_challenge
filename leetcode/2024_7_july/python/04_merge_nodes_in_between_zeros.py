# CODE

from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = head.next
        sum_node = dummy
        while sum_node:
            sum = 0
            while sum_node.val != 0:
                sum += sum_node.val
                sum_node = sum_node.next
            dummy.val = sum
            sum_node = sum_node.next
            dummy.next = sum_node
            dummy = dummy.next
        return head.next