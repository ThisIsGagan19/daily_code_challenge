# CODE

class Solution:
    def checkValidString(self, s: str) -> bool:
        open = close = 0
        n = len(s) - 1
        for i in range(n + 1):
            if s[i] == '(' or s[i] == '*': open += 1
            else: open -= 1
            if s[n - i] == ')' or s[n - i] == '*': close += 1
            else: close -= 1
            if open < 0 or close < 0: return False
        return True