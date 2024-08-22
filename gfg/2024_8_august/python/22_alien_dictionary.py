# CODE

from typing import List

class Solution:
    def findOrder(self, alien_dict: List[str], N: int, K: int) -> str:
        
        # Task 1: creating adjacency list
        adj_list = {ch: set() for word in alien_dict for ch in word}
        
        for i in range(N - 1):
            first, second = alien_dict[i], alien_dict[i + 1]
            common_length = min(len(alien_dict[i]), len(alien_dict[i + 1]))
            
            if len(first) > len(second) and first[:common_length] == second[:common_length]:
                return ""
            
            for ch in range(common_length):
                if first[ch] != second[ch]:
                    adj_list[first[ch]].add(second[ch])  # one way / no bidirectional edges
                    break
        
        
        # Task 2: Checking for cycles
        visited = {}
        path = []
        
        def DFS(char):
            if char in visited:
                return visited[char]
            
            visited[char] = True
            
            for nbr in adj_list[char]:
                if DFS(nbr):
                    return True
            
            visited[char] = False
            path.append(char)
            
        # As it is directed graph so, check for every node 
        # whether it contains cycle or not.
        for ch in adj_list:
            if DFS(ch):
                return ""
        
        # Task 3: Return the topological order
        return "".join(path[::-1])