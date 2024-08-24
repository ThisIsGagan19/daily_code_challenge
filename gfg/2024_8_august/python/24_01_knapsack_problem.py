# CODE

class Solution:
    def knapSack(self, w, wt, val):
        n = len(wt)
        dp = [[-1 for _ in range(w + 1)] for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = 0
        for i in range(w + 1):
            dp[0][i] = 0
        for i in range(1, n + 1):
            for j in range(1, w + 1):
                if wt[i - 1] <= j:
                    include = val[i - 1] + dp[i - 1][j - wt[i - 1]]
                    exclude = dp[i - 1][j]
                    dp[i][j] = max(include, exclude)
                else:
                    dp[i][j] = dp[i - 1][j]
        return dp[n][w]