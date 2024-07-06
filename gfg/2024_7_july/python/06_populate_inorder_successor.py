# CODE

class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
        self.next = None


class Solution:
    def populateNext(self, root):
        parent = [None]
        
        def reverse_inorder(node):
            if node is None:
                return
            reverse_inorder(node.right)
            node.next = parent[0]
            parent[0] = node
            reverse_inorder(node.left)
        
        reverse_inorder(root)