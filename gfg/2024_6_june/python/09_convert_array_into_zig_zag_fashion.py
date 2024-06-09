# NOTE
# We don't need to sort the array, this problem can be solved in O(n).
# We just need to make sure that at an even position value is smaller than its 
# right and at an odd position value is greater than its right.

# CODE

from typing import List
class Solution:
    def zigZag(self, n : int, arr : List[int]) -> None:
        for i in range(n - 1):
            if i % 2 == 0:
                if arr[i] > arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
            else:
                if arr[i] < arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]