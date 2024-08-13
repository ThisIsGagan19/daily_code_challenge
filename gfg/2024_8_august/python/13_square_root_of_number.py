# CODE 

class Solution:
    def floorSqrt(self, n): 
        start = 1
        end = n // 2
        res = 1
        
        while(start <= end):
            mid = start + ((end - start) >> 1)
            sqr = mid * mid
            
            if sqr == n:
                return mid
            
            if sqr <= n:
                start = mid + 1
                res = mid     # holding floor value
            else:
                end = mid - 1
        
        return res