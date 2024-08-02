# CODE

class Solution:
    
    # using iterative dynamic programming
    def editDistance(self, s, t):
        n, m = len(s), len(t)
        dp = [[float('inf') for j in range(m + 1)] for i in range(n + 1)]
        
        for i in range(n + 1):
            for j in range(m + 1):
                if i == 0:
                    dp[i][j] = j
                elif j == 0:
                    dp[i][j] = i
                elif s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j], 
                                        dp[i - 1][j - 1], 
                                        dp[i][j - 1])
        return dp[n][m]


	# using lru_cache(None) decorator
	# it's like memoization but python take care of it.
    def editDistance(self, s, t):
        m = len(s)
        n = len(t)
        
        # importing lru_cache
        from functools import lru_cache
        @lru_cache(None)
        
        def dfs(i = m - 1, j = n - 1):
            nonlocal s, t
            if i < 0 and j < 0:
                return 0
            if i < 0 or j < 0:
                return max(i, j) + 1
            if s[i] == t[j]:
                return dfs(i - 1, j - 1)
            return min(dfs(i - 1, j), 
                       dfs(i, j - 1), 
                       dfs(i - 1, j - 1)) + 1
                       
        return dfs()