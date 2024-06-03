# CODE

class Solution:
	def min_operations(self, nums):
		n = len(nums)
        dp = [1] * n
        
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j] and nums[i] - nums[j] >= i - j:
                    dp[i] = max(1 + dp[j], dp[i])
        
        return n - max(dp)