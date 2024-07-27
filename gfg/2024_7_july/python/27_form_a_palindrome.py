# CODE

class Solution:
    def countMin(self, str):
        n = len(str)
        a, b = str, str[::-1]
        LCS = [[0] * (n + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if a[i - 1] == b[j - 1]:
                    LCS[i][j] = 1 + LCS[i - 1][j - 1]
                else:
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])
                    
        return n - LCS[n][n]