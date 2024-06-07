# CODE

import sys
class Solution:
    def maxOccured(self,n, l, r, maxx):
        x = [0] * (maxx + 2)
        for i in range(n):
            x[l[i]] += 1
            x[r[i] + 1] -= 1
        
        res = sum = 0
        maxiboi = -sys.maxsize - 1 # INT_MIN
        for i in range(maxx + 1):
            sum += x[i]
            if sum > maxiboi:
                maxiboi = sum
                res = i
        
        return res