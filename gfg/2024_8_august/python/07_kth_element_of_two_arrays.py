# SOLUTION 1: Using Two Pointers

# TIME COMPLEXITY: O(n + m)
# SPACE COMPLEXITY: O(1)

# CODE 

class Solution:
    def kthElement(self, k, arr1, arr2):
        n1 = len(arr1)
        n2 = len(arr2)
        i = j = 0
        
        while (i < n1) and (j < n2):
            k -= 1
            if arr1[i] <= arr2[j]:
                if not k: return arr1[i]
                i += 1
            else:
                if not k: return arr2[j]
                j += 1
        
        while i < n1:
            k -= 1
            if not k: return arr1[i]
            i += 1
            
        while j < n2:
            k -= 1
            if not k: return arr2[j]
            j += 1
        
        return -1
    

# SOLUTION 2: Using Binary Search

# TIME COMPLEXITY: O(log(n) + log(m))
# SPACE COMPLEXITY: O(1)

# CODE 

import bisect

class Solution:
    def kthElement(self, k, a, b):
        n, m = len(a), len(b)
        
        l = min(a[0], b[0]) - 1
        h = max(a[n-1], b[m-1]) + 1
        
        while l <= h:
            mid = l + (h - l) // 2
            x = bisect.bisect_right(a, mid)
            y = bisect.bisect_right(b, mid)
            
            if x + y < k:
                l = mid + 1
            else:
                h = mid - 1
                
        return l