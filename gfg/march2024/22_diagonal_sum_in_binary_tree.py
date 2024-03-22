# INTUITION
# We can go in right direction there isn't any problem in that, point is how
# to track left nodes at that time. well, think of storing them in some data
# structure like queue or stack. Next time pick nodes from that data structure
# and do the same.

# APPROACH
# 1. Move in right direction from root as far as we can go
# 2. If left subtree exists for some nodes, store it in queue
# 3. Now, for that particular size/level of queue do the same for all nodes
#    present in queue
#    For all nodes in queue, pick one node traverse as far as we can go and store
#    left subtree root in queue
# 4. Maintain sum for each size/level
# 5. Store sum in result vector and return result

# TIME COMPLEXITY
# TC: O(n)

# SPACE COMPLEXITY
# SC: O(n)

# CODE

class Solution:
    def diagonalSum(self, root):
        res = []
        q = deque([root])
    
        while q:
            sum = 0
            sz = len(q)
            for _ in range(sz):
                node = q.popleft()
                while node:
                    sum += node.data
                    if node.left:
                        q.append(node.left)
                    node = node.right
            res.append(sum)
    
        return res