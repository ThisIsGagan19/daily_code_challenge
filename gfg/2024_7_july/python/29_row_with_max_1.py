# CODE

class Solution:
    def rowWithMax1s(self, arr):
        m, n = len(arr), len(arr[0])
        ind, res, cnt = 0, 0, n - 1
        while ((ind != m) and (cnt >= 0)):
            if arr[ind][cnt]:
                res = ind
                cnt -= 1
            else:
                ind += 1
        return -1 if cnt == n - 1 else res