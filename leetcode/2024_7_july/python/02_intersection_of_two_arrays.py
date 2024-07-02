# CODE

import collections
from typing import List
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        count1 = collections.Counter(nums1)
        count2 = collections.Counter(nums2)
        return list((count1 & count2).elements())