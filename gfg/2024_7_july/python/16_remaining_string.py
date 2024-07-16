# CODE

class Solution:
    def printString(self, s, ch, count):
        idx = 0
        for _ in range(count):
            idx = s.find(ch, idx)
            if idx == -1:
                return ""
            idx += 1
        return s[idx:]