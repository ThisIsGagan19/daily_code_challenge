# CODE

from bisect import bisect_left, bisect_right

class Solution:   
    def countPairs(self, arr, brr):
        res = 0
        brr.sort()
        
        for val in arr:
            
            # sepecial case of 1
            if val == 1:
                continue
            
            # for 2, it is valid only for value 1 and values >= 5
            elif val == 2:
                res += bisect_right(brr, 1)
                res += len(brr) - bisect_left(brr, 5)
                
            # general case
            else:
                res += len(brr) - bisect_left(brr, val + 1)
                res += bisect_right(brr, 1) - bisect_left(brr, 1)
                
                # for 3, it is not valid ony for value 2.
                # so, remove those cases
                if val == 3:
                    res += bisect_right(brr, 2) - bisect_left(brr, 2)
                
                
        return res