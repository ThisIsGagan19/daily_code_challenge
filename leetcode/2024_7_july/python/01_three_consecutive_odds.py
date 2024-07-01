# CODE

from typing import List
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = len(arr)
        for i in range(0, n - 2):
            if (arr[i] & 1) and (arr[i + 1] & 1) and (arr[i + 2] & 1):
                return True   
        return False