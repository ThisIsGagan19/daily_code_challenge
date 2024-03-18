# INTUITION
# For every node we have to take its left child then right child and to 
# maintain storing order we can use queue. Hence, we can achieve left to 
# right level order traversal.

# APPROACH
# 1. Take queue.
# 2. Take element from queue and push into result. 
# 3. For the each element taken from queue's front push its left and right 
#    element (if exists) in order, until the queue becomes empty.
# 4. Finally, return the resulted array/vector.

# TIME COMPLEXITY
# TC: O(heightOfTree) | O(n) - worst case

# SPACE COMPLEXITY
# SC: O(n)

# CODE

class Solution:
    def levelOrder(self, root):
        res = []
        if root is None:
            return res
        q = deque()
        q.append(root)
        while q:
            currNode = q.popleft()
            res.append(currNode.data)
            if currNode.left is not None:
                q.append(currNode.left)
            if currNode.right is not None:
                q.append(currNode.right)
        return res