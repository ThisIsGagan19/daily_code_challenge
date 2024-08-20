# CODE

from collections import defaultdict, deque

class Solution:
    def minTime(self, root, target):
        adj = defaultdict(list)
        x = None

        def buildAdjList(root):
            nonlocal x
            if root is None:
                return

            if root.left:
                adj[root].append(root.left)
                adj[root.left].append(root)

            if root.right:
                adj[root].append(root.right)
                adj[root.right].append(root)

            if root.data == target:
                x = root

            buildAdjList(root.left)
            buildAdjList(root.right)

        buildAdjList(root)

        # BFS to calculate the maximum time to burn the entire tree
        q = deque([(x, 0)])
        vis = set()
        res = 0

        while q:
            u, time = q.popleft()
            res = max(res, time)
            vis.add(u)

            for neighbor in adj[u]:
                if neighbor not in vis:
                    vis.add(neighbor)
                    q.append((neighbor, time + 1))

        return res