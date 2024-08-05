# CODE

from collections import deque

class Solution:
    def bottomView(self, root):
        if root is None:
            return []
        view = {}
        q = deque([(root, 0)])
        while q:
            curr, index = q.popleft()
            view[index] = curr.data
            if curr.left:
                q.append((curr.left, index - 1))
            if curr.right:
                q.append((curr.right, index + 1))
        res = []
        for i in sorted(view.keys()):
            res.append(view[i])
        return res