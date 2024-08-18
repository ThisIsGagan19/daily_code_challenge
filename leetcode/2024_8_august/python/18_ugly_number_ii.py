# CODE

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_set = set()
        ugly_set.add(1)
        res = 1
        for i in range(n):
            res = min(ugly_set)
            ugly_set.remove(res)
            ugly_set.add(res * 2)
            ugly_set.add(res * 3)
            ugly_set.add(res * 5)
        return res