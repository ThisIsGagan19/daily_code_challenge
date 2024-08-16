# CODE

from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        res = 0
        maxiboi = arrays[0][-1]
        miniboi = arrays[0][0]
        for i in range(1, len(arrays)):
            first = arrays[i][0]
            last = arrays[i][-1]
            res = max(last - miniboi, maxiboi - first, res)
            maxiboi = max(maxiboi, last)
            miniboi = min(miniboi, first)
        return res