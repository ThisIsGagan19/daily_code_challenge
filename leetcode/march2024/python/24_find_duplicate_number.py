# CODE

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(0, n):
            nums[nums[i] % n] += n
        for i in range(0, n):
            if nums[i] // n > 1: 
                res = i
            nums[i] %= n
        return res   