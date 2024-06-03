# CODE

class Solution:
    def inorder(self, root, res, prev):
        if not root:
            return
        self.inorder(root.left, res, prev)
        if prev[0] != -1:
            res[0] = min(res[0], abs(root.data - prev[0]))
        prev[0] = root.data
        self.inorder(root.right, res, prev)
    
    def absolute_diff(self, root):
        res = [float('inf')]
        prev = [-1]
        self.inorder(root, res, prev)
        return res[0]