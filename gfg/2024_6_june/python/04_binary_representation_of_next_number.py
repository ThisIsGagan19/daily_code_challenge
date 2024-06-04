# CODE

class Solution:
    def binaryNextNumber(self, s):
        s = s.lstrip('0') or '0'
        n = len(s)
        res = list(s)
        
        for i in range(n - 1, -1, -1):
            if res[i] == '0':
                res[i] = '1'
                for j in range(i + 1, n):
                    res[j] = '0'
                return ''.join(res)
        
        return '1' + '0' * n