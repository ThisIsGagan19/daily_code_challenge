# CODE

from typing import List

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        freqmap = {}
        for s in arr:
            freqmap[s] = freqmap.get(s, 0) + 1
        for s in arr:
            if freqmap[s] == 1: k -= 1
            if k == 0: return s
        return ""