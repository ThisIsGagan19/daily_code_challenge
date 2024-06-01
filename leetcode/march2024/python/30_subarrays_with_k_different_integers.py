# INTUITION
# Standard Sliding Window Problem

# CODE

class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        
        def solve(nums, k):
            n = len(nums)
            res = start = end = 0
            count = {}
            while end < n:
                count[nums[end]] = count.get(nums[end], 0) + 1
                
                while len(count) > k:
                    count[nums[start]] -= 1
                    if count[nums[start]] == 0:
                        del count[nums[start]]
                    start += 1
                
                res += end - start + 1
                end += 1
            return res

        return solve(nums, k) - solve(nums, k - 1)