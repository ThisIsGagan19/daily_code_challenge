# INTUITION
# Level order traversal variation

# APPROACH
# 1. Do level order traversal
# 2. Instead of storing from left to right, track boolean varialbe turn:
#     a. IF turn == true: store from left to right
#     b. IF turn == false: store left to right

# TIME COMPLEXITY
# TC: O(n)

# SPACE COMPLEXITY
# TC: O(n) - for queue

# CODE

class Solution:
    def zigZagTraversal(self, root):
        res = []
        turn = True
        q = deque([root])

        while q:
            sz = len(q)
            level = []
            for _ in range(sz):
                currNode = q.popleft()
                if currNode.left:
                    q.append(currNode.left)
                if currNode.right:
                    q.append(currNode.right)
                level.append(currNode.data)
            if turn:
                res.extend(level)
            else:
                res.extend(reversed(level))
            turn = not turn
        
        return res