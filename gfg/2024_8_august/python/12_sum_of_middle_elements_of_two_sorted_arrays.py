# INTUITION
# The solution uses binary search to efficiently find the sum of the middle
# elements of two sorted arrays by identifying a partition between them. 
# By ensuring that elements on the total left side (including left of both 
# arrays) of the partition are less than or equal to those on the right, the
# algorithm calculates the middle elements as the maximum of the left-side 
# elements and the minimum of the right-side elements from both arrays. 

# This approach leverages the sorted nature of the arrays to find the correct 
# partition in logarithmic time, avoiding the need to merge the arrays directly.


# TIME COMPLEXITY
# O(log(n))


# SPACE COMPLEXITY
# O(1)


# CODE

class Solution:
    def sum_of_middle_elements(self, arr1, arr2):
        n = len(arr1)
        start = 0
        end = n
        
        while(start <= end):
            mid_of_arr1 = (start + end) >> 1
            mid_of_arr2 = n - mid_of_arr1
            
            left_of_arr1 = 0 if mid_of_arr1 == 0 else arr1[mid_of_arr1 - 1] 
            left_of_arr2 = 0 if mid_of_arr2 == 0 else arr2[mid_of_arr2 - 1] 
            right_of_arr1 = 10 ** 7 if mid_of_arr1 == n else arr1[mid_of_arr1] 
            right_of_arr2 = 10 ** 7 if mid_of_arr2 == n else arr2[mid_of_arr2]
            
            if ((left_of_arr1 <= right_of_arr2) and
                (left_of_arr2 <= right_of_arr1)):
                return (max(left_of_arr1, left_of_arr2) + 
                        min(right_of_arr1, right_of_arr2))
            
            if left_of_arr1 > right_of_arr2:
                end = mid_of_arr1 - 1
            else:
                start = mid_of_arr1 + 1
        
        return -1