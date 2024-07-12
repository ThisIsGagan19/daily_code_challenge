# CODE

class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def hasPathSum(self, root, target):
        if root is None:
            return False
        if root.left is None and root.right is None:
            return target == root.data
        rem_sum = target - root.data
        return (self.hasPathSum(root.left, rem_sum) or 
                self.hasPathSum(root.right, rem_sum))