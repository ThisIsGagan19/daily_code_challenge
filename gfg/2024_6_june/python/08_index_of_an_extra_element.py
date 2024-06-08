# CODE

class Solution:
    def findExtra(self, n, a, b):
        left = 0
        right = n - 1
        while left < right:
            mid = left + ((right - left) >> 1)
            if b[mid] == a[mid]:
                left = mid + 1
            else:
                right = mid
        return left