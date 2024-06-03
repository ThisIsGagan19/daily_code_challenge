# INTUITION
# Inorder of BST will always give the sorted array, 
# so we have to work on that sorted order and find paris which 
# aren't sorted.

# APPROACH
# 1. Store inorder of BST
# 2. Count inverted paris [Standard Question: Count Inversion Pair Using Merge Sort]

# TIME COMPLEXITY
# O(n * log(n))

# SPACE COMPLEXITY
# O(n)

# CODE

from typing import Optional
from collections import deque

class Solution:
    def __init__(self):
        self.res = 0

    # Merge Sort
    def merge(self, arr, st, mid, end):
        temp1 = arr[st:mid + 1]
        temp2 = arr[mid + 1:end + 1]
        i, j, k = 0, 0, st

        while i < len(temp1) and j < len(temp2) and k <= end:
            if temp1[i] <= temp2[j]:
                arr[k] = temp1[i]
                i += 1
                k += 1
            else:
                self.res += len(temp1) - i
                arr[k] = temp2[j]
                j += 1
                k += 1

        while i < len(temp1) and k <= end:
            arr[k] = temp1[i]
            i += 1
            k += 1

        while j < len(temp2) and k <= end:
            arr[k] = temp2[j]
            j += 1
            k += 1

    def mergeSort(self, arr, st, end):
        if st >= end:
            return
        mid = (st + end) // 2
        self.mergeSort(arr, st, mid)
        self.mergeSort(arr, mid + 1, end)
        self.merge(arr, st, mid, end)

    # Inorder
    def inorder(self, arr, root):
        if root is None:
            return
        self.inorder(arr, root.left)
        arr.append(root.data)
        self.inorder(arr, root.right)

    def pairsViolatingBST(self, n, root):
        arr = []
        self.inorder(arr, root)
        self.mergeSort(arr, 0, n - 1)
        return self.res