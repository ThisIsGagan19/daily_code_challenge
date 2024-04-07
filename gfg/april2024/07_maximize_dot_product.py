# CODE

class Solution:
    def solve(self, a, b, i, j, cache):
        if j < 0:
            return 0
        if i < 0:
            return -1e9
        if cache[i][j] != -1:
            return cache[i][j]
        nottake = self.solve(a, b, i - 1, j, cache)
        take = a[i] * b[j] + self.solve(a, b, i - 1, j - 1, cache)
        cache[i][j] = max(take, nottake)
        return cache[i][j]
    
    def maxDotProduct(self, n, m, a, b):
        cache = [[-1] * m for _ in range(n)]
        res = self.solve(a, b, n - 1, m - 1, cache)
        return res