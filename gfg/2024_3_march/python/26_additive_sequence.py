# CODE

class Solution:
    def isAdditiveSequence(self, n: str) -> bool:
        if len(n) < 3:
            return 0
            
        def valid(s):
            return len(s) == 1 or s[0] != '0'
        
        for i in range(1, len(n) - 1):
            if not valid(n[:i]):
                continue
            for j in range(i + 1, len(n)):
                if not valid(n[i:j]):
                    continue
                num1 = int(n[:i])
                num2 = int(n[i:j])
                k = j
                while k < len(n):
                    num3 = num1 + num2
                    num3_str = str(num3)
                    if not n.startswith(num3_str, k):
                        break
                    k += len(num3_str)
                    num1, num2 = num2, num3
                    if k == len(n):
                        return 1
        return 0