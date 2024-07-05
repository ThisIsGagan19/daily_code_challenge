# CODE

from typing import Optional, List
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        res = [-1, -1]
        miniboi = float("inf")

        prev = head
        curr = head.next
        idx = 1
        prev_critical = 0
        first_critical = 0

        while curr.next is not None:
            if ((curr.val < prev.val and curr.val < curr.next.val) or 
                (curr.val > prev.val and curr.val > curr.next.val)):

                if prev_critical == 0:
                    prev_critical = idx
                    first_critical = idx
                else:
                    miniboi = min(miniboi, idx - prev_critical)
                    prev_critical = idx
            idx += 1
            prev = curr
            curr = curr.next
        
        if miniboi != float("inf"):
            maxiboi = prev_critical - first_critical
            res = [miniboi, maxiboi]
        
        return res