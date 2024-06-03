# INTUITION
# This question can be divided into 2 parts
# first find LCA & then find Kth ancestor of LCA.

# TIME COMPLEXITY
# O(n)

# SPACE COMPLEXITY
# O(n) -- for recursion stack

# CODE

class Solution:
    def __init__(self):
        self.arr = []
        self.visited = False
        
    def LCA(self, root, x, y):
        if not root: return None
        if root.data == x or root.data == y:
            return root
        a = self.LCA(root.left, x, y)
        b = self.LCA(root.right, x, y)
        if a and b: return root
        if a: return a
        return b
    
    def rootToNode(self, root, node):
        if not root: return
        if not self.visited:
            self.arr.append(root.data)
        if root == node:
            self.visited = True
        self.rootToNode(root.left, node)
        self.rootToNode(root.right, node)
        if not self.visited:
            self.arr.pop()
    
    def kthCommonAncestor(self, root, k, x, y):
        node = self.LCA(root, x, y)
        self.rootToNode(root, node)
        if len(self.arr) < k: return -1
        return self.arr[-k]