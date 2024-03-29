# CODE

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxiboi = max(nums)
        n = len(nums)
        res = start = end = 0
        for end in range(n):
            if nums[end] == maxiboi:
                k -= 1
            while k == 0:
                if nums[start] == maxiboi:
                    k += 1
                start += 1
            res += start
        return res