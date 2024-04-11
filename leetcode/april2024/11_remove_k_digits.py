# CODE

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        res = []
        for c in num:
            # keeping only n - k smaller elements in stack i.e., res list
            while res and c < res[-1] and k:
                res.pop()
                k -= 1
            if res or c != '0':
                res.append(c)
        while k and res:
            res.pop()
            k -= 1
        return '0' if not res else ''.join(res)