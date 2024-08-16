# CODE

class Solution:
    def maximizeTheCuts(self, n, x, y, z):
        prev = [-1 for _ in range(n + 1)]
        size = [0, x, y, z]
        prev[0] = 0
        for i in range(1, 4):
            for j in range(1, n + 1):
                notTake = prev[j] if prev[j] >= 0 else -1
                take = 1 + prev[j - size[i]] if ((size[i] <= j) and (prev[j - size[i]] >= 0)) else -1
                prev[j] = max(notTake, take)
        if prev[n] < 0:
            return 0
        return prev[n]