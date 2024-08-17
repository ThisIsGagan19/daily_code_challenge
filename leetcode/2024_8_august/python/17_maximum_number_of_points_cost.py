# CODE

from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m, n = len(points), len(points[0])
    
        dp = points[0]
        
        left = [0] * n ## left side contribution
        right = [0] * n ## right side contribution
        
        for r in range(1, m):
            for c in range(n):
                if c == 0:
                    left[c] = dp[c]
                else:
                    left[c] = max(left[c - 1] - 1, dp[c])
            
            for c in range(n - 1, -1, -1):
                if c == n-1:
                    right[c] = dp[c]
                else:
                    right[c] = max(right[c + 1] - 1, dp[c])
                    
            for c in range(n):
                dp[c] = points[r][c] + max(left[c], right[c])
                
        return max(dp)