# CODE

class Solution:
    def series(self, n):
        res = [0, 1]
        for _ in range(2, n + 1):
            res.append((res[-1] + res[-2]) % (10 ** 9 + 7))
        return res