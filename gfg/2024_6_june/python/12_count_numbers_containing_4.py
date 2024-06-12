# CODE

class Solution:
    def countNumberswith4(self, n : int) -> int:
        if n < 4:
            return 0
        cnt = 0
        for i in range(4, n + 1):
            s = str(i)
            if "4" in s:
                cnt += 1
        return cnt