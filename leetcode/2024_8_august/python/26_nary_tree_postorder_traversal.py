# CODE

from typing import List

class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        path = []
        if root is None:
            return path

        # function for post order traversal
        def post_order_traversal(node):
            if node is None:
                return
            for child in node.children:
                post_order_traversal(child)
            path.append(node.val)
        
        post_order_traversal(root)
        return path