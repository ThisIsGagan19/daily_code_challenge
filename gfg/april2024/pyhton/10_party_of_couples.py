# CODE

from functools import reduce
class Solution:
    def findSingle(self, n, arr):
        return reduce(lambda x, y: x ^ y, arr, 0)