# CODE

from typing import List
from collections import heapq

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.min_heap = []
        self.limit = k
        for val in nums:
            self.add(val)

    def add(self, val: int) -> int:
        if len(self.min_heap) < self.limit or self.min_heap[0] < val:
            heapq.heappush(self.min_heap, val)
            if len(self.min_heap) > self.limit:
                heapq.heappop(self.min_heap)
        return self.min_heap[0]