# INTUITION
# As we don't have head pointer we have only one direction to move i.e. forward
# hence, the only way to delete current element is by replacing it with front element.

# APPROACH
# 1. Move in forward direction.
# 2. Replace current element data with next element data.
# 3. After reaching to end element delete last element with NULL pointer.

# TIME COMPLEXITY
# TC: O(n)

# SPACE COMPLEXITY
# SC: O(1)

# CODE

class Solution:
    def deleteNode(self, del_node):
        if del_node is None:
            return
        nextboi = del_node.next
        while nextboi:
            del_node.data = nextboi.data
            nextboi = nextboi.next
            if nextboi:
                del_node = del_node.next
        del_node.next = None