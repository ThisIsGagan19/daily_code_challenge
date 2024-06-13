# CODE

class Solution:
    def padovanSequence(self, n):
        MOD = 10**9 + 7
        if n < 3:
            return 1
        p0, p1, p2 = 1, 1, 1
        for i in range(3, n + 1):
            p_n = (p0 + p1) % MOD
            p0, p1, p2 = p1, p2, p_n
        return p2