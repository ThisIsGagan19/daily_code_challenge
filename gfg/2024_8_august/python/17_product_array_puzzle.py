# CODE

class Solution:
    def productExceptSelf(self, nums):
        n, zero_cnt, product = len(nums), 0, 1
        res = [0] * n
        
        for i in range(n):
            if nums[i] != 0: product *= nums[i]
            else: zero_cnt += 1
                
        for i in range(n):
            if zero_cnt == 0: res[i] = product // nums[i]
            elif zero_cnt == 1 and nums[i] != 0: res[i] = 0
            elif zero_cnt == 1 and nums[i] == 0: res[i] = product
            else: res[i] = 0
        
        return res