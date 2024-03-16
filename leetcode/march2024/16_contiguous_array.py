# INTUITION
# Kadane's algorithm variation

# APPROACH
# Check out Kadane's algorithm

# TIME COMPLEXITY
# TC: O(n)

# SPACE COMPLEXITY
# SC: O(n) - for hashmap

# CODE

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        index = {}
        index[0] = -1
        len = cnt = 0
        for i, val in enumerate(nums):
            cnt += 1 if val == 1 else -1
            if cnt in index:
                len = max(len, i - index[cnt])
            else:
                index[cnt] = i
        return len