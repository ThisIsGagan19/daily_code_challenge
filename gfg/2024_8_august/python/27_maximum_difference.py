# CODE

from typing import List

class Solution:
    def findMaxDiff(self, arr: List[int]) -> int:
        n = len(arr)
        
        # Initialize arrays to store nearest smaller elements to the left and right
        left_smaller = [0] * n
        right_smaller = [0] * n
        
        # Stack to keep track of elements for left smaller elements
        stack = []
        
        # Calculate left smaller elements
        for i in range(n):
            while stack and stack[-1] >= arr[i]:
                stack.pop()
            if stack:
                left_smaller[i] = stack[-1]
            stack.append(arr[i])
        
        # Clear the stack for right smaller elements calculation
        stack.clear()
        
        # Calculate right smaller elements
        for i in range(n-1, -1, -1):
            while stack and stack[-1] >= arr[i]:
                stack.pop()
            if stack:
                right_smaller[i] = stack[-1]
            stack.append(arr[i])
        
        # Calculate the maximum absolute difference
        max_diff = 0
        for i in range(n):
            max_diff = max(max_diff, abs(left_smaller[i] - right_smaller[i]))
        
        return max_diff