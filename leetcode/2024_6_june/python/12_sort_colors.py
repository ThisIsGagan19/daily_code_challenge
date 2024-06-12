# CODE

from typing import List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zero = one = 0
        two = len(nums) - 1
        while one <= two:
            if nums[one] == 0:
                nums[zero], nums[one] = nums[one], nums[zero]
                one += 1
                zero += 1
            elif nums[one] == 2:
                nums[two], nums[one] = nums[one], nums[two]
                two -= 1
            else:
                one += 1