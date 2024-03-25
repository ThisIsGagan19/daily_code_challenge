# INTUITION
# Try to mark the visited values with something and when visited again 
# we get our result. Hint - change their sign

# CODE

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for val in nums:
            if nums[abs(val) - 1] < 0: res.append(abs(val))
            else: nums[abs(val) - 1] *= -1
        return res