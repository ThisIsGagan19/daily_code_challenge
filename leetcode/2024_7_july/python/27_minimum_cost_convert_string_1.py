# CODE

import heapq
from typing import List

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:

        # dijkstra algorithm
        def dijkstra(start: int, adj_list: List[List[tuple]]) -> List[int]:
            pq = [(0, start)]
            min_costs = [float("inf")] * 26
            while pq:
                curr_cost, curr_char = heapq.heappop(pq)
                if min_costs[curr_char] != float('inf'):
                    continue
                min_costs[curr_char] = curr_cost
                for target_char, conversion_cost in adj_list[curr_char]:
                    new_cost = curr_cost + conversion_cost
                    if (min_costs[target_char] == float('inf') or 
                        new_cost < min_costs[target_char]):
                        heapq.heappush(pq, (new_cost, target_char))
            return min_costs           

        # creating adjacency list
        adj_list = [[] for _ in range(26)]
        conversion_count = len(original)
        for i in range(conversion_count):
            adj_list[ord(original[i]) - ord('a')].append((ord(changed[i]) - ord('a'), cost[i]))

        # calculate shortest path of all conversions
        min_conversion_costs = [dijkstra(i, adj_list) for i in range(26)]

        # converting source to target
        res = 0
        for s, t in zip(source, target):
            if s != t:
                cost = min_conversion_costs[ord(s) - ord('a')][ord(t) - ord('a')]
                if cost == float('inf'):
                    return -1
                res += cost
        return res