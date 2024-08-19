# CODE

from heapq import heappush, heappop

class Solution:
    def kthSmallest(self, arr, k):
        n, i = len(arr), 0
        pq = []
        while i < k:
            heappush(pq, -arr[i])
            i += 1
        while i < n:
            if arr[i] < -pq[0]:
                heappop(pq)
                heappush(pq, -arr[i])
            i += 1
        return -heappop(pq)