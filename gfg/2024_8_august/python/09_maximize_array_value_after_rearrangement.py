# CODE

class Solution:
    def Maximize(self, a):
        idx = res = 0
        a.sort()
        for i in a:
            res += (i * idx)
            idx += 1
        return res % (10 ** 9 + 7)