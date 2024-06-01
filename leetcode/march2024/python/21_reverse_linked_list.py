# INTUITION
# If we can reverse the current pair by keeping track of pair's next pointer, we 
# can easily able to reverse the whole list.

# APPROACH
# 1. Check head == NULL and head -> next == NULL as in this case list is already reversed
# 2. Track 3 pointers - prev (p), current(c) and next(n)
# 3. Traverse the whole list until c is not NULL:
#     a. Reverse the pair (p, c), shown in code
#     b. Move pointers - p to c, c to n and IF n exists then n to n -> next
# 4. Return p at the end as a new list

# TIME COMPLEXITY
# TC: O(n)

# SPACE COMPLEXITY
# SC: O(1)

# CODE

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if (head is None) or (head.next is None): return head
        p = None
        c = head
        n = head.next
        while c:
            c.next = p
            p = c
            c = n
            if n: n = n.next
        return p