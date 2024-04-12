# CODE

class Solution:
    def pairAndSum(self, n, arr):
        res = 0
        for b in range(32):
            count = 0
            for i in range(n):
                if arr[i] & (1 << b):
                    count += 1
            res += (count * (count - 1) // 2) * (1 << b)
        return res