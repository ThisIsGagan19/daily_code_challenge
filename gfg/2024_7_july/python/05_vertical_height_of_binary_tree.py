# CODE

def verticalWidth(root):
    # base case
    if root is None: 
        return 0
    
    left = [0]
    right = [0]
    
    def inorder(root, pos, left, right):
        # base case
        if root is None:
            return
        
        # calling left
        inorder(root.left, pos - 1, left, right)
        
        # calculation
        if pos < left[0]:
            left[0] = pos
        elif pos > right[0]:
            right[0] = pos
        
        # calling right
        inorder(root.right, pos + 1, left, right)
    
    # calculate left and right in inorder function
    inorder(root, 0, left, right)
    
    return right[0] - left[0] + 1