# INTUITION 
# As the graph has unit weight edges, we don't need to use 
# dijkstra, BFS will be enough


# TIME COMPLEXITY
# O(n), here n is V (No. of nodes) + E(No. of edges)


# SPACE COMPLEXITY 
# O(n), for the queue at each level


# CODE 

from collections import defaultdict

class Solution:
    def shortestPath(self, edges, n, m, src):
        
        # creating adjacency list
        adj_list = defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
            
        # BFS algorithm
        res = [-1] * n
        visited = set([src])
        q = [src]
        dist = 0
        while q:
            next_level_q = []
            for node in q:
                res[node] = dist
                for nbr in adj_list[node]:
                    if nbr not in visited:
                        next_level_q.append(nbr)
                        visited.add(nbr)
            q = next_level_q
            dist += 1
        
        return res