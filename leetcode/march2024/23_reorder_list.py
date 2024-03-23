# INTUITION
# Find middle, reverse second half and merge lists :)

# CODE

class Solution:
    def getMiddle(self, head):
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

    def reverseList(self, head):
        prev = None
        while head:
            next_node = head.next
            head.next = prev
            prev = head
            head = next_node
        return prev

    def reorderList(self, head):
        if not head or not head.next:
            return
        
        mid = self.getMiddle(head)
        reversed_second_half = self.reverseList(mid.next)
        mid.next = None
        
        while head and reversed_second_half:
            next_head = head.next
            next_reversed = reversed_second_half.next
            head.next = reversed_second_half
            head.next.next = next_head
            head = next_head
            reversed_second_half = next_reversed