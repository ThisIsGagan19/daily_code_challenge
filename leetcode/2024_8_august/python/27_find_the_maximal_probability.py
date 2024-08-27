# CODE

from typing import List

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        distance = [0] * n
        distance[start] = 1
        for _ in range(n - 1):
            change = False
            for i, (u, v) in enumerate(edges):
                if distance[u] * succProb[i] > distance[v]:
                    distance[v] = distance[u] * succProb[i]
                    change = True
                if distance[v] * succProb[i] > distance[u]:
                    distance[u] = distance[v] * succProb[i]
                    change = True
            if not change:
                break
        return distance[end]