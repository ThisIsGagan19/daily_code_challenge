# CODE

from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return list()
        
        path = []

        def post_order_traversal(node):
            if node is None:
                return
            post_order_traversal(node.left)
            post_order_traversal(node.right)
            path.append(node.val)
        
        post_order_traversal(root)
        return path