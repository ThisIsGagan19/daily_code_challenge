# CODE

from typing import List

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        res = float("inf")
        no_of_ones = sum(nums)
        ones_count = nums[0]
        end = 0
        for start in range(len(nums)):
            if start != 0:
                ones_count -= nums[start - 1]
            while end - start + 1 < no_of_ones:
                end += 1
                ones_count += nums[end % len(nums)]
            res = min(res, no_of_ones - ones_count)
        return res