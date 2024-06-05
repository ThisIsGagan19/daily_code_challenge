# INTUITION
# Let,
# Sum of array a = s1
# Sum of array b = s2

# Condition: s1 - a[i] + b[j] = s2 - b[j] + a[i]

# Simplification:
# 2 * (b[j] - a[i]) = s2 - s1
# b[j] - a[i] = (s2 - s1) / 2
# b[j] = a[i] + (s2 - s1) / 2
# Thus, we have to find above value in array a which equals to b[j]

# APPROACH
# 1. Find sum of both arrays, s1 and s2.
# 2. Evaluate target values as per above equation.
# 3. Sort the array b in order to apply binary search.
# 4. Traverse in array a and for each value, apply binary search and
#    find target value.
# 5. return -1 if target value not found for all element of array a.

# TIME COMPLEXITY
# O((n + m)*log(m)) 

# SPACE COMPLEXITY
# O(1)

# CODE

import bisect
class Solution:
    def findSwapValues(self, a, n, b, m):
        s1 = sum(a)
        s2 = sum(b)
        
        # if sum is odd, not possible
        if abs(s2 - s1) % 2:
            return -1
        
        sum_diff = (s2 - s1) // 2
        b.sort()
        
        for val in a:
            target = sum_diff + val
            if self.binary_search(b, target):
                return 1
        
        return -1
    
    def binary_search(self, arr, target):
        index = bisect.bisect_left(arr, target)
        return index < len(arr) and arr[index] == target