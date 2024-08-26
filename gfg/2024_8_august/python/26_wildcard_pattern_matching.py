# CODE

class Solution:
    def wildCard(self, pattern, string):
        n, m = len(string), len(pattern)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True
        
        for j in range(1, m + 1):
            if pattern[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if pattern[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                elif pattern[j - 1] == '?' or string[i - 1] == pattern[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]

        return dp[n][m]