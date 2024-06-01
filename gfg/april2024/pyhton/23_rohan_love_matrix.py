# INTUITION
# The trick here is to either use matrix exponentiation or just to figure out 
# that at position a[1][0], values will always follow the fibonacci order.

# CODE

class Solution:
    def firstElement (self, n):
        if n == 1 or n == 2: return 1
        f = s = 1
        for _ in range(n - 2):
            r = (f + s) % 1000000007
            f = s
            s = r
        return r