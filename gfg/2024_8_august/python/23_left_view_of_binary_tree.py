# CODE

def LeftView(root):
    if root is None: 
        return []
    res = []

    def solve(root, lvl):
        if root is None: return
        if len(res) == lvl: res.append(root.data)
        solve(root.left, lvl + 1)
        solve(root.right, lvl + 1)
    
    solve(root, 0)
    return res