# CODE

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Solution:
    def is_sum_tree(self, node):
        if node is None:
            return True
            
        def solve(node):
            if node is None:
                return (True, 0)
            
            if (node.left is None) and (node.right is None):
                return (True, node.data)
            
            left_res = solve(node.left)
            right_res = solve(node.right)
            
            if (not left_res[0]) or (not right_res[0]):
                return (False, -1)
                
            return ((True, node.data + left_res[1] + right_res[1]) 
                     if node.data == (left_res[1] + right_res[1]) 
                     else (False, -1))
            
        return solve(node)[0]