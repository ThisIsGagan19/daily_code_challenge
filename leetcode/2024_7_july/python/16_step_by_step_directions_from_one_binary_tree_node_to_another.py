# CODE

from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        
        # function to find root to node path
        def root_to_node_path(root: TreeNode, target: int, path: List[str]):
            if root is None:
                return False

            if root.val == target:
                return True
            
            # go left
            path.append('L')
            if root_to_node_path(root.left, target, path):
                return True
            path.pop()

            # go right
            path.append('R')            
            if root_to_node_path(root.right, target, path):
                return True
            path.pop()

            return False

        start_node_path = []
        end_node_path = []

        root_to_node_path(root, startValue, start_node_path)
        root_to_node_path(root, destValue, end_node_path)

        directions = []
        i = 0
        while(i < len(start_node_path) and 
                i < len(end_node_path) and 
                start_node_path[i] == end_node_path[i]):

                i += 1
        
        directions.extend('U' * (len(start_node_path) - i))
        directions.extend(end_node_path[i:])
        return "".join(directions)