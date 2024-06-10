# CODE

from typing import List
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        org_heights = heights.copy()
        heights.sort()
        res = 0
        for i in range(len(org_heights)):
            if org_heights[i] != heights[i]:
                res += 1
        return res