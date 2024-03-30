# CODE

class Solution:
    def minValue(self, root):
        if root is None: return -1
        while root.left is not None:
            root = root.left
        return root.data