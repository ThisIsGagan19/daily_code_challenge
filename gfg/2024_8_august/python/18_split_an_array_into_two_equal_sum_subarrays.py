# CODE

class Solution:
    def canSplit(self, arr):
        total_sum = sum(arr)
        if total_sum % 2 != 0:
            return False
        prefix_sum = 0
        suffix_sum = total_sum
        for i in range(len(arr) - 1):
            prefix_sum += arr[i]
            suffix_sum -= arr[i]
            if prefix_sum == suffix_sum:
                return True
        return False