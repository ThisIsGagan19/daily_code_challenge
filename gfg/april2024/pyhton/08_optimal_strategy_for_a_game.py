# INTUITION
# Another player will try to maximize his score, but take it like he will try to 
# minimize your score. So, he will choose the path which will give you minimum
# score.

# TIME COMPLEXITY
# O(n * n)

# SPACE COMPLEXITY
# O(n * n)

# CODE

class Solution:
    def solve(self, i, j, arr, cache):
        if j < i: return 0
        if cache[i][j] != -1: return cache[i][j]
        take_left = arr[i] + min(self.solve(i + 2, j, arr, cache), self.solve(i + 1, j - 1, arr, cache))
        take_right = arr[j] + min(self.solve(i + 1, j - 1, arr, cache), self.solve(i, j - 2, arr, cache))
        cache[i][j] = max(take_left, take_right)
        return cache[i][j]
    
    def optimalStrategyOfGame(self, n, arr):
        cache = [[-1] * n for _ in range(n)]
        return self.solve(0, n - 1, arr, cache)