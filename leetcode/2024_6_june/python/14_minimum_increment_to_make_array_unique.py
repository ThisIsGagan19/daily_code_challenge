# CODE

from typing import List
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        nums.sort()
        for i in range(1, n):
            if nums[i] <= nums[i - 1]:
                inc = nums[i - 1] - nums[i] + 1
                nums[i] = nums[i - 1] + 1
                res += inc
        return res