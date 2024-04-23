# CODE

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        
        adj_list = [[] for _ in range(n)]
        indegree = [0] * n
        res = []

        # creating adjacency list and calculating indegree
        for e in edges:
            adj_list[e[0]].append(e[1])
            adj_list[e[1]].append(e[0])
            indegree[e[0]] += 1
            indegree[e[1]] += 1

        # adding leaf nodes into queue
        q = deque()
        for i in range(n):
            if indegree[i] == 1:
                q.append(i)
                indegree[i] -= 1

        while q:
            s = len(q)
            res.clear()
            for _ in range(s):
                curr = q.popleft()
                res.append(curr)
                for nbr in adj_list[curr]:
                    indegree[nbr] -= 1
                    if indegree[nbr] == 1:
                        q.append(nbr)
        
        return res