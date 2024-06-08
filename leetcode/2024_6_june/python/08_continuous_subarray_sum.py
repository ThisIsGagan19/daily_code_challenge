# CODE

from typing import List
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        mapboi = {0 : -1}
        prefix = 0

        for i in range(n):
            prefix = (prefix + nums[i]) % k
            if prefix in mapboi:
                if i - mapboi[prefix] > 1:
                    return True
            else:
                mapboi[prefix] = i
        
        return False