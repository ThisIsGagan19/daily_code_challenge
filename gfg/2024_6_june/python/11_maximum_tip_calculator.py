# CODE

from typing import List
class Solution:
    def maxTip(self, n : int, x : int, y : int, arr : List[int], brr : List[int]) -> int:
        tips = zip(arr, brr)
        tips_sorted = sorted(tips, key = lambda t: abs(t[0] - t[1]), reverse = True)
        cntA, cntB, res = 0, 0, 0
        for i, j in tips_sorted:
            if (i >= j and cntA < x) or (cntB == y):
                res += i
                cntA += 1
            else:
                res += j
                cntB += 1
        return res