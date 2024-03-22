# INTUITION
# Recursion mirrors the bouncing of a ball, it returns after hitting the base case. 
# Utilizing this, we can track forward movement with a start pointer and, upon return, 
# compare values using start and end pointers. If they remain the same throughout traversal, 
# it signifies a palindrome.

# NOTE - Although the code isn't optimized and we could improve the time complexity by 
# tracking the middle of the linked list, but here I want to show how to use the 
# bouncing nature of recursion.

# CODE

class Solution:
    def solve(self, start, end):
        if end is None: return True
        res = self.solve(start, end.next) and (start[0].val == end.val)
        start[0] = start[0].next
        return res

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next: return True
        start = [head]
        return self.solve(start, head)