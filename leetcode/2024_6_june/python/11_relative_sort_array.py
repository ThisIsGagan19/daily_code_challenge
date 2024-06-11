# CODE

from typing import List
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        maxiboi = max(arr1)
        count_sort = [0] * (maxiboi + 1)
        for val in arr1:
            count_sort[val] += 1
        res = []
        for val in arr2:
            while count_sort[val] > 0:
                res.append(val)
                count_sort[val] -= 1
        for val in range(maxiboi + 1):
            while count_sort[val] > 0:
                res.append(val)
                count_sort[val] -= 1
        return res